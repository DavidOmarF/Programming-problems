// Problem seen at: https://www.codewars.com/kata/54bf1c2cd5b56cc47f0007a1/

function duplicateCount(text){
    var text = text.toLowerCase();
    var repetitions = 0;
    var repeated = []; // Arr containing already repeated letters.
    for (var i = 0; i < text.length; i++){
        if(repeated.indexOf(text[i]) == -1 && text.slice(i+1, text.length).indexOf(text[i]) != -1){
        // if current letter isn't in "already repeated letters" array, and it repeats it in 
        // original string, it proceeds.
            repetitions++;
            repeated.push(text[i]); //adds current letter to repeated letters
        }
    }

    return repetitions;
}

var myString = "aasd933jksjd9939833sdasddsgggsd3"
console.log(duplicateCount(myString))
