from django.db import models
import uuid
from Authentication.models import MyUser

# Create your models here.
class Batch(models.Model):
    id = models.UUIDField(primary_key=True, default=uuid.uuid4, editable=False)
    user = models.ForeignKey(MyUser,on_delete=models.CASCADE)
    name = models.CharField(max_length=150)
    description = models.TextField()
    created_at = models.DateTimeField(auto_now=True,editable=False)
    result = models.FileField(default='sample/result.txt')

    def __str__(self):
        return str(self.id)


def get_file_name(instance,filename):
    return "/".join(['src',str(instance.batch),filename])

class CodeFile(models.Model):
    batch = models.ForeignKey(Batch,on_delete=models.CASCADE)
    file = models.FileField(upload_to=get_file_name)