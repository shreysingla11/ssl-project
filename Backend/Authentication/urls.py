from django.urls import path,include
from rest_framework.routers import DefaultRouter
from Authentication import views
from Authentication.views import LoginView,LogoutView,ProfileView,RegisterView,ChangePasswordView
from Authentication.token_auth import CustomAuthToken,TokenLogoutView
router = DefaultRouter()
#router.register(r'users', views.UserViewSet,basename='users')
router.register(r'orgs',views.OrganisationViewSet,basename='organisation')

urlpatterns = [
    path('',include(router.urls)),
    path('register/', RegisterView.as_view()),
    path('login/', LoginView.as_view()),
    path('profile/',ProfileView.as_view()),
    path('logout/',LogoutView.as_view()),
    path('changepassword/',ChangePasswordView.as_view()),
    path('token/',CustomAuthToken.as_view()),
    path('token-logout/',TokenLogoutView.as_view())
]