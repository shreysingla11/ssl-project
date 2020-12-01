import { Component, OnInit } from '@angular/core';
import { Batch } from '../interfaces';
import { ActivatedRoute, Router } from '@angular/router';
import { BatchService } from '../batch.service';

@Component({
  selector: 'app-batch',
  templateUrl: './batch.component.html',
  styleUrls: ['./batch.component.scss']
})
export class BatchComponent implements OnInit {
  batch:Batch;

  constructor(private route:ActivatedRoute,private batchService:BatchService,private router:Router) { }

  ngOnInit(): void {
    this.route.paramMap.subscribe((params)=>{
      this.batchService.getBatch(params.get('id')).subscribe((data)=>{
        this.batch=data;
      })
    })
    
  }

  download(){
    this.batchService.downloadResult(this.batch.id).subscribe(
      (response: any) =>{
        let dataType = response.type;
        let binaryData = [];
        binaryData.push(response);
        let downloadLink = document.createElement('a');
        downloadLink.href = window.URL.createObjectURL(new Blob(binaryData, {type: dataType}));
        downloadLink.setAttribute('download', 'result');
        document.body.appendChild(downloadLink);
        downloadLink.click();
        downloadLink.parentNode.removeChild(downloadLink);
    }
    )
  }

  delete(){
    this.batchService.deleteBatch(this.batch.id).subscribe((data)=>{
      window.location.href='/dashboard';
    },(err)=>alert('Some error occured'))
  }

}
