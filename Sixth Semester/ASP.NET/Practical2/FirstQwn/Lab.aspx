//Create a web form that contains two label that display Enter first number and enter second number, two text box for taking an input, third text box for output and three button add, subtract and find prime. Add proper validation like text box should not be empty, value of first field should be greater than value of second field. If add button is clicked display the addition of two number given in textboxes, if subtract button is clicked display the subtraction of two number given in textboxes and if findprime is clicked then display the prime number from first value to second value given in textboxes. 

<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Lab2.aspx.cs" Inherits="project.Lab2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
     <form id="form1" runat="server">
        <div class="container">
            <h1>Number Operations</h1>
            <label for="firstNumber">Enter first number:</label>
            <asp:TextBox ID="firstNumber" runat="server"></asp:TextBox>
            <br />
            <label for="secondNumber">Enter second number:</label>
            <asp:TextBox ID="secondNumber" runat="server"></asp:TextBox>
            <br />
            <asp:Button ID="btnAdd" runat="server" Text="Add" OnClick="btnAdd_Click" />
            <asp:Button ID="btnSubtract" runat="server" Text="Subtract" OnClick="btnSubtract_Click" />
            <asp:Button ID="btnFindPrime" runat="server" Text="Find Prime" OnClick="btnFindPrime_Click" />
            <br />
            <label for="output">Output:</label>
            <asp:TextBox ID="output" runat="server" ReadOnly="true"></asp:TextBox>
        </div>
    </form>
</body>
</html>
