from django.db import models
from django.contrib.auth.models import AbstractUser
from django.utils.crypto import get_random_string
from django.db.models.signals import pre_save
from django.dispatch import receiver
from django.core.mail import send_mail
from django.contrib.auth.hashers import make_password
# Create your models here.
class Organisation(models.Model):
    name = models.CharField(max_length=50)
    org_pass = models.CharField(max_length=20,unique=True)

    def __str__(self):
        return self.name

class MyUser(AbstractUser):
    org = models.ForeignKey(Organisation,on_delete=models.CASCADE,null=True)
    pass


# @receiver(pre_save,sender=Organisation)
# def hashOrgPass(sender,instance,**kwargs):
#     instance.org_pass = make_password(instance.org_pass)

