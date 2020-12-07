from rest_framework.authtoken.views import ObtainAuthToken,APIView
from rest_framework.authtoken.models import Token
from rest_framework.response import Response
from rest_framework import status
from rest_framework import permissions

class CustomAuthToken(ObtainAuthToken):

    def post(self, request, *args, **kwargs):
        org_pass = request.data.pop('org_pass')
        serializer = self.serializer_class(data=request.data,
                                       context={'request': request})
        if serializer.is_valid(raise_exception=True):
            user = serializer.validated_data['user']
            if org_pass == user.org.org_pass:
                token, created = Token.objects.get_or_create(user=user)
                return Response({
                    'token': token.key
                })
        return Response({'error':'Incorrect authentication credentials'},status=status.HTTP_401_UNAUTHORIZED)

class TokenLogoutView(APIView):
    permission_classes = (permissions.IsAuthenticated,)

    def get(self,request):
        try:
            print(request.user)
            request.user.auth_token.delete()
        except:
            pass

        return Response({"success": "Successfully logged out."})