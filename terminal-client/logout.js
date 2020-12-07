const Configstore = require('configstore');
const package = require('./package.json');
const Config = new Configstore(package.name);
const axios = require('axios').default;
module.exports = {
    logout: async function(){
        return axios.get('http://localhost:8000/auth/token-logout',{
            headers:{
                Authorization: 'Token ' + Config.get('token')
            }
        }); 
    } 
}