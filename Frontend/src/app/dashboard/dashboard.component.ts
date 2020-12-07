import { Component, OnInit } from '@angular/core';
import { NgbModal } from '@ng-bootstrap/ng-bootstrap';
import { FormBuilder, FormControl, FormGroup, Validators } from '@angular/forms';
import { BatchService } from '../batch.service';
import { Batch } from '../interfaces';
import { Router } from '@angular/router';

@Component({
  selector: 'app-dashboard',
  templateUrl: './dashboard.component.html',
  styleUrls: ['./dashboard.component.scss']
})
export class DashboardComponent implements OnInit {
  languages=["C++","Python"];
  createForm:FormGroup;
  fileList = [];
  batches:Batch[]=[];

  constructor(private modalService: NgbModal,private formBuilder:FormBuilder,private batchService:BatchService,private router:Router) {
    this.createForm = this.formBuilder.group({
      name: new FormControl('',[Validators.required]),
      description: new FormControl('',[Validators.required]),
      language:new FormControl('',[Validators.required]),
      inline_comment:new FormControl({value:'',disabled:true}),
      multi_begin:new FormControl({value:'',disabled:true}),
      multi_end:new FormControl({value:'',disabled:true}),
    })
   }

    disable(){
     if(this.languages.includes(this.createForm.get('language').value)){
      this.createForm.get('inline_comment').setValue('');
      this.createForm.get('multi_begin').setValue('');
      this.createForm.get('multi_end').setValue('');
      this.createForm.get('inline_comment').disable();
      this.createForm.get('multi_begin').disable();
      this.createForm.get('multi_end').disable();
     }
     else{
      this.createForm.get('inline_comment').enable();
      this.createForm.get('multi_begin').enable();
      this.createForm.get('multi_end').enable();
     }
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
    console.log(data)
    this.batchService.createBatch(data,this.fileList).subscribe(data=>{
      console.log(data);
      alert("Batch created");
      this.syncBatchList()
    },err=>{
      alert(err.status)
    })
  }

  

}
