export var chartOptions = {
    chart: {
      type: 'scatter',
      zoomType: 'xy'
    },
    title: {
      text: 'Suspicious files plot'
    },
    xAxis: {
      startOnTick: true,
      endOnTick: true,
      showLastLabel: true
    },
    yAxis: {
      title: {
        text: 'Files'
      }
    },
    plotOptions: {
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
            return "None";
          },
          headerFormat : '',
        }
      }
    },
    series: [{
      type:'scatter',
      name: 'Above threshold of ' + 0 + ' %',
      color: 'rgba(223, 83, 83, .5)',
      data: [],
    }, ]
  };