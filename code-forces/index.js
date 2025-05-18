function calculte() {
    const input = "4 2".split(" ").map(Number);
    var a = input[0]
    var b = input[1]

    var sum = a;
    var rest = a / b;
    while (rest > 0) {
        sum += rest;
        rest = rest / b;
    }
 
 
    return sum;
}

console.log(calculte())