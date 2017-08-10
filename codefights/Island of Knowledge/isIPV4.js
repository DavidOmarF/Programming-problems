function isIPv4Address(inputString) {
    if(inputString.search(/[a-z]/gi) != -1) return false;
    var list = inputString.split(".");
    if(list.length != 4) return false;
    for(var i = 0; i < list.length; i++){
        if(parseInt(list[i]) > 255 || list[i].length == 0) return false;
    }
    return true;
}

var myIP = "1.1.1.1a";
console.log(isIPv4Address(myIP));