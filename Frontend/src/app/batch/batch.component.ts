import { Component, OnInit } from '@angular/core';
import { Batch } from '../interfaces';
import { ActivatedRoute } from '@angular/router';
import { BatchService } from '../batch.service';

@Component({
  selector: 'app-batch',
  templateUrl: './batch.component.html',
  styleUrls: ['./batch.component.scss']
})
export class BatchComponent implements OnInit {
  batch:Batch;

  constructor(private route:ActivatedRoute,private batchService:BatchService) { }

  ngOnInit(): void {
    console.log("hello")
    this.batchService.getBatch(this.route.snapshot.params['id']).subscribe((data)=>this.batch=data)
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

}
