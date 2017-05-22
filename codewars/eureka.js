// Problem seen at: https://www.codewars.com/kata/take-a-number-and-sum-its-digits-raised-to-the-consecutive-powers-and-dot-dot-dot-eureka/

function sumDigPow(a, b) {
    if (b < a || b < 0 || a < 0){
        return "Bad limits";
    }
    var eurekaNums = [];
    for(var i = a; i <= b; i++){
        var myNumStr = String(i);
        var mySum = 0;
        for(var j = 0; j < myNumStr.length; j++){
            mySum += Math.pow(Number(myNumStr[j]), j+1) 
        }
        if (i == mySum){
            eurekaNums.push(i);
        }
    }

    return eurekaNums;
}


var lower = 0;
var upper = 10000;
console.log(sumDigPow(lower,upper));
