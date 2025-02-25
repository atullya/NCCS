using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace StateManagement.Controllers
{
    public class StateController : Controller
    {
        public IActionResult SetSession()
        {
            HttpContext.Session.SetString("User", "Atullya");
            TempData["Message"] = "Session value has been set!";
            return RedirectToAction("GetSession"); 
        }

        public IActionResult GetSession()
        {
            string user = HttpContext.Session.GetString("User"); 
            ViewBag.User = user ?? "No session found!";
            ViewBag.Message = TempData["Message"];

            return View("SessionView"); 
        }
        public IActionResult TempDataDemo()
        {
         
            ViewData["data1"] = "this is data from view data (Atullya)";
            ViewBag.data2 = "this is data from view bag (CSIT)"; 
            TempData["data3"] = "data from temp data (Nagarjun-4, Bafal)"; 
            return View();
        }
    }
}
