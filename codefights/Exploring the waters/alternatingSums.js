function alternatingSums(myRow) {
    var total = [0, 0];
    for(var i = 0; i < myRow.length; i++){
        if(i % 2 == 0){
            total[0] += myRow[i];
        } else {
            total[1] += myRow[i];
        }
    }
    return total;
}

var myRow = [50, 60, 60, 45, 70];
console.log(alternatingSums(myRow));