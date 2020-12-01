from django.shortcuts import render
from rest_framework import viewsets
from Authentication.serializers import MyUserSerializer,ChangePasswordSerializer,RegisterSerializer,LoginSerializer,SampleSerializer
from Authentication.models import MyUser
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from rest_framework.generics import UpdateAPIView,RetrieveAPIView
# Create your views here.
from rest_framework.permissions import IsAuthenticated
from django.contrib.auth import login, authenticate,logout
from rest_framework.parsers import MultiPartParser,FormParser

class UserViewSet(viewsets.ModelViewSet):

    queryset = MyUser.objects.all()
    serializer_class = SampleSerializer

class RegisterView(APIView):

    def post(self,request):
        user_ser = RegisterSerializer(data=request.data)
        if user_ser.is_valid():
            user_ser.save()
            return Response(user_ser.data,status=status.HTTP_201_CREATED)
        return Response(user_ser.errors,status = status.HTTP_400_BAD_REQUEST)

class LoginView(APIView):

    def post(self,request):
        if not request.user.is_authenticated:
            print(request.data)
            creds = LoginSerializer(data=request.data)
            if creds.is_valid():
                print(creds.data.get('username'),creds.data.get('password'))
                user = authenticate(username=creds.data.get('username'), password=creds.data.get('password'))
                print(user.org_pass)
                if user is not None and creds.data.get('org_pass') == user.org_pass:
                    login(request,user)
                    return Response({"username":user.username},status=status.HTTP_202_ACCEPTED)
                else:
                    return Response({"error":"Wrong credentials"},status=status.HTTP_400_BAD_REQUEST)
            else:
                return Response(creds.errors,status=status.HTTP_400_BAD_REQUEST)
        else:
            return Response({"error":"Already logged in"},status=status.HTTP_400_BAD_REQUEST)

class ProfileView(RetrieveAPIView):

    serializer_class = MyUserSerializer
    model = MyUser

    def get(self,request):
        print(request.user)
        if request.user.is_authenticated:
            return Response(MyUserSerializer(request.user).data,status=status.HTTP_200_OK)
        else:
            return Response({"error":"User not logged in"},status=status.HTTP_404_NOT_FOUND)

class LogoutView(APIView):

    def get(self,request):
        print(request.user)
        logout(request)
        print(request.user)
        return Response({"message":"Logged out successfully"})

class ChangePasswordView(UpdateAPIView):
        """
        An endpoint for changing password.
        """
        serializer_class = ChangePasswordSerializer
        model = MyUser

        def update(self, request):
            serializer = self.get_serializer(data=request.data)

            if request.user.is_authenticated:
                if serializer.is_valid():
                    # Check old password
                    if not request.user.check_password(serializer.data.get("old_password")):
                        return Response({"error": "Wrong old password."}, status=status.HTTP_400_BAD_REQUEST)
                    # set_password also hashes the password that the user will get
                    request.user.set_password(serializer.data.get("new_password"))
                    request.user.save()
                    response = {
                        'message': 'Password updated successfully',
                    }

                    return Response(response)
                    
                return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
            else:
                return Response({"error":"You are not logged in"},status=status.HTTP_401_UNAUTHORIZED)