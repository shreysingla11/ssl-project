Backend                         {#backend}
============
This folder contains the implementation for the backend API for the RedPlag webapp. The framework used for this implementation is Django REST framework on top of the Django framework. It provides API for registration and authentication of users as well as updation of passwords. It also provides an API to perform CRUD operations on batches of sources code files.

## API
The API consists of two major parts -:

### Authentication API
This API provides endpoints for session as well token authentication to authenticate users
The routes offered by the API are :

```
# The base path is /auth
router = DefaultRouter()
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
```

- Register

    | Route | Method | Description |
    |---|---|---|
    | /register  | POST | Registraion of new users |

    <br>This is the request 

    | Name | Datatype | Description |
    |---|---|---|
    | username  | string | Username for loggin in (unique) |
    | first_name  | string | First name of user |
    | last_name  | string | Last name of user |
    | email  | string | User's email address |
    | password  | string | Login Password |
    | org_pass  | string | Passcode of a registered organisation  |

    <br>This is the request body in JSON

- Login

    | Route | Method | Description |
    |---|---|---|
    | /login  | POST | Login into your account |

    <br>This is the request 

    | Name | Datatype | Description |
    |---|---|---|
    | username  | string | Username |
    | password  | string | Login Password |
    | org_pass  | string | Passcode of user's organisation  |

    <br>This is the request body in JSON

- Logout

    | Route | Method | Description |
    |---|---|---|
    | /logout  | GET | Logout your session |

    <br>This is the request 
    <br>This request does not have search parameters but must be sent with session headers

- Profile

    | Route | Method | Description |
    |---|---|---|
    | /profile  | POST | Return's the current user's data|

    <br>This is the request 
    <br>This request does not have search parameters but must be sent with session headers. 
    <br>Return' user data in JSON format

- Change password

    | Route | Method | Description |
    |---|---|---|
    | /changepassword  | POST | Change the current user's password |

    <br>This is the request 

    | Name | Datatype | Description |
    |---|---|---|
    | old_password  | string | Current Password |
    | new_password  | string | New password |

    <br>This is the request body in JSON. This nust also be sent with user session headers

- Token

    | Route | Method | Description |
    |---|---|---|
    | /token  | POST | Get the user's token |

    <br>This is the request 

    | Name | Datatype | Description |
    |---|---|---|
    | username  | string | Username |
    | password  | string | Login Password |
    | org_pass  | string | Passcode of user's organisation  |

    <br>This is the request body in JSON.. Return a token for authentication on other views

- LogoutToken

    | Route | Method | Description |
    |---|---|---|
    | /token-logout  | POST | Delete the user's token if present |

    <br>This is the request 
    <br>This request does not have any params. Returns a JSON response with success message


### Batch API
This API handles operations on batches of source code files submitted for evaluation
The routes offered by the API are :

```
# The base path is /rp
router = DefaultRouter()
router.register(r'batch', BatchViewSet,basename='batch')

urlpatterns = [
    path('',include(router.urls)),
    path('download/<uuid:id>',DownloadResult.as_view()),
]
```
- List Batch

    | Route | Method | Description |
    |---|---|---|
    | /batch/:uid(optional)  | GET | Returns a list of users batches or a particular batch with ID=uid |

    <br>This is the request 
    <br>It returns JSON response with information about the current user's batches

- Create Batch

    | Route | Method | Description |
    |---|---|---|
    | /batch  | POST | Create a new batch for the current user |

    <br>This is the request 

    | Name | Datatype | Description |
    |---|---|---|
    | name  | string | Name of the batch |
    | description  | string | Short description for the batch |
    | language  | ["C++","Python","Other"] | Language used in code files |
    | inline_comment  | string | Character(s) to start an inline comment |
    | multi_begin | string | Character(s) to start a multiline comment |
    | multi_end  | string | Character(s) to end a multiline comment  |
    | files | File[] | List of files to be uploaded  |

    <br>This is the request body in ***multipart/form-data***

- Delete Batch

    | Route | Method | Description |
    |---|---|---|
    | /batch/:uid  | DELETE | Deletes the batch with ID=uid |

    <br>This is the request 
    <br>Can only destroy the request's user's batches.Returns a success or failure message accordingly.

- Download Result

    | Route | Method | Description |
    |---|---|---|
    | /download/:uid  | GET | Returns a file containing results of plagiarism check on the specified batch |

    <br>This is the request 
    <br>This must also be sent with session or token headers. It return a File response.

## Usage

Clone the repository, navigate into the project diectory and run the following commands

```
$ cd Backend
$ pip install -r requirements.txt
$ python3 manage.py makemigrations
$ python3 manage.py migrate
$ python3 manage.py runserver
```
