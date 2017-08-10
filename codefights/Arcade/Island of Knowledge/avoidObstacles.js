function avoidObstacles(inputArray) {
    inputArray.sort((a, b) => a - b);
    return inputArray;
    var freePos = [inputArray[0] - 1];
    for(var i = 1; i < inputArray.length; i++){
        for(var j = inputArray[i - 1] + 1; j < inputArray[i]; j++ ){
            freePos.push(j);
        }
    }
    freePos.push(inputArray[inputArray.length - 1] + 1);
    // console.log(freePos);
    for(var i = 0; i < freePos[freePos.length - 1] + 1; i++){
        cont = false;
        for(var arr_i = 1; arr_i < freePos.length - 2; arr_i++){
            if(freePos[arr_i] + i != freePos[arr_i + 1]){
                cont = true;
                break;
            }
        }
        if (cont == true) {
            continue;
        }
        if(freePos[1] - i < freePos[0] && freePos[freePos.length - 2] + i > freePos[freePos.length - 1])
            return i;
    }
    return 0;
}

var obstacles = [1, 4, 10, 6, 2];
console.log(avoidObstacles(obstacles));