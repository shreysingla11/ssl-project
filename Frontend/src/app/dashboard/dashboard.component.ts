import { Component, OnInit } from '@angular/core';
import { NgbModal } from '@ng-bootstrap/ng-bootstrap';
import { FormBuilder } from '@angular/forms';
import { BatchService } from '../batch.service';
import { Batch } from '../interfaces';
import { Router } from '@angular/router';

@Component({
  selector: 'app-dashboard',
  templateUrl: './dashboard.component.html',
  styleUrls: ['./dashboard.component.scss']
})
export class DashboardComponent implements OnInit {

  createForm;
  fileList = [];
  batches:Batch[]=[];

  constructor(private modalService: NgbModal,private formBuilder:FormBuilder,private batchService:BatchService,private router:Router) {
    this.createForm = this.formBuilder.group({
      name: '',
      description: '',
    })
   }

   ngOnInit(): void {
     this.syncBatchList()
  }
  open(content) {
    this.modalService.open(content, {ariaLabelledBy: 'modal-basic-title', size:'xl', centered: true}).result.then(result=>this.submitCreateForm())
  }

  syncFiles(event){
    this.fileList = event.target.files;
  }

  syncBatchList(){
    this.batchService.getBatchList().subscribe((data)=>{
      this.batches = data.results;
      console.log(this.batches)
    })
  }
  submitCreateForm(){
    let data  = this.createForm.value
    this.batchService.createBatch(data.name,data.description,this.fileList).subscribe(data=>{
      console.log(data);
      alert("Batch created");
      this.syncBatchList()
    },err=>{
      alert(err.status)
    })
  }

  

}
