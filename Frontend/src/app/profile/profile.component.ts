import { Component, OnInit } from '@angular/core';
import { FormBuilder } from '@angular/forms';
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
  pass_form;
  constructor(private auth: AuthService,private formBuilder:FormBuilder) {
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
        this.org = data["org"]["name"]
    });
  }

  onSubmit(){
    this.auth.changePassword(this.pass_form.value).subscribe(
      (data) => {
        alert(data["message"])
      },
      (error) => {
        alert(error["error"]);
      }
    )
  }

}
