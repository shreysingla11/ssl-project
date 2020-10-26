import { Component, OnInit } from '@angular/core';
import { NgbModal } from '@ng-bootstrap/ng-bootstrap';

@Component({
  selector: 'app-dashboard',
  templateUrl: './dashboard.component.html',
  styleUrls: ['./dashboard.component.scss']
})
export class DashboardComponent implements OnInit {

  afuConfig = {
    multiple: false,
    formatsAllowed: ".jpg,.png",
    maxSize: "1",
    uploadAPI:  {
      url:"https://example-file-upload-api",
      method:"POST",
      responseType: 'blob',
    },
    theme: "dragNDrop",
    hideProgressBar: false,
    hideResetBtn: false,
    hideSelectBtn: false,
    fileNameIndex: true,
    replaceTexts: {
      selectFileBtn: 'Select Files',
      resetBtn: 'Reset',
      uploadBtn: 'Upload',
      dragNDropBox: 'Drag N Drop',
      attachPinBtn: 'Attach Files...',
      afterUploadMsg_success: 'Successfully Uploaded !',
      afterUploadMsg_error: 'Upload Failed !',
      sizeLimit: 'Size Limit'
    }
  };
  batchname=""

  l=['Bhavnoor','Jayesh','Tanu','Shrey']
  constructor(private modalService: NgbModal) { }

  open(content) {
    this.modalService.open(content, {ariaLabelledBy: 'modal-basic-title', size:'xl', centered: true})
  }

  ngOnInit(): void {
  }

}
