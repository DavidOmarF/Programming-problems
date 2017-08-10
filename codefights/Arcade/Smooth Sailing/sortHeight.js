function count_m1(array, value){
    for(var i = 0; i < array.length; i++){
        if(array[i] != value){
            return i;
        }
    }
    return 0;
}

function sortByHeight(myArr) {
    var original = myArr.slice();
    myArr.sort(function sortNumber(a,b) {return a - b;})
    noNegIndex = count_m1(myArr, -1);
    myArr = myArr.slice(noNegIndex);
    for(var i = 0, j = 0; i < original.length; i++){
        if(original[i] == -1){
            continue;
        }
        original[i] = myArr[j];
        j++;
    }

    return original;
}

var myArr = [-1, 150, 190, 170, -1, -1, 160, 180]
console.log(sortByHeight(myArr));