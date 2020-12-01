import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http'

@Injectable({
  providedIn: 'root'
})
export class AuthService {
  url_register="http://localhost:8000/auth/register/";
  url_login="http://localhost:8000/auth/login/";
  url_logout="http://localhost:8000/auth/logout/";
  url_profile = "http://localhost:8000/auth/profile";
  url_changepass = "http://localhost:8000/auth/changepassword/";

  options = {withCredentials:true}

  constructor(
    private http: HttpClient
  ) { }

  postRegister(data) {
    return this.http.post(this.url_register, data,this.options);
  }

  postLogin(data) {
    return this.http.post(this.url_login, data,this.options);
  }

  logout(){
    return this.http.get(this.url_logout,this.options);
  }

  profile(){
    return this.http.get(this.url_profile,this.options);
  }

  changePassword(data){
    return this.http.put(this.url_changepass,data,this.options);
  }
}
