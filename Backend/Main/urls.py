from django.urls import path,include
from rest_framework.routers import DefaultRouter
from Main.views import BatchViewSet,CodeFileViewSet,DownloadResult

router = DefaultRouter()
router.register(r'batch', BatchViewSet,basename='batch')
router.register(r'src',CodeFileViewSet,basename='codefile')

urlpatterns = [
    path('',include(router.urls)),
    path('download/<uuid:id>',DownloadResult.as_view()),
]