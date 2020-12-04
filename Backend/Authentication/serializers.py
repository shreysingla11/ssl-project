from rest_framework import serializers
from Authentication.models import MyUser,Organisation

class OrganisationSerializer(serializers.HyperlinkedModelSerializer):

    class Meta:
        model = Organisation
        fields = '__all__'

class MyUserSerializer(serializers.HyperlinkedModelSerializer):
    org = OrganisationSerializer()
    class Meta:
        model = MyUser
        fields = ['username','email','first_name','last_name','org']


class RegisterSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = MyUser
        fields = ['username','email','first_name','last_name','password']
    
    def create(self, validated_data):
        password = validated_data.pop('password', None)
        print(validated_data)
        instance = self.Meta.model(**validated_data)
        instance.org = self.context["org"]
        if password is not None:
            instance.set_password(password)
        instance.save()
        return instance

class LoginSerializer(serializers.Serializer):
    username = serializers.CharField(required=True)
    password = serializers.CharField(required=True)
    org_pass = serializers.CharField(required=True)

class SampleSerializer(serializers.HyperlinkedModelSerializer):
    org = OrganisationSerializer()
    class Meta:
        model = MyUser
        fields = ['username','password','org']

class ChangePasswordSerializer(serializers.Serializer):
    model = MyUser

    """
    Serializer for password change endpoint.
    """
    old_password = serializers.CharField(required=True)
    new_password = serializers.CharField(required=True)