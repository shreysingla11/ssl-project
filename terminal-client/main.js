const axios = require('axios');
const chalk = require('chalk');
const vorpal = require('vorpal')();
const Configstore = require('configstore');
const package = require('./package.json');
const Config = new Configstore(package.name);
const inquirer = require('inquirer');
const figlet = require('figlet')
const ora = require('ora')
const fs = require('fs')

const login = require('./login');
const Create = require('./create');
const utils = require('./utils')
const batch = require('./batch');
const create = require('./create');
const logout = require('./logout')

const API_URL = "http://localhost:8000/";

// Banner
console.log(
  chalk.red(
    figlet.textSync('Red Plag', { horizontalLayout: 'full' }) 
  )  
)

// Command for login
vorpal
    .command('login','Login using your username, password and organisation passcode')
    .action((args,cb)=>{
      utils.validate(Config.get('token')).then((valid)=>{
        if(valid){
          console.log("You are already logged in")
          cb()
        }
        else{
          inquirer.prompt(login.questions).then((answers)=>{
            const spinner = ora('Logging in').start()
            axios
              .post(API_URL + 'auth/token/',answers)
              .then((res)=>{
                if(res.data.token){
                  Config.set('token',res.data.token)
                  spinner.succeed('Login successful');
                }
                else{
                  spinner.fail('Login failed');
                }
                cb();    
            },(err)=>{
              spinner.fail('Login failed');
              cb();
            })
          })
        }
      }) 
      
    })

vorpal
    .command('create','Create a new batch of code files')
    .action((args,cb)=>{
      utils.validate(Config.get('token')).then((valid)=>{
        if(valid){
          inquirer.prompt(Create.questions).then((answers)=>{
            fs.readdir(answers.dirPath,(err,filenames)=>{
              if(err){
                console.log(chalk.red("Error in reading the files. Check directory path"))
                cb();
              }
              else{
                let files = []
                filenames.forEach((val)=>{
                  files.push(answers.dirPath+'/'+val);
                })
                delete answers["dirPath"]
                create.postData(answers,files,(err,res,body)=>{
                  body = JSON.parse(body)
                  if(err || !body["id"]){
                    //console.log(err)
                    //console.log(body.id)
                    console.log(chalk.red("Error occured during batch creation.Try again"));
                    cb();
                  }
                  else{
                    //console.log(body)
                    console.log(chalk.green("Batch created successfully"));
                    cb();
                  }
                })
              }
            })
          })
        }
        else{
          console.log(chalk.red("You are not logged in"))
          cb();
        }
      }) 
    })

vorpal
    .command('batch [uid]','Prints the list of batches,download result of batch with ID = uid or delete a batch')
    .option('-d,--delete',"Deletes the batch with specified uid")
    .action((args,cb)=>{
      utils.validate(Config.get('token')).then((valid)=>{
        if(valid){
          if(args.uid){
            if(!args.options.delete)
              inquirer.prompt(batch.question).then((ans)=>{
                const spinner = ora("Downloading file").start()
                batch.download(args.uid,ans.filePath,ans.threshold/100).then((data)=>{
                  spinner.succeed("File downloaded successfully")
                  cb();
                }
                ).catch((err)=>{
                  spinner.fail("Download unsuccessful")
                  console.log(err)
                  cb()
                })
              })
            else{
              inquirer.prompt([
                {
                  type:"confirm",
                  name:"confirm",
                  message:"Are you sure you want to delete batch with ID = " + args.uid
                }
              ]).then((ans)=>{
                if(ans){
                  batch.delete(args.uid).then((val)=>{
                    console.log(chalk.green("Batch delete successfully"))
                    cb()
                  },(err)=>{
                    console.log(chalk.red("Some error occured. Please chech batch ID"))
                    cb()
                  })
                }
                else{
                  cb();
                }
              })
            }
          }
          else if(args.options.delete){
            console.log("Usage batch -d <uid>")
            cb()
          }
          else
            batch.list().then((data)=>{
              console.log('============================================================','\n')
              data.results.forEach(element => {
                console.log(chalk.bold.underline.green(element.name),'\n')
                console.log("ID :" ,chalk.blue(element.id))
                console.log("Description :",chalk.blue(element.description))
                console.log("Date created :",chalk.blue.italic(element.created_at),'\n')
                console.log('============================================================','\n')
              });
              cb();
            },(err)=>{
              console.log(chalk.red("Some error occured. Please try again :("));
              cb();
            })
        }
        else{
          console.log(chalk.red("You are not logged in"))
          cb();
        }
      }) 
    })

vorpal
    .command('logout','Logout from Red Plag server')
    .action((args,cb)=>{
      utils.validate(Config.get('token')).then((valid)=>{
        if(valid){
          logout.logout().then((data)=>{
            //console.log(data)
            Config.delete('token');
            console.log(chalk.green("Logged out successfully"))
            cb();
          },(err)=>{
            //console.log(err)
            console.log("Some error occured")
            cb()
          })
        }
        else{
          console.log(chalk.red("You are not logged in"))
          cb();
        }
      }) 
    })

vorpal
    .delimiter('red-plag$')
    .show()

  process.on('exit',(code)=>{
    //Config.clear()
  })