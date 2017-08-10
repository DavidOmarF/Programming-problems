String.prototype.count=function(c) { 
  var result = 0, i = 0;
  for(i;i<this.length;i++)if(this[i]==c)result++;
  return result;
};

function commonCharacterCount(s1, s2) {
    var chars = [];
    var total = 0;
    for(var i = 0; i < s1.length; i++){
        if(chars.indexOf(s1[i]) == -1 ){
            chars.push(s1[i]);
        }
    }

    for(var i = 0; i < chars.length; i++){
        total += Math.min(s1.count(chars[i]), s2.count(chars[i]));
    }

    return total;
}


var s1 = "aabcc";
var s2 = "adcaa";
console.log(commonCharacterCount(s1, s2));


