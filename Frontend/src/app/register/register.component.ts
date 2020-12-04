import { Component, OnInit } from '@angular/core';
import { FormBuilder } from '@angular/forms';
import { AuthService } from '../auth.service';
import { Router } from '@angular/router';
import { collectExternalReferences } from '@angular/compiler';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.scss']
})

export class RegisterComponent implements OnInit {

  form;

  constructor(
    private auth: AuthService,
    private formBuilder: FormBuilder,
    private router: Router
  ) { 
    this.form = this.formBuilder.group({
      username: '',
      email: '',
      first_name: '',
      last_name: '',
      password: '',
      org_pass:''
    })
  }

  ngOnInit(): void {
  }

  onSubmit(){
    this.auth.postRegister(this.form.value).subscribe(
      (data) => {
        if (data.hasOwnProperty('username')){
          this.router.navigate(['login']);
        }
        else {
          alert("Please try again");
        }
        
      },
      (error) => {
        console.log(error)
        alert("Please try again");
      }
    )
  }

}
