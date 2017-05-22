// Problem seen at: https://www.codewars.com/kata/57b06f90e298a7b53d000a86/

var minTime = function(index, value){
    this.i = index;
    this.val = value;
}

function getMyMin(timeTaken){
    var index = 0;
    var value = timeTaken[index];
    for(var i = 0; i < timeTaken.length; i++){
        if (timeTaken[i] < value){
            value = timeTaken[i];
            index = i;
        }
    }

    return value, index;
}

function queueTime(customers, n) {
    if (customers.length == 0){
        return 0;
    }
    
    if (n >= customers.length){
        return Math.max.apply(null, customers);
    }

    var timeTaken = [];
    var myMin = new minTime(0, customers[0]);
    for(var i = 0; i < n; i++){
        timeTaken.push(customers[i]);
        if (timeTaken[i] < myMin.val){
            myMin.val = timeTaken[i];
            myMin.i = i;
        }
    }

    console.log(timeTaken, myMin.val);
    for(var i = n; i < customers.length; i++){
        console.log("before", timeTaken, myMin.i, customers[i]);
        timeTaken[myMin.i] =timeTaken[myMin.i] + customers[i];
        myMin.val, myMin.i = getMyMin(timeTaken, myMin);
        console.log("after", timeTaken, myMin.i, customers[i]);
    }

    return Math.max.apply(null, timeTaken);
}

console.log(queueTime([2,2,3,3,4,4], 2));
