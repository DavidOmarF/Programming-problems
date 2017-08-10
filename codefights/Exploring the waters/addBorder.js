    function addBorder(picture) {

        for(var i = 0; i < picture.length; i++){
            picture[i] = "*" + picture[i] + "*";
        }

        var hor = "";

        for(var i = 0; i < picture[0].length; i++){
            hor += "*";
        }


        return hor.split(" ").concat(picture).concat(hor.split(" "));
    }

var picture = 
["abc",
"ded"];

console.log(addBorder(picture));