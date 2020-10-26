import { Component, OnInit } from '@angular/core';
import { FormBuilder } from '@angular/forms';
import { AuthService } from '../auth.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.scss']
})

export class LoginComponent implements OnInit {

  form;

  constructor(
    private auth: AuthService,
    private formBuilder: FormBuilder,
    private router: Router
  ) {
    this.form = this.formBuilder.group({
      username: '',
      password: '',
      org_pass: ''
    })
  }

  ngOnInit(): void {
  }

  onSubmit() {
    this.auth.postLogin(this.form.value).subscribe(
      (data) => {
        if (data.hasOwnProperty('username')) {
          this.router.navigate(['/dashboard']);
        }
        else {
          alert("Please try again");
        }

      },
      (error) => {
        alert("Please try again");
      }
    )
  }

}
