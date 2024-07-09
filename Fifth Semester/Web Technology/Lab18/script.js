$(document).ready(function () {
  // Smooth scrolling for navigation links
  $("nav ul li a").click(function (event) {
    event.preventDefault();
    $("html, body").animate(
      {
        scrollTop: $($(this).attr("href")).offset().top,
      },
      500
    );
  });

  // Form submission
  $("#contactForm").submit(function (event) {
    event.preventDefault();
    const name = $("#name").val();
    const email = $("#email").val();
    const message = $("#message").val();

    alert(`Thank you, ${name}. We have received your message: "${message}"`);

    // Clear the form
    $(this).trigger("reset");
  });
});
