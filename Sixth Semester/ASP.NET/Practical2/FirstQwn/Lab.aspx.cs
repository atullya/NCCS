using System;
using System.Collections.Generic;
using System.Web.UI;

namespace project
{
    public partial class Lab2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
        }

        private bool ValidateInputs(out int firstNum, out int secondNum, string operation)
        {
            firstNum = 0;
            secondNum = 0;

            if (string.IsNullOrWhiteSpace(firstNumber.Text) || string.IsNullOrWhiteSpace(secondNumber.Text))
            {
                output.Text = "Both fields are required.";
                return false;
            }

            if (!int.TryParse(firstNumber.Text, out firstNum) || !int.TryParse(secondNumber.Text, out secondNum))
            {
                output.Text = "Please enter valid numbers.";
                return false;
            }

            if (operation == "Add" || operation == "Subtract")
            {
                if (firstNum <= secondNum)
                {
                    output.Text = "First number must be greater than second number.";
                    return false;
                }
            }
            else if (operation == "FindPrime")
            {
                if (firstNum > secondNum)
                {
                    output.Text = "First number must be less than or equal to second number.";
                    return false;
                }
            }

            return true;
        }

        protected void btnAdd_Click(object sender, EventArgs e)
        {
            if (ValidateInputs(out int firstNum, out int secondNum, "Add"))
            {
                int result = firstNum + secondNum;
                output.Text = result.ToString();
            }
        }

        protected void btnSubtract_Click(object sender, EventArgs e)
        {
            if (ValidateInputs(out int firstNum, out int secondNum, "Subtract"))
            {
                int result = firstNum - secondNum;
                output.Text = result.ToString();
            }
        }

        protected void btnFindPrime_Click(object sender, EventArgs e)
        {
            if (ValidateInputs(out int firstNum, out int secondNum, "FindPrime"))
            {
                List<int> primes = FindPrimesInRange(firstNum, secondNum);
                output.Text = string.Join(", ", primes);
            }
        }

        private List<int> FindPrimesInRange(int start, int end)
        {
            List<int> primes = new List<int>();
            for (int num = start; num <= end; num++)
            {
                if (IsPrime(num))
                {
                    primes.Add(num);
                }
            }
            return primes;
        }

        private bool IsPrime(int number)
        {
            if (number <= 1) return false; // 0 and 1 are not prime numbers
            if (number == 2) return true; // 2 is the only even prime number
            if (number % 2 == 0) return false; // other even numbers are not prime

            for (int i = 3; i <= Math.Sqrt(number); i += 2)
            {
                if (number % i == 0)
                {
                    return false; // found a divisor, not prime
                }
            }
            return true; // no divisors found, it's prime
        }
    }
}
