import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http'

@Injectable({
  providedIn: 'root'
})
export class AuthService {
  url_register="localhost:8000/auth/register";
  url_login="localhost:8000/auth/login";
  url_logout="localhost:8000/auth/logout";
  url_profile = "localhost:8000/auth/profile";


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
