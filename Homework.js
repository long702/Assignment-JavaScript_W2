// 1. Define a number and check divisibility
let number = 15;

if (number % 3 === 0 && number % 5 === 0) {
  console.log(`${number} is divisible by both 3 and 5.`);
} else if (number % 3 === 0) {
  console.log(`${number} is divisible only by 3.`);
} else if (number % 5 === 0) {
  console.log(`${number} is divisible only by 5.`);
} else {
  console.log(`${number} is not divisible by 3 or 5.`);
}

// 2. Define a day string and check weekday/weekend
let day = "Sunday";

if (day === "Saturday" || day === "Sunday") {
  console.log(`${day} is a weekend.`);
} else {
  console.log(`${day} is a weekday.`);
}

// 3. Define a traffic light color and print action
let lightColor = "Red";

if (lightColor === "Red") {
  console.log("Stop");
} else if (lightColor === "Green") {
  console.log("Go");
} else if (lightColor === "Yellow") {
  console.log("Slow down");
} else {
  console.log("Invalid color");
}





