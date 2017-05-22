// Problem seen at: https://www.codewars.com/kata/563b662a59afc2b5120000c6

function nbYear(p0, percent, aug, p) {
    percent = percent / 100.0;
    var years = 0;
    while (p0 < p){
        p0 = p0 + p0 * percent + aug;
        years++;
    }
    return years;
}
