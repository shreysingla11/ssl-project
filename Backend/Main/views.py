from django.shortcuts import render
from rest_framework import viewsets
from Main.serializers import BatchSerializer,CodeFileSerializer
from Main.models import CodeFile,Batch
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from rest_framework.generics import UpdateAPIView,RetrieveAPIView
# Create your views here.
from django.http import FileResponse
from rest_framework.permissions import IsAuthenticated
from django.contrib.auth import login, authenticate,logout
import io
# Create your views here.

class BatchViewSet(viewsets.ModelViewSet):

    serializer_class = BatchSerializer
    lookup_field = 'id'
    permission_classes = (IsAuthenticated,)

    def get_queryset(self):
        return  Batch.objects.filter(user=self.request.user).order_by('-created_at')
    
    def create(self, request, *args, **kwargs):
        if request.user.is_authenticated:
            print(request.data)
            files = request.data.pop('files',None)
            serializer = self.get_serializer(data=request.data,context={'user':request.user,'files':files})
            serializer.is_valid(raise_exception=True)
            self.perform_create(serializer)
            #headers = self.get_success_headers(serializer.data)
            print("Yessss")
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response({"error":"Unauthorized access"},status=status.HTTP_404_NOT_FOUND)


class CodeFileViewSet(viewsets.ModelViewSet):
    
    serializer_class = CodeFileSerializer
    permission_classes = (IsAuthenticated,)
    
    def get_queryset(self):
        btchs = Batch.objects.filter(user = self.request.user)
        qs = CodeFile.objects.none()
        for bt in btchs:
            qs = qs.union(CodeFile.objects.filter(batch=bt))
        return qs

class DownloadResult(APIView):

    permission_classes = (IsAuthenticated,)

    def get(self,request,id):
        batch = Batch.objects.get(id=id)
        if batch is not None:
            print(batch.result,'\n\n\n')
            f = io.BytesIO(bytes(batch.result,encoding='utf-8'))
            return FileResponse(f,filename='result.txt',as_attachment=True)
        else:
            return Response({"error":"Unknown batch"},status=status.HTTP_404_NOT_FOUND)

    