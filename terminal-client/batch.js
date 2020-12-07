const axios = require('axios').default;
const chalk = require('chalk');
const Configstore = require('configstore');
const package = require('./package.json');
const Config = new Configstore(package.name);
const fs = require('fs')

module.exports = {
    list : async function(){
        let data = (await axios.get('http://localhost:8000/rp/batch',{
            headers:{
                Authorization: 'Token ' + Config.get('token')
            }
        })).data;
        
        return data   
    },
    delete : async function(uid){
        let data = (await axios.delete('http://localhost:8000/rp/batch/'+uid,{
            headers:{
                Authorization: 'Token ' + Config.get('token')
            }
        }));
        
        return data   
    },

    download : async function(id,path,threshold){
        let response = await axios.get('http://localhost:8000/rp/download/'+id+'?threshold='+threshold,{
            headers:{
                Authorization: 'Token ' + Config.get('token')
            },
            responseType:'stream'
        });
        
        const writer = fs.createWriteStream(path)
        response.data.pipe(writer)
        return new Promise((resolve, reject) => {
            writer.on('finish', resolve)
            writer.on('error', reject)
        })
    },
    question:[
        {
            name:'filePath',
            message:'Enter absolute path of the file you want to save the results in',
            type:'input'
        },
        {
            name:'threshold',
            message:'Enter the threshold similarity above which you would like to obtain results',
            type:'number'
        }
    ],


}