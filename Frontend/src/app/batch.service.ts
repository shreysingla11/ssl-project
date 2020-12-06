import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { from, Observable } from 'rxjs';
import { Batch, BatchData } from './interfaces';

@Injectable({
  providedIn: 'root'
})
export class BatchService {

  constructor(private http:HttpClient) { }

  BATCH_URL = "http://localhost:8000/rp/batch/";
  DOWNLOAD_URL = "http://localhost:8000/rp/download/";
  options = {withCredentials:true}
  downloadOptions = {
    withCredentials:true,
    responseType:'blob' as 'json'
  }

  createBatch(data,files:File[]){
    let form = new FormData()

    Object.keys(data).forEach((value)=>{
      form.append(value,data[value]);
    })
    for(let i=0;i<files.length;i++)
      form.append("files",files[i])
    
    return this.http.post(this.BATCH_URL,form,this.options)

  }
  getBatchList():Observable<BatchData>{
    return this.http.get<BatchData>(this.BATCH_URL,this.options)
  }

  getBatch(uid:string){
    return this.http.get<Batch>(this.BATCH_URL+uid,this.options)
  }

  downloadResult(uid:string,threshold:number){
    return this.http.get(this.DOWNLOAD_URL+uid+"?threshold="+threshold,this.downloadOptions)
  }

  deleteBatch(uid:string){
    return this.http.delete(this.BATCH_URL+uid,this.options)
  }
}


