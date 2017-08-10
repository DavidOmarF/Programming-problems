function adjacentElementsProduct(inputArray) {
    if(inputArray.length == 2){
        return inputArray[0] * inputArray[1];
    }
    
    var max = inputArray[0] * inputArray[1];
    
    for(var i = 2; i < inputArray.length; i++){
        if(inputArray[i] * inputArray[i - 1] > max){
            max = inputArray[i] * inputArray[i - 1];
        }
    }
    
    return max;
}
