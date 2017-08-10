function shapeArea(n) {
    var sizes = [1];
    for(var i = 1; i < n; i++){
        sizes.push(sizes[i - 1] + i * 4);
    }
    
    return sizes[n - 1];
}
