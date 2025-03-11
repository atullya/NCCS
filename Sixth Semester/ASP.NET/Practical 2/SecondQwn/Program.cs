/*	Write a console program (ADO.net) to create a table tbl_registration that have fields (id int primary key, username, password, repassword, gender, course and country). After this perform the following operation
•	Insert any 5 data into tbl_registration. All the required input should be taken from user
•	Display all the record of database table
•	Update the name and course of a person to data given by user according to id given by user
•	Delete the record of person whose id is given by user
•	Display all the record of person who are male and also from country Nepal
*/
using System.Data;
using System.Data.SqlClient;
using ADO;
class Program
{
    static void Main(string[] args)
    {
       CRUD c1=new CRUD();
        c1.CreateTable();
        c1.InsertRecord();
        c1.UpdateRecord();
        c1.DeleteRecord();
        c1.DisplayMaleUsersFromNepal();

    }
}
