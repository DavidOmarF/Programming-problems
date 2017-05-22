// Problem seen at: https://www.codewars.com/kata/52685f7382004e774f0001f7

function humanReadable(seconds) {
    if (seconds > 359999){
        return "Limit exceded";
    }
    var hours = ("0" + (parseInt(seconds / 3600))).slice(-2);
    var minutes = ("0" + (parseInt((seconds - hours * 3600) / 60))).slice(-2);
    var seconds = ("0" + (seconds - hours * 3600 - minutes * 60)).slice(-2);
    return hours + ":" + minutes + ":" + seconds;
}

var mySeconds = 359999
console.log(humanReadable(mySeconds));
