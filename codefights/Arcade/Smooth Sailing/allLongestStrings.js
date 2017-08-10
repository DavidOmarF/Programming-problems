function allLongestStrings(inputArray) {
    var longest = inputArray[0].length;
    var strings = [inputArray[0]];

    for (var i = 1; i < inputArray.length; i++){
        if(inputArray[i].length == longest){
            strings.push(inputArray[i]);
            continue;
        }

        if(inputArray[i].length > longest){
            longest = inputArray[i].length;
            strings = [];
            strings.push(inputArray[i]);
        }
    }

    return strings;
}

myArray = ["aba", "aa", "ad", "vcd", "aba"];
console.log(allLongestStrings(myArray));