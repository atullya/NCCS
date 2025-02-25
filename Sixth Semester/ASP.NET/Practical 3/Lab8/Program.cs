using System.Security.Claims;
using Microsoft.AspNetCore.Authentication.Cookies;//import cookies
var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddControllersWithViews();
//adding authentication mechanism:cookie
builder.Services.AddAuthentication(CookieAuthenticationDefaults.AuthenticationScheme)
    .AddCookie(x =>
    {
        x.LoginPath = "/Home/Login"; // go to homecontoller and login
    });
builder.Services.AddAuthorization(options =>
{
    options.AddPolicy("CanEditPolicy", policy =>
        policy.RequireClaim("CanEdit", "true"));

    options.AddPolicy("IsAtullya", policy =>
        policy.RequireClaim(ClaimTypes.Name, "atullya"));
});
var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
    app.UseHsts();
}

app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();

app.UseAuthorization();

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}");

app.Run();
