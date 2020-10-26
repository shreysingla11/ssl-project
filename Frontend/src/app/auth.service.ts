import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http'

@Injectable({
  providedIn: 'root'
})
export class AuthService {
  url_register;
  url_login;
  url_logout;
  url_profile;


  constructor(
    private http: HttpClient
  ) { }

  postRegister(data) {
    return this.http.post(this.url_register, data);
  }

  postLogin(data) {
    return this.http.post(this.url_login, data);
  }

  logout(){
    return this.http.get(this.url_logout);
  }

  profile(){
    return this.http.get(this.url_profile);
  }

}
