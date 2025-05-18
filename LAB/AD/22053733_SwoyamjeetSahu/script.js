function checkEvenOdd() {
    const input = document.getElementById("numberInput").value.trim();
    const result = document.getElementById("result");
  
    if (input === "" || isNaN(input)) {
      result.textContent = "Number not valid";
      result.className = "invalid";
      return;
    }
  
    const num = Number(input);
    if (num % 2 === 0) {
      result.textContent = `${num} is Even`;
      result.className = "even";
    } else {
      result.textContent = `${num} is Odd`;
      result.className = "odd";
    }
  }
  