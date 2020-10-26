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

# Create your views here.

class BatchViewSet(viewsets.ModelViewSet):

    serializer_class = BatchSerializer
    permission_classes = (IsAuthenticated,)
    lookup_field = 'id'

    def get_queryset(self):
        return  Batch.objects.filter(user=self.request.user)
    
    def create(self, request, *args, **kwargs):
        files = request.data.pop('files',None)
        serializer = self.get_serializer(data=request.data,context={'user':request.user,'files':files})
        serializer.is_valid(raise_exception=True)
        self.perform_create(serializer)
        #headers = self.get_success_headers(serializer.data)
        print("Yessss")
        return Response(serializer.data, status=status.HTTP_201_CREATED)


class CodeFileViewSet(viewsets.ModelViewSet):
    
    serializer_class = CodeFileSerializer
    queryset = CodeFile.objects.all()

class DownloadResult(APIView):

    permission_classes = (IsAuthenticated,)

    def get(self,request,id):
        batch = Batch.objects.get(id=id)
        if batch is not None:
            print(batch.result.path,'\n\n\n\n\n\n\n')
            f = open(batch.result.path,'rb')
            return FileResponse(f,filename='result.txt',as_attachment=True)
        else:
            return Response({"error":"Unknown batch"},status=status.HTTP_404_NOT_FOUND)

    