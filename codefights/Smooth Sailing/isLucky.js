function isLucky(n) {
    if(n % 2 != 0) return false;

    var numStr = String(n);
    var firstHalf = numStr.slice(0, numStr.length / 2).split("");
    var secondHalf = numStr.slice(numStr.length / 2).split("");
    var firstSum = 0;
    var secondSum = 0;
    for(var i = 0; i < firstHalf.length; i++){
        firstSum += parseInt(firstHalf[i]);
    }
    for(var i = 0; i < secondHalf.length; i++){
        secondSum += parseInt(secondHalf[i]);
    }

    return firstSum == secondSum;
}


var n = 1231
console.log(isLucky(n));