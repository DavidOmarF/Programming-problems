function makeArrayConsecutive2(statues) {
    statues.sort(function sortNumber(a,b) {return a - b;});
    return statues[statues.length - 1] - statues[0] - statues.length + 1;
}

var myArr = [1, 2, 3, 4, 5, 6, 7, 12312,11514, 12123, 1111, 19999];
console.log(makeArrayConsecutive2(myArr));