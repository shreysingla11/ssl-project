# Frontend
This folder contains the implementation for the frontend of the app using angular framework. It provides functionality for the registration and login for the app as well as the dashboard component. It also contains batch component representing the result of each batch of file and a profile page.

## Components:
It consists of five major components:
### Register Page
The user is asked to register to use the services of the app. If the credentials provided are valid, user is redirected to the login page and user information is added to the database. In addition to the basic information, user is also required to provide an organisation passcode indicating the current organisation it is a part of.

### Login Page
The user is asked to sign in using his/her credentials and the organisational passcode. If the user is registered, (s)he is redirected to the dashboard page.

### Dashboard Component
The user can view previous results of batches of code files uploaded before as well as make a new batch. (s)he can also navigate to the profile page.

### Batch Compenent
It is a child component of the dashboard component. It shows the result obtained by running the plagiarism detection algorithm on the bunch of code files. The user is given control over the number of suspicious files by a slider representing a threshold above which the files are considered to be plagiarised. The corresponding files are shown as a scatterplot with each point representing a pair of code files.

### Profile Component
It shows the information of the registered user along with the number of batches the user has created and the number of files on which the checker has run. It also provides a facility for the user to change the password if required. The database is updated accordingly.

## Usage
Clone the repository, navigate into the project directory and run the following commands

```
$ cd Frontend
$ npm installThe batch can be deleteThe batch can be deleted from the database using the button provided and the rd from the database using the button provided and the r
$ ng serve --open
```
