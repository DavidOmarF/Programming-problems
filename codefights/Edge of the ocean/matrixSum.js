function matrixElementsSum(matrix) {
    var mySum = 0;
    for(var matrix_row = 0; matrix_row < matrix.length; matrix_row++){
        console.log(matrix[matrix_row]);
    }

    for(var matrix_row = 0; matrix_row < matrix.length; matrix_row++){
        for(var matrix_col = 0; matrix_col < matrix[matrix_row].length; matrix_col++){
            if(matrix[matrix_row][matrix_col] == 0 && matrix_row + 1 != matrix.length){
                    matrix[matrix_row + 1][matrix_col] = 0;
            }
            mySum += matrix[matrix_row][matrix_col];
        }
    }
    
    for(var matrix_row = 0; matrix_row < matrix.length; matrix_row++){
        console.log(matrix[matrix_row]);
    }
    return mySum;
}

myMatrix = [
    [0, 1, 1, 2], 
    [0, 5, 0, 0], 
    [2, 0, 3, 3]
    ];

console.log(matrixElementsSum(myMatrix));