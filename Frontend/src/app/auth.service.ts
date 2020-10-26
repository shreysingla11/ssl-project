import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http'

@Injectable({
  providedIn: 'root'
})
export class AuthService {
  url_register;
  url_login;


  constructor(
    private http: HttpClient
  ) { }

  postRegister(data) {
    return this.http.post(this.url_register, data);
  }

  postLogin(data) {
    return this.http.post(this.url_login, data);
  }

}
