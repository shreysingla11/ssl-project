from django.db import models
import uuid
from Authentication.models import MyUser
from django.db.models.signals import post_delete,pre_save
from django.dispatch import receiver
import shutil
import os
import json
from Parser.core import logic

# Create your models here.
class Batch(models.Model):
    id = models.UUIDField(primary_key=True, default=uuid.uuid4, editable=False)
    user = models.ForeignKey(MyUser,on_delete=models.CASCADE)
    name = models.CharField(max_length=150)
    description = models.TextField()
    language = models.CharField(max_length=40)
    inline_comment = models.CharField(max_length=5,default='')
    multi_begin = models.CharField(max_length=5,default='')
    multi_end = models.CharField(max_length=5,default='')
    created_at = models.DateTimeField(auto_now=True,editable=False)
    result = models.TextField(default="This is a sample results file")

    def __str__(self):
        return str(self.id)
    
    def computeResult(self):
        print("In compute result2")
        try:
            result = logic(os.getcwd(),str(self.id),self.language,self.inline_comment,self.multi_begin,self.multi_end)
            self.result = json.dumps(result)
        except:
            self.result = json.dumps({"data":[],"files":[]})
        self.save()


def get_file_name(instance,filename):
    return "/".join(['src',str(instance.batch),filename])

class CodeFile(models.Model):
    batch = models.ForeignKey(Batch,on_delete=models.CASCADE)
    file = models.FileField(upload_to=get_file_name)

@receiver(post_delete, sender=Batch)
def deleteBatchDir(sender, instance, **kwargs):

    directory = os.path.join(os.getcwd(),'src',str(instance.id))
    print(directory)
    try:
        if os.path.isdir(directory):
            print("Yes")
            shutil.rmtree(directory)
    except:
        print("Error")

# @receiver(pre_save, sender=Batch)
# def computeResult(sender, instance, **kwargs):
#     print("In compute result")
#     result = logic(os.getcwd(),str(instance.id))
#     instance.result = json.dumps(result)