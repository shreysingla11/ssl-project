"""!
@file views.py
@brief File for defining functions controllling batch API endpoints

Classes and functions are defined here which return responses to different HTTP requests at different endpoints
"""
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
import json
from Parser.core import result
# Create your views here.

class BatchViewSet(viewsets.ModelViewSet):
    """!
    @brief This is the class controlling the authenticated /rp/batch endpoint

    This viewset supports GET,POST,DELETE requests to perform CRUD operations on batches\n  
    GET /rp/batch  Returns list of current user's batches\n 
    GET /rp/batch/:id Returns detail of batch with ID = id\n 
    POST /rp/batch/ Creates a new batch for the current user\n 
    DELETE /rp/batch/":id Deletes the batch with ID=id if it belongs to the current user
    """
    serializer_class = BatchSerializer
    lookup_field = 'id'
    permission_classes = (IsAuthenticated,)

    def get_queryset(self):
        """!
        Filters the batches to only show the authenticated users batches
        """
        return  Batch.objects.filter(user=self.request.user).order_by('-created_at')
    
    def create(self, request, *args, **kwargs):
        """!
        @brief This is the function for handling the POST request to create a batch

        @param self Default object parameter
        @param request Request object with post data fields - 'name','description','language','inline_comment','multi_begin','multi_end'

        @return JSON response with created batch's data or error response in case of failure
        """
        if request.user.is_authenticated:
            request.data._mutable = True
            print(request.data,request.data._mutable)
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
    """!
    @brief This is the class controlling the authenticated /rp/download endpoint

    This viewset supports GET request to download a particular batch's result\n  
    GET /rp/download/:uid Returns file response with the required batch's result
    """
    permission_classes = (IsAuthenticated,)

    def get(self,request,id):
        """!
        @brief This is the function for handling the GET request

        @param self Default object parameter
        @param request Request object
        @param id The batch ID

        @return File response with the request batch's result
        """
        batch = Batch.objects.filter(user=request.user,id=id).exists()
        if batch:
            batch = Batch.objects.get(id=id)
            print(batch.result,'\n\n\n')
            if 'threshold' in request.query_params:
                threshold = float(request.query_params.get('threshold'))
            else:
                threshold = 0.5
            try:
                res = result(json.loads(batch.result),threshold)
            except:
                res = "Invalid files"
            f = io.BytesIO(bytes(res,encoding='utf-8'))
            return FileResponse(f,filename='result.txt',as_attachment=True)
        else:
            return Response({"error":"Unknown batch"},status=status.HTTP_404_NOT_FOUND)

    