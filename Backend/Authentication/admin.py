"""!
@file admin.py
@brief Settings file for Django admin page

The models are registers on the admin site in this file
"""
from django.contrib import admin
from django.contrib.auth.admin import UserAdmin
from Authentication.models import MyUser,Organisation

# Register your models here.

admin.site.register(MyUser)
admin.site.register(Organisation)