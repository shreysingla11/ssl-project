import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { DashboardComponent } from './dashboard/dashboard.component';
import { LoginComponent } from './login/login.component';
import { RegisterComponent } from './register/register.component';
import { LoginRegisterGuard, DashboardGuard } from './auth-guard';

const routes: Routes = [
  {
    path:'login',
    component: LoginComponent,
    canActivate: [LoginRegisterGuard],
  },
  {
    path : 'register',
    component : RegisterComponent,
    //canActivate: [LoginRegisterGuard],
  },
  {
    path : 'dashboard',
    component : DashboardComponent,
    canActivate: [DashboardGuard],
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
