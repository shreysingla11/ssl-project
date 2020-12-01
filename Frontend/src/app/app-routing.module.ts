import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { DashboardComponent } from './dashboard/dashboard.component';
import { LoginComponent } from './login/login.component';
import { RegisterComponent } from './register/register.component';
import { LoginRegisterGuard, DashboardGuard } from './auth-guard';
import { BatchComponent } from './batch/batch.component';
import { ProfileComponent } from './profile/profile.component';

const routes: Routes = [
  {
    path:'login',
    component: LoginComponent,
    canActivate: [LoginRegisterGuard],
  },
  {
    path : 'register',
    component : RegisterComponent,
    canActivate: [LoginRegisterGuard],
  },
  {
    path : 'dashboard',
    component : DashboardComponent,
    canActivate: [DashboardGuard],
    children :[
      {
        path:':id',
        component : BatchComponent,
        //canActivate : [DashboardGuard]
      }
    ]
  },
  {
    path : 'profile',
    component : ProfileComponent,
    canActivate : [DashboardGuard],
  },
  {
    path : '**',
    redirectTo:'login',
  }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
