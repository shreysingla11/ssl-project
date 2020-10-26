import { Router, CanActivate } from '@angular/router';
import { Injectable } from '@angular/core';
import { AuthService } from './auth.service';

@Injectable({
    providedIn: 'root'
  })
export class LoginRegisterGuard implements CanActivate {

    constructor(private auth: AuthService, private router: Router) {}

    canActivate(): Promise<boolean> {
        return new Promise((resolve, reject) => {
            this.auth.profile().subscribe(data => {
                    this.router.navigate(['dashboard']);
                    resolve(false);
                    
            },err=>resolve(true));   
        });
    }
}

@Injectable({
    providedIn: 'root'
})
export class DashboardGuard implements CanActivate {
    
        constructor(private auth: AuthService, private router: Router) {}
        canActivate(): Promise<boolean> {
    
            return new Promise((resolve, reject) => {
                this.auth.profile().subscribe(data => {
                    // console.log(this.data);
                        resolve(true);
                },err=>{
                    this.router.navigate(['login'])
                    resolve(false);
                });   
            });
        };
}