import { Component, OnInit } from '@angular/core';
import { FormBuilder } from '@angular/forms';
import { Router } from '@angular/router';
import { AuthService } from '../auth.service';

@Component({
  selector: 'app-profile',
  templateUrl: './profile.component.html',
  styleUrls: ['./profile.component.scss']
})
export class ProfileComponent implements OnInit {

  username:string;
  name: string;
  email: string;
  org:string;
  bcount:number;
  ccount:number;
  pass_form;
  constructor(private auth: AuthService,private formBuilder:FormBuilder,private router:Router) {
    this.pass_form = this.formBuilder.group({
      old_password:'',
      new_password:'',
    })
   }
  ngOnInit(): void {
    this.auth.profile().subscribe((data)=>{
        console.log(data)
        this.name = data["first_name"] + " " + data["last_name"];
        this.username = data["username"];
        this.email = data["email"];
        this.org = data["org"]["name"];
        this.bcount = data["bcount"];
        this.ccount = data["ccount"];
    });
  }

  onSubmit(){
    this.auth.changePassword(this.pass_form.value).subscribe(
      (data) => {
        alert(data["message"]);
        this.router.navigate(['login'])
      },
      (error) => {
        //console.log(error)
        alert(error["error"]["error"]);
      }
    )
  }

}
