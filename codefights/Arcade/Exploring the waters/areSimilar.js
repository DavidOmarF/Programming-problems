function areEqual(a, b){
    a.sort(function sortNumber(a,b){return a - b;});
    b.sort(function sortNumber(a,b){return a - b;});
    for(var i = 0; i < a.length; i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

function areSimilar(a, b) {
    var count = 0;
    var first = 0;
    for(var i = 0; i < a.length; i++){
        if(a[i] != b[i]){
            count++;
        }
        if(a.indexOf(b[i]) == -1){
            return false;
        }
        if(b.indexOf(a[i]) == -1){
            return false;
        }
    }

    if(count == 2 || count == 0) return areEqual(a, b);
    return false;
}

var a = [1, 2, 3, 2, 2, 3, 3, 33];
var b = [1, 2, 2, 2, 2, 3, 2, 33];

console.log(areSimilar(a, b));