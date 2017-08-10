function arrayMaximalAdjacentDifference(inputArray) {
    var maxDiff = 0;
    for(var i = 1; i < inputArray.length; i++){
        if(Math.abs(inputArray[i] - inputArray[i - 1]) > maxDiff){
            maxDiff = Math.abs(inputArray[i] - inputArray[i - 1]);
        }
    }
    return maxDiff;
}

var myArr = [2, 4, 1, 0];
console.log(arrayMaximalAdjacentDifference(myArr));