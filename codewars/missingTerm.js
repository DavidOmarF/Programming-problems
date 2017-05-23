// Problem seen at: https://www.codewars.com/kata/52de553ebb55d1fca3000371

function findMissing (list) {
    var increments = [];
    var increment = 0;
    increments.push(list[1] - list[0]);
    increments.push(list[2] - list[1]);

    if (Math.abs(increments[0]) < Math.abs(increments[1])){
        // Selects the lower increment, because if the step is the
        // biger one, one of the values shouldn't exist.
        increment = increments[0];
    } else {
        increment = increments[1]; 
    }

    for(var i = 1; i < list.length; i++){
        if (list[i] - increment != list[i - 1]){
            return list[i] - increment;
        }
    }
}

var mySeries = [-7, -5, -3, -1, 1,3,5,9,11];
console.log(findMissing(mySeries));
