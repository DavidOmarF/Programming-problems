process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();    
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////

function main() {
    var n_temp = readLine().split(' ');
    var n = parseInt(n_temp[0]);
    var m = parseInt(n_temp[1]);
    a = readLine().split(' ');
    a = a.map(Number);
    b = readLine().split(' ');
    b = b.map(Number);
    var contador = 0;
    
    var maxVal = a[0];
    var minVal = b[0];
    for (var i = 0; i < n; i++){
        if ( a[i] > maxVal){
            maxVal = a[i];
        }
    }
    
    for (var i = 0; i < n; i++){
        if (b[i] < minVal){
            minVal = b[i];
        }
    }
    
    for ( var x = maxVal; x <= minVal; x += a[0]){
        for (var i = n-1; i >= 0; i--){
            if ( x % a[i] != 0){
                break;
            } else if (i == 0){
                for (var j = 0; j < m; j++){
                    var aux = 0;
                    if (b[j] % x != 0){
                        break;
                    } else {
                        if (j + 1 == m){
                            contador++;
                        }
                    }
                }
            }
        }
    }
            
    console.log(contador);
}
