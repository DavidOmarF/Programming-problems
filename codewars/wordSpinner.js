// Problem seen at: https://www.codewars.com/kata/stop-gninnips-my-sdrow/train/javascript

function spinWords(myString){
    var wordsArr = myString.split(" ");
    for(var i = 0; i < wordsArr.length; i++){
        if (wordsArr[i].split("").length >= 5){
            wordsArr[i] = wordsArr[i].split("").reverse().join("");
        }
    }

    return wordsArr.join(" ");
}
