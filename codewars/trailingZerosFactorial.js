// Problem seen at: https://www.codewars.com/kata/52f787eb172a8b4ae1000a34

function zeros (n) {
    var numZeros = 0;
    var power = 5;
    for(var i = 0, maxPower = log5(n); i < maxPower; i++){
        numZeros = numZeros + parseInt(n / power);
        power = power * 5;
    }
    return numZeros;
}

function log5(val) {
    // Calculates the maximum power of five that is less or equal to the value passed
  return parseInt(Math.log(val) / Math.log(5));
}

var myFactorial = 10123;
console.log(zeros(myFactorial));
