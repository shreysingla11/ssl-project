# Backend
This folder contains the implementation for the backend API for the RedPlag webapp. The framework used for this implementation is Django REST framework on top of the Django framework. It provides API for registration and authentication of users as well as updation of passwords. It also provides an API to perform CRUD operations on batches of sources code files.

## API
The API consists of two major parts -:

### Authentication API
This API uses session authentication to authenticate users
The routes offered by the API are :

```
# The base path is /auth
router = DefaultRouter()
router.register(r'users', views.UserViewSet)

urlpatterns = [
    path('',include(router.urls)),
    path('register/', RegisterView.as_view()),
    path('login/', LoginView.as_view()),
    path('profile/',ProfileView.as_view()),
    path('logout/',LogoutView.as_view()),
    path('changepassword/',ChangePasswordView.as_view()),
]
```

| Route | Http methods allowed|
|---|---|
| register  | POST  |
|  login |  POST |
| profile  |  GET |
|  logout |  GET |
|  changepassword |  UPDATE |
| users  |  GET, POST, DELETE, UPDATE |

- The ***register*** route provides functionality for user registration
- The ***login*** and ***logout*** route provides functionality for user authentication
- The ***profile*** route returns the current users general information
- The ***changepassword*** routes provides functionality to chage user password

**Note**- This API also provides unauthenticated route ***/auth/users/*** which provides details of all registered users. This route is only for development and must be removed during production

### Batch API
This API handles operations on batches of source code files submitted for evaluation
The routes offered by the API are :

```
# The base path is /rp
router = DefaultRouter()
router.register(r'batch', BatchViewSet,basename='batch')
router.register(r'src',CodeFileViewSet,basename='codefile')

urlpatterns = [
    path('',include(router.urls)),
    path('download/<uuid:id>',DownloadResult.as_view()),
]
```

| Route | Http methods allowed|
|---|---|
| batch  | GET, POST, UPDATE, DELETE  |
|  src | GET, POST, UPDATE, DELETE |
| download  |  GET |

- The ***batch*** route provides functionality for CRUD operations on the Batch model
- The ***download*** route returns the results file corresponding to a given batch(using batch_id)
- The ***src*** route provides functonality to view the source code files uploaded

**Note**- This API also an unauthenticated route ***/rp/src/*** which provides details of all code files submitted. This route is only for development and must be removed during production

## Usage

Clone the repository, navigate into the project diectory and run the following commands

```
$ cd Backend
$ pip install -r requirements.txt
$ python3 manage.py makemigrations
$ python3 manage.py migrate
$ python3 manage.py runserver
```
