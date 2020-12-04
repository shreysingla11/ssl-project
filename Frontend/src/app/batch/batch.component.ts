import { Component, OnInit} from '@angular/core';
import { Batch } from '../interfaces';
import { ActivatedRoute, Router } from '@angular/router';
import { BatchService } from '../batch.service';
import * as Highcharts from 'highcharts';
import {chartOptions} from './dummy';

declare var Plotly: any;
@Component({
  selector: 'app-batch',
  templateUrl: './batch.component.html',
  styleUrls: ['./batch.component.scss']
})
export class BatchComponent implements OnInit {
  batch:Batch;
  data:number[];
  filenames:string[];
  updateFlag = false;
  ind = [];
  Highcharts: typeof Highcharts = Highcharts;
  chartOptions: Highcharts.Options = chartOptions as Highcharts.Options;
  
  constructor(private route:ActivatedRoute,private batchService:BatchService,private router:Router) {
   }

  updateGraph(threshold){
    this.ind = [];
    this.data.forEach((val,index)=>{
      if(val>threshold/100)
        this.ind.push([Math.floor(index/this.filenames.length),index%this.filenames.length]);
    });
    console.log(threshold);

    var points = this.data;
    var names = this.filenames;

    this.chartOptions.series[0] = {
      type:'scatter',
      name: 'Above threshold of ' + threshold + ' %',
      color: 'rgba(223, 83, 83, .5)',
      data: this.ind,
    };
    this.chartOptions.plotOptions = {
      scatter: {
        marker: {
          radius: 4,
          states: {
            hover: {
              enabled: true,
              lineColor: 'rgb(100,100,100)'
            }
          }
        },
        tooltip: {
          pointFormatter:function(){
            return "<b>"+ (points[this.x*names.length + this.y]*100).toPrecision(3) +" %</b><br>" + names[this.x] + "  " + names[this.y];
          },
          headerFormat : '',
        }
      }
    }
    this.updateFlag = true;
  }

  ngOnInit(): void {
    this.route.paramMap.subscribe((params)=>{
      this.batchService.getBatch(params.get('id')).subscribe((data)=>{
        this.batch = data;
        let temp = JSON.parse(this.batch.result);
        this.filenames = temp["filenames"];
        this.data = temp["data"];
        this.updateGraph(0);
      })
    });

    
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
