const fs = require('fs')
const request = require('request')
const formData = {
    // Pass a simple key-value pair
    name: 'ss',
    // Pass data via Buffers
    description: "ss",
    // Pass data via Streams
    language:"C++",
    // Pass multiple values /w an Array
    files: [
      fs.createReadStream("/home/hp/Sem3/CS251/RedPlag/ProjectRepo/Backend/Parser/sample2/1.cpp"),
      fs.createReadStream("/home/hp/Sem3/CS251/RedPlag/ProjectRepo/Backend/Parser/sample2/2.cpp"),
    ],
    // Pass optional meta-data with an 'options' object with style: {value: DATA, options: OPTIONS}
    // Use case: for some types of streams, you'll need to provide "file"-related information manually.
    // See the `form-data` README for more information about options: https://github.com/form-data/form-data
  };
  console.log(formData)
  request.post({url:'http://localhost:8000/rp/batch/', formData: formData,headers:{
    Authorization: 'Token 88b37342e93fc4fd3a678ccc7936c407843aa5ef'
  }}, function optionalCallback(err, httpResponse, body) {
    if (err) {
      return console.error('upload failed:', err);
    }
    console.log('Upload successful!  Server responded with:', body);
  });