# Frontend
This folder contains the implementation for the frontend of the app using angular framework. It provides functionality for the registration and login for the app as well as the dashboard component. 

## Components:
It consists of four major components:
### Register Page
The user is asked to register to use the services of the app. If the credentials provided are valid, user is redirected to the login page and user information is added to the database. A random passcode is sent to user via email (to be implemented).

### Login Page
The user is asked to sign in using his/her credentials and the organisational passcode provided. If the user is registered, (s)he is redirected to the dashboard page.

### Dashboard Component
The user can view previous results of batches of code files uploaded before as well as make a new batch. (s)he can upload the files to the newly created batch or download the results from the previous batches.

### Batch Compenent
It is a child component of the dashboard component. It shows the result obtained by running the plagiarism detection algorithm on the bunch of code files. The result can be downloaded and the batch can be deleted as well from the database using their respective buttons.

## Usage
Clone the repository, navigate into the project directory and run the following commands

```
$ cd Frontend
$ npm install
$ ng serve --open
```

## ToDo
Make a profile page of a user which shows all the information of the user. It also has a functionality to change the password and update the database

