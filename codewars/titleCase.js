// Problem seen at: https://www.codewars.com/kata/5202ef17a402dd033c000009

function titleCase(title, minorWords) {
    if(minorWords == undefined){
        return titleCase(title, "");
    }
    title = title.toLowerCase().split(" ");
    minorWords = minorWords.toLowerCase().split(" ");
    for (var i = 0; i < title.length; i++){
        if (minorWords.indexOf(title[i]) == -1 || !i){
            title[i] = title[i].slice(0, 1).toUpperCase() + title[i].slice(1, title[i].length);
        }
    }
    return title.join(" ");
}


var title = "THE WIND IN THE WILLOWS";
var minorWords = "The In";
console.log(titleCase(title, minorWords));
