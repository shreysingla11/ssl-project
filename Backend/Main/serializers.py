from rest_framework import serializers
from Main.models import Batch,CodeFile

class BatchSerializer(serializers.HyperlinkedModelSerializer):

    class Meta:
        model = Batch
        fields = ['id','name','description','created_at','result']

    def create(self, validated_data):
        print(validated_data)
        instance = Batch(user=self.context['user'],**validated_data)
        instance.save()
        print(instance)
        if self.context['files'] is not None:
            for f in self.context['files']:
                print('Yes')
                obj = CodeFile(batch=instance,file=f)
                obj.save()
        instance.computeResult()
        return instance

class CodeFileSerializer(serializers.HyperlinkedModelSerializer):

    batch = BatchSerializer(required=True)

    class Meta:
        model = CodeFile
        fields = '__all__' 

# class BatchFormSerializer(serializers.Serializer):
#     name = serializers.CharField(required=True)
#     description = serializers.CharField()
#     files = serializers.ListField(child=serializers.FileField(allow_null=False),required=True)
    
#     def create(self, validated_data):
#         print(validated_data)
#         files = validated_data.pop('files', None)
#         print(validated_data)
#         instance = Batch(user=self.context['request'].user,**validated_data)
#         instance.save()
#         print(instance)
#         if files is not None:
#             for f in files:
#                 print('Yes')
#                 obj = CodeFile(batch=instance,file=f)
#                 obj.save()
#         return instance

