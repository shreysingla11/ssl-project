# RedPlag Terminal Client
This is a basic terminal client for the RedPlag API developed using NodeJS. This client uses token authentication to authenticate the user and interacts with the RedPlag Django server to handle requests.

## Installation
Clone the project repository and cd into into it. Then execute the following commands
```
$ cd terminal-client
$ npm i
```
## Usage
```
$ node main.js
$ help
```
This will open an interactive console where you can execute commands
## Commands
1. ### Login
    ```
    $ login
    ```
    Login using your username, password and organisation passcode. This creates an authorization token which you include in subsequent requests.

2. ### Create
    ```
    $ create
    ```
    Create a new batch of code files. The user needs to be logged in for this. You need to have all files in a single folder.

3. ### Batch listing, retreiving and deletion
    ```
    $ batch [-d,--delete] [uid]
    ```
    Prints the list of batches or download result of batch with ID = uid. 
    <br>FLAG -d,--delete  Deletes the batch with specified uid

4. ### Logout

    ```
    $ logout
    ```
    Logout from Red Plag server and dete the generated token

5. ### Exit
    ```
    $ exit
    ```
    Exits the application
