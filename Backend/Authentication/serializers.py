from rest_framework import serializers
from Authentication.models import MyUser

class MyUserSerializer(serializers.HyperlinkedModelSerializer):

    class Meta:
        model = MyUser
        fields = ['username','email','first_name','last_name']


class RegisterSerializer(serializers.HyperlinkedModelSerializer):

    class Meta:
        model = MyUser
        fields = ['username','email','first_name','last_name','password']
    
    def create(self, validated_data):
        password = validated_data.pop('password', None)
        instance = self.Meta.model(**validated_data)
        print("Yes")
        if password is not None:
            instance.set_password(password)
        instance.save()
        return instance

class LoginSerializer(serializers.Serializer):
    username = serializers.CharField(required=True)
    password = serializers.CharField(required=True)
    org_pass = serializers.CharField(required=True)

class SampleSerializer(serializers.HyperlinkedModelSerializer):

    class Meta:
        model = MyUser
        fields = ['username','password','org_pass']

class ChangePasswordSerializer(serializers.Serializer):
    model = MyUser

    """
    Serializer for password change endpoint.
    """
    old_password = serializers.CharField(required=True)
    new_password = serializers.CharField(required=True)