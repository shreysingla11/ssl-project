const axios = require('axios');
const Configstore = require('configstore');
const package = require('./package.json');
const Config = new Configstore(package.name);
module.exports = {
    validate : async function(token){
        try{
        let data = (await axios.get('http://localhost:8000/auth/profile',{
            headers:{
                Authorization: 'Token ' + token
            }
        })).data;
        if(data.username)
            return true
        return false
        }
        catch{
            return false;
        }   
    }
}