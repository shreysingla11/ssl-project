import { Component, OnInit } from '@angular/core';
import { AuthService } from '../auth.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-header',
  templateUrl: './header.component.html',
  styleUrls: ['./header.component.scss']
})
export class HeaderComponent implements OnInit {

  username:string="";

  constructor(private auth:AuthService,private router:Router) { }

  ngOnInit(): void {
    this.auth.profile().subscribe((data)=>{
      console.log(data)
      this.username = data["username"];
    })
  }

  logout(){
    this.auth.logout().subscribe((data)=>{
      window.location.reload()
    })
  }


}
