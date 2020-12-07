const Configstore = require('configstore');
const package = require('./package.json');
const Config = new Configstore(package.name);
const request = require('request')
const fs = require('fs')
module.exports = {
    questions:[
        {
          name:'name',
          message:'Enter the batch name',
          type:'input',
        },
        {
          name:'description',
          message:'Enter a short description of the batch',
          type:'input',
        },
        {
            type: 'expand',
            name: 'language',
            message: 'Choose the programming language used in code files',
            choices: [
              {
                key: 'c',
                value: 'C++',
              },
              {
                key: 'p',
                value: 'Python',
              },
              {
                  key:'o',
                  value:'Other',
              }
            ],
        },
        {
            name:'inline_commment',
            message:'Enter the character(s) to start an inline comment',
            type:'input',
            when : (answers) => answers.language == "Other"
        },
        {
            name:'multi_begin',
            message:'Enter the character(s) to start a multiline comment',
            type:'input',
            when : (answers) => answers.language == "Other"
        },
        {
            name:'multi_end',
            message:'Enter the character(s) to end a multiline comment',
            type:'input',
            when : (answers) => answers.language == "Other"
        },
        {
            name : 'dirPath',
            message: 'Enter absolute path to the directory where source code files are stored',
            type:'input'
        }
    
      ],
      postData :  function(answers,files,callback){
        answers.files = []
        for(var i in files){
          answers.files.push(fs.createReadStream(files[i]))
        }
        //console.log(answers)
        const headers = {
          "Authorization": "Token " + Config.get('token')
        }
        //console.log(headers)
        request.post({
          url:'http://localhost:8000/rp/batch/', 
          formData: answers,
          headers:headers
        }, callback);
      },

    }