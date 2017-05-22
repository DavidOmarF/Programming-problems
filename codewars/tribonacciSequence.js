// Problem seen at: https://www.codewars.com/kata/556deca17c58da83c00002db/train/javascript

function tribonacci(signature,n){
    if (n <= 3){
        return (signature.slice(0,n));
    }
    var myArr = signature.slice(0,3);
    for(var i = 3; i < n; i++){
        myArr.push(myArr[i - 3] + myArr [i - 2] + myArr [i - 1]);
    }
    
    return myArr;
}
