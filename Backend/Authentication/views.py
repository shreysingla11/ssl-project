"""!
@file views.py
@brief File for defining functions controllling API endpoints

Classes and functions are defined here which return responses to different HTTP requests at different endpoints
"""
from django.shortcuts import render
from rest_framework import viewsets
from Authentication.serializers import MyUserSerializer,ChangePasswordSerializer,RegisterSerializer,LoginSerializer,SampleSerializer,OrganisationSerializer
from Authentication.models import MyUser,Organisation
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from rest_framework.generics import UpdateAPIView,RetrieveAPIView
# Create your views here.
from rest_framework.permissions import IsAuthenticated
from django.contrib.auth import login, authenticate,logout
from rest_framework.parsers import MultiPartParser,FormParser
from Main.models import Batch,CodeFile

class UserViewSet(viewsets.ModelViewSet):
    
    permission_classes = (IsAuthenticated,)
    serializer_class = SampleSerializer

    def get_queryset(self):
        return MyUser.objects.filter(username=self.request.user.username)

class OrganisationViewSet(viewsets.ReadOnlyModelViewSet):
    """!
    @brief This is the class controlling the /auth/orgs endpoint

    This viewset supports GET requests to create objects of the Orgaisation model\n  
    GET /orgs  Returns the current user's organisation
    """

    serializer_class = OrganisationSerializer
    permission_classes = (IsAuthenticated,)

    def get_queryset(self):
        """!
        Filters the organisations to only show the authenticated users organisation
        """
        return Organisation.objects.filter(org_pass=self.request.user.org.org_pass)


class RegisterView(APIView):
    """!
    @brief This is the class controlling the /auth/register endpoint

    This viewset supports POST request to create a new user\n  
    POST /auth/register  Creates a new user
    """
    def post(self,request):
        """!
        @brief This is the function for handling the POST request

        @param self Default object parameter
        @param request Request object with post data fields - 'username','first_name','last_name','email','password','org_pass'

        @return JSON response with created user's data or errors
        """
        org_pass = request.data.pop('org_pass','')
        if Organisation.objects.filter(org_pass=org_pass).exists():
            user_ser = RegisterSerializer(data=request.data,context={'org':Organisation.objects.get(org_pass=org_pass)})
            if user_ser.is_valid():
                user_ser.save()
                return Response(user_ser.data,status=status.HTTP_201_CREATED)
            return Response(user_ser.errors,status = status.HTTP_400_BAD_REQUEST)
        return Response({"msg":"No organization with this passcode"})

class LoginView(APIView):
    """!
    @brief This is the class controlling the /auth/login endpoint

    This viewset supports POST request to login a user\n  
    POST /auth/login  Login a user
    """
    def post(self,request):
        """!
        @brief This is the function for handling the POST request

        @param self Default object parameter
        @param request Request object with post data fields - 'username','password','org_pass'

        @return JSON response with user's username or error response in case of failure
        """
        if not request.user.is_authenticated:
            print(request.data)
            creds = LoginSerializer(data=request.data)
            if creds.is_valid():
                print(creds.data.get('username'),creds.data.get('password'))
                user = authenticate(username=creds.data.get('username'), password=creds.data.get('password'))
                #print(user.org.org_pass)
                if user is not None and creds.data.get('org_pass') == user.org.org_pass:
                    login(request,user)
                    return Response({"username":user.username},status=status.HTTP_202_ACCEPTED)
                else:
                    return Response({"error":"Wrong credentials"},status=status.HTTP_400_BAD_REQUEST)
            else:
                return Response(creds.errors,status=status.HTTP_400_BAD_REQUEST)
        else:
            return Response({"error":"Already logged in"},status=status.HTTP_400_BAD_REQUEST)

class ProfileView(RetrieveAPIView):
    """!
    @brief This is the class controlling the /auth/profile endpoint

    This viewset supports GET request to obtain current user's information\n  
    GET /auth/profile Get current user's info
    """
    serializer_class = MyUserSerializer
    model = MyUser

    def get(self,request):
        """!
        @brief This is the function for handling the GET request

        @param self Default object parameter
        @param request Request object

        @return JSON response with current user's data or error response in case of failure
        """
        print(request.user)
        if request.user.is_authenticated:
            data = MyUserSerializer(request.user,context={'request':request}).data
            data["bcount"] = Batch.objects.filter(user=request.user).count()
            data["ccount"] = 0
            for b in Batch.objects.filter(user=request.user):
                data["ccount"] += CodeFile.objects.filter(batch=b).count()
            return Response(data,status=status.HTTP_200_OK)
        else:
            return Response({"error":"User not logged in"},status=status.HTTP_404_NOT_FOUND)

class LogoutView(APIView):
    """!
    @brief This is the class controlling the /auth/logout endpoint

    This viewset supports GET request to log out the current user's session\n  
    GET /auth/logout
    """
    def get(self,request):
        """!
        @brief This is the function for handling the GET request

        @param self Default object parameter
        @param request Request object

        @return JSON response on successful logging out of the current user
        """
        print(request.user)
        logout(request)
        print(request.user)
        return Response({"message":"Logged out successfully"})

class ChangePasswordView(UpdateAPIView):
        """!
        @brief This is the class controlling the /auth/changepassword endpoint

        This viewset supports PUT request to change the current user's password\n  
        PUT /auth/changepassword/
        """
        serializer_class = ChangePasswordSerializer
        model = MyUser

        def update(self, request):
            """!
            @brief This is the function for handling the PUT request

            @param self Default object parameter
            @param request Request object with PUT JSON data with fields 'old_password','new_password'

            @return JSON response on successful password change or error message in case of failure
            """
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