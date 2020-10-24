from django.db import models
from django.contrib.auth.models import AbstractUser
from django.utils.crypto import get_random_string
from django.db.models.signals import post_save
from django.dispatch import receiver
from django.core.mail import send_mail
# Create your models here.

class MyUser(AbstractUser):
    org_pass = models.CharField(max_length=20,default=get_random_string(length=20))
    pass


# @receiver(post_save,sender=MyUser)
# def sendOrgPass(sender,instance,**kwargs):
#     send_mail(
#         'Your organisation passcode for RedPlag',
#         f"Your passcode is {instance.org_pass}",
#         None,
#         [instance.email],
#         fail_silently=False,
#         )

