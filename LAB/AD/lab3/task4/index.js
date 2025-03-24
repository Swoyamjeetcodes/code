document.getElementById("submitForm").addEventListener("click", function() {
    let isValid = true;

    // Clear previous errors
    document.querySelectorAll(".error").forEach(error => error.textContent = "");

    // Validate Name
    const name = document.getElementById("name").value.trim();
    if (!/^\w+ \w+$/.test(name)) {
        isValid = false;
        document.getElementById("nameError").textContent = "Please enter a valid first and last name.";
    }

    // Validate Address
    const address = document.getElementById("address").value.trim();
    if (!/\w+, \w+, \w+, \d{5}/.test(address)) {
        isValid = false;
        document.getElementById("addressError").textContent = "Please enter a valid address with street, city, state, and zip code.";
    }

    // Validate Phone
    const phone = document.getElementById("phone").value.trim();
    if (!/^\d{3}-\d{3}-\d{4}$/.test(phone)) {
        isValid = false;
        document.getElementById("phoneError").textContent = "Please enter a valid 10-digit phone number in the format 123-456-7890.";
    }

    // Validate Email
    const email = document.getElementById("email").value.trim();
    if (!/^\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,3}$/.test(email)) {
        isValid = false;
        document.getElementById("emailError").textContent = "Please enter a valid email address.";
    }

    // Validate Birth Date
    const birthDate = new Date(document.getElementById("birthDate").value);
    const today = new Date();
    if (!birthDate || birthDate >= today) {
        isValid = false;
        document.getElementById("birthDateError").textContent = "Please enter a valid birth date.";
    }

    // Validate Message
    const message = document.getElementById("message").value.trim();
    if (!message) {
        isValid = false;
        document.getElementById("messageError").textContent = "Message cannot be blank.";
    }

    // Validate Captcha
    const captcha = document.getElementById("captcha").value.trim();
    if (captcha !== "8") {
        isValid = false;
        document.getElementById("captchaError").textContent = "Incorrect answer to the security question.";
    }

    if (isValid) {
        const confirmDetails = `
            <strong>Name:</strong> ${name}<br>
            <strong>Address:</strong> ${address}<br>
            <strong>Phone:</strong> ${phone}<br>
            <strong>Email:</strong> ${email}<br>
            <strong>Birth Date:</strong> ${birthDate.toISOString().split("T")[0]}<br>
            <strong>Message:</strong> ${message}<br>
        `;
        document.getElementById("confirmDetails").innerHTML = confirmDetails;
        document.getElementById("confirmSection").style.display = "block";
    }
});

document.getElementById("editForm").addEventListener("click", function() {
    document.getElementById("confirmSection").style.display = "none";
});

document.getElementById("finalSubmit").addEventListener("click", function() {
    alert("Thank you! Your information has been confirmed.");
});