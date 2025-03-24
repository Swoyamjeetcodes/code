// #  JavaScript Display Possibilities
// ## JavaScript can "display" data in different ways:
// - Writing into an HTML element, using innerHTML.
// - Writing into the HTML output using document.write().
// - Writing into an alert box, using window.alert().
// - Writing into the browser console, using console.log().

// window.alert("This is an alert")
// window.alert("i like pizza");
// alert("pizza");
console.log(`Hello`);
console.log(`Pizza`);
document.getElementById("p1").style.display = "none"; //hides the paragraph
document.getElementById("p2").textContent = `hello`;
document.getElementById("p3").innerHTML = 5+6;
document.write(6+5); // The document.write() method should only be used for testing.

// The var keyword was used in all JavaScript code from 1995 to 2015.
// The let and const keywords were added to JavaScript in 2015.
// The var keyword should only be used in code written for older browsers.
// const values cant be changed.
// let values can be changed.
let x;
x=100;
console.log(x);
console.log(`you are ${x} years old`);
console.log(typeof x);

  {
    let y = 2;
  }
  // y can NOT be used here
  {
    var z = 2;
  }
  // z CAN be used here