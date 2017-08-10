function almostIncreasingSequence(sequence) {
    if (sequence.length < 2) return false;
    var countFail = 0;

    for (var i = 0; i < sequence.length - 1; i++) {
        if (sequence[i] >= sequence[i + 1]) {
            countFail++;            

            if (sequence[i - 1] && sequence[i + 2]) {
                if ((sequence[i - 1] < sequence[i] && sequence[i] < sequence[i + 2]) || 
                (sequence[i - 1] < sequence[i + 1] && sequence[i + 1] < sequence[i + 2])) {
                } else {
                    countFail++;
                }
            }
        }

        if (countFail >= 2) break;
    }

    if (countFail >= 2) {
        return false;
    } else {
        return true;
    }
}



var mySequence = [1, 2, 1, 2];
console.log(mySequence[-1] < mySequence[0]);
console.log(almostIncreasingSequence(mySequence));