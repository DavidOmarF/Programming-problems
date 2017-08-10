String.prototype.count=function(c) { 
  var result = 0, i = 0;
  for(i;i<this.length;i++)if(this[i]==c)result++;
  return result;
};

function palindromeOdd (inputString){
    var letters = [];
    var midFound = false;
    for(var i = 0; i < inputString.length; i++){
        if(letters.indexOf(inputString[i]) != -1) {
            continue;
        } else if(inputString.count([inputString[i]]) % 2 != 0){
            letters.push(inputString[i]);
            if(!midFound){
                midFound = true;
            } else {
                return false;
                // console.log("else");
            }
        }
    }
    return true;
}

function palindromeEven (inputString){
    var letters = [];
    for(var i = 0; i < inputString.length; i++){
        if(letters.indexOf(inputString[i]) != -1) continue;
        if(inputString.count([inputString[i]]) % 2 != 0){
            return false;
        }
    }
    return true;
}

function palindromeRearranging(inputString) {
    // if(inputString.length == 1)return false;
    if(inputString.length % 2 == 0){
        return palindromeEven(inputString);
    }
    return palindromeOdd(inputString);
}

var input = "bca";
console.log(palindromeRearranging(input));