function reverse(s){
    return s.split("").reverse().join("");
}

function reverseParentheses(myStr) {
    while( myStr.indexOf(")") != -1){
        var closeParen = myStr.indexOf(")");
        var openParen = myStr.lastIndexOf("(", closeParen);
        // console.log(myStr);
        // console.log(myStr.slice(0, openParen), reverse(myStr.slice(openParen + 1, closeParen)), myStr.slice(closeParen + 1));
        myStr = myStr.slice(0, openParen) + reverse(myStr.slice(openParen + 1, closeParen)) + myStr.slice(closeParen + 1);
    }

    return myStr;
}

var myStr = "The ((quick (brown) (fox) jumps over the lazy) dog)";
console.log(reverseParentheses(myStr));