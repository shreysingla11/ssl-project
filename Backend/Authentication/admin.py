from django.contrib import admin
from django.contrib.auth.admin import UserAdmin
from Authentication.models import MyUser,Organisation

# Register your models here.

admin.site.register(MyUser)
admin.site.register(Organisation)