function arrayChange(inputArray) {
    var newSum = 0;
    var originalSum = 0;
    for(var i = 1; i < inputArray.length; i++){
        originalSum += inputArray[i];
        if(inputArray[i] <= inputArray[i-1]){
            inputArray[i] += inputArray[i-1] - inputArray[i] + 1;
        }
        newSum += inputArray[i];
    }
    return newSum - originalSum;
}

var myArr = [2, 3, 3, 5, 5, 5, 4, 12, 12, 10, 15];
console.log(arrayChange(myArr));