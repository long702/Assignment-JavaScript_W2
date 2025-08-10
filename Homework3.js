// ...existing code...
const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

readline.question("Enter your grade (A, B, C, etc): ", (grade) => {
    switch (grade.toUpperCase()) {
        case "A":
            console.log("Excellent");
            break;
        case "B":
            console.log("Good");
            break;
        case "C":
            console.log("Average");
            break;
        default:
            console.log("Try harder");
    }

    readline.question("Enter a fruit name: ", (fruit) => {
        switch (fruit.toLowerCase()) {
            case "banana":
                console.log("Yellow");
                break;
            case "apple":
                console.log("Red or Green");
                break;
            case "orange":
                console.log("Orange");
                break;
            case "grape":
                console.log("Purple or Green");
                break;
            case "lemon":
                console.log("Yellow");
                break;
            default:
                console.log("Color unknown");
        }
        readline.close();
    });
});
// ...existing code...