// Problem seen at: https://www.codewars.com/kata/56a5d994ac971f1ac500003e

function longestConsec(strarr, k) {
    if (k > strarr.length || k < 1 || strarr.length == 0){
        //Checks for correct execution logic
        return "";
    }

    var answer = "";
    var maxLength = 0;
    var kConsecutiveStrings = [];
    
    for (var i = 0; i < strarr.length - k + 1; i++){
        kConsecutiveStrings[i] = strarr[i];
        for (var j = i+1; j < k + i; j++){
            kConsecutiveStrings[i] = kConsecutiveStrings[i] + strarr[j];
            // Concatenates strarr[i] and the 'k' following strings in only one string in
            // kConsecutiveStrings[i]
        }
        if (kConsecutiveStrings[i].length > maxLength){
            // Selects the longest string in kConsecutiveStrings array.
            maxLength = kConsecutiveStrings[i].length;
            answer = kConsecutiveStrings[i];
        }
    }

    return answer;
}


var myArr = ["zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail"];
var k = 2;
console.log(longestConsec(myArr, k))
