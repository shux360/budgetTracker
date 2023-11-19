#pragma once
#include <iostream>
#include "DoublyLinkedList.h"
#include<fstream>
#include<string>

using namespace std;

DoublyLinkedList dll1;

class DisplayFunction {
public:
    int select_4, daysOfMonth = 0;
    void LogInData() {
        int select_1;

        cout << "Select an Option" << endl;
        cout << "1.Log In" << endl;
        cout << "2.Create a New Account" << endl;
        cout << "ttttttt";
        cin >> select_1;

        system("cls");
        switch (select_1)
        {
        case 1:
            Login();
            break;

        case 2:
            createNewAccount();
            break;

        default:
            system("cls");
            cout << "Enter a valid option" << endl;
            LogInData();
        }
    }
    void Login() {
        int count = 0;
        string username, password, uName, uPass;
        cout << "LOG IN" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        system("cls");

        ifstream read("records.txt");//ifstream is used to read the data from the file

        while (read >> uName >> uPass)//read is the object name
        {
            if (uName == username)
            {
                count = 1;
            }
        }
        read.close();

        if (count == 1)
        {
            cout << "Login Successfull!" << endl;
        }
        else
        {
            cout << "Login Failed" << endl;
            cout << "Please check your Username and Password" << endl;
            LogInData();
        }
    }
    void createNewAccount() {
        string uGoodName, uGender, uOccupation, uUsername, uPassword;
        int uAge, yr, select_3;
        system("cls");
        /*
        cout << "Enter your Good name: " << endl;
        cin >> uGoodName;
        cout << "Enter your age: " << endl;
        cin >> uAge;
        cout << "Enter your gender (Male/Female): " << endl;
        cin >> uGender;
        cout << "Enter your occupation: " << endl;
        cin >> uOccupation;
        */
        cout << "Select the number of the option that you want to select" << endl;
        cout << "Enter the year:";
        cin >> yr;
        cout << "Select the month that you want to enter the data" << endl;
        cout << "1.January" << endl;
        cout << "2.Feb" << endl;
        cout << "3.March" << endl;
        cout << "4.April" << endl;
        cout << "5.May" << endl;
        cout << "6.June" << endl;
        cout << "7.July" << endl;
        cout << "8.Aug" << endl;
        cout << "9.Sept" << endl;
        cout << "10.Oct" << endl;
        cout << "11.Nov" << endl;
        cout << "12.Dec" << endl;
        cin >> select_3;

        if (select_3 == 1 || select_3 == 3 || select_3 == 5 || select_3 == 7 || select_3 == 8 || select_3 == 10 || select_3 == 12)
            daysOfMonth = 31;
        else if (select_3 == 4 || select_3 == 6 || select_3 == 9 || select_3 == 11)
            daysOfMonth = 30;
        else if (select_3 == 2) {
            if ((yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0))
                daysOfMonth = 29;
            else
                daysOfMonth = 28;
        }
        dll1.CreateNodes(daysOfMonth);
        dll1.getdaysofmonth(daysOfMonth);
        /*out << "Enter a Username" << endl;
        cin >> uUsername;
        cout << "Enter Password" << endl;
        cin >> uPassword;*/

        //ofstream input("records.txt", ios::app);
        //input << uGoodName << " " << uAge << " " << uGender << " " << uOccupation << " " << uUsername << " " << uPassword << endl;
        //system("cls");
        cout << "Registration Successfull!" << endl;
        //LogInData();
        
        //return daysOfMonth;
       
    }

    void savingData() {
        double mon_Salary; //monthly salary of the user
        double save_Money; //how much money does user want to save
        double gen_Expenses; //basic expenses that user got
        double ot_Income; //other incomes instead of the salary    
        double daily_exp;
        //int daysOfMonth;
        string goal_description;
        char goal_response;

        cout << "What is your goal?(How much money do you want to save for a month): ";
        cin >> save_Money;
        cout << "Add a description about your goal: ";
        cin >> goal_description;

        cout << "Enter your current monthly salary: ";
        cin >> mon_Salary;
        cout << "General income of the month except monthly salary:";
        cin >> ot_Income;

        daily_exp = ((mon_Salary + ot_Income) - (save_Money)) / daysOfMonth;//changedddd
        system("cls");

        cout << "Amount of money you can spend for a day to achieve your goal: " << daily_exp << endl;

        cout << "Do you want to set the goal(y/n): ";
        cin >> goal_response;

        if (goal_response == 'y' || goal_response == 'Y') {

        }
        else if (goal_response == 'n' || goal_response == 'N') {
            InsertData();
        }
    } //user details

    void op_Data() { cout << "This is op_Data" << endl; } //taking users options to an action

    int ExpenseData() {

        cout << "Select the category that you want to enter the data" << endl;//editedddd
        cout << "1.Food" << endl;
        cout << "2.Transport" << endl;
        cout << "3.Bills" << endl;
        cout << "4.Clothing" << endl;
        cout << "5.Shopping" << endl;
        cout << "6.Education" << endl;
        cout << "7.Health" << endl;
        cout << "8.Social" << endl;
        cout << "9.Beauty" << endl;
        cout << "10.Other" << endl;
        cout << "11.Exit" << endl;
        cin >> select_4;

        return select_4;
    }

    void IncomeData() {
        cout << "1.Salary" << endl;
        cout << "2.Part time salary" << endl;
        cout << "3.Interests" << endl;
    }


  
    int select_2, select_3, Date, transport, food, Bills, Clothing, Shopping,
        Education, Health, Social, Beauty, Other;
    char choice;
    void InsertData() {
        transport = 0; food = 0;
        Bills = 0;
        Clothing = 0;
        Shopping = 0;
        Education = 0;
        Health = 0;
        Social = 0;
        Beauty = 0;
        Other = 0;
        //char choice;
        cout << "1.Insert Data" << endl;
        cout << "2.Delete Data" << endl;
        cout << "3.Find Data" << endl;
        cout << "4.Print Data" << endl;
        cout << "5.Set a Goal" << endl;
        cout << "6.Edit Data" << endl;
        cout << "7.Exit" << endl;

        cin >> select_2;

        switch (select_2) {
        case 1:
            do
            {
                cout << "INSERT DATA" << endl;
                int select;
                cout << "1 - Add data to a previous day" << endl;
                cout << "2 - Add data to a new date" << endl;
                cin >> select;
                if (select == 1)
                {
                    adddatatoprevnode();
                }
                else
                {
                    cout << "Enter the Date" << endl;
                    cin >> Date;
                    if (Date<1 || Date> daysOfMonth)
                    {
                        cout << "Invalid Date, Enter another date" << endl;

                    }
                }
            }
            while (Date<1 || Date>daysOfMonth);

            InsertDataTocategory();

            dll1.InsertAt(Date, food, transport, Bills, Clothing, Shopping, Education, Health, Social, Beauty, Other);
            break;
           
            /*cout << "Select the number of the option that you want to select" << endl;
            cout << "1.Expenses" << endl;
            cout << "2.Incomes" << endl;
            cin >> select_3;

            if (select_3 == 1) {
                ExpenseData();
                while (select_4 != 11) {
                    switch (select_4) {
                    case 1:
                        cout << "Enter the expense on food:";
                        cin >> food;
                        ExpenseData();
                        break;
                    case 2:
                        cout << "Enter the expense on transport:";
                        cin >> transport;
                        ExpenseData();
                        break;
                    case 3:
                        cout << "Enter the expense on bills:";
                        cin >> Bills;
                        ExpenseData();
                        break;
                    case 4:
                        cout << "Enter the expense on clothing:";
                        cin >> Clothing;
                        ExpenseData();
                        break;
                    case 5:
                        cout << "Enter the expense on shopping:";
                        cin >> Shopping;
                        ExpenseData();
                        break;
                    case 6:
                        cout << "Enter the expense on education:";
                        cin >> Education;
                        ExpenseData();
                        break;
                    case 7:
                        cout << "Enter the expense on health:";
                        cin >> Health;
                        ExpenseData();
                        break;
                    case 8:
                        cout << "Enter the expense on social:";
                        cin >> Social;
                        ExpenseData();
                        break;
                    case 9:
                        cout << "Enter the expense on beauty:";
                        cin >> Beauty;
                        ExpenseData();
                        break;
                    case 10:
                        cout << "Enter the expense on other:";
                        cin >> Other;
                        ExpenseData();
                        break;
                    case 11:
                        break;
                    default:
                        cout << "Enter a valid number!!" << endl;
                        ExpenseData();
                    }
                }
            }
            else if (select_3 == 2) {
                IncomeData();
            }
            else {
                cout << "Enter a valid number!!!" << endl;
            }

            dll1.InsertAt(Date, food, transport, Bills, Clothing, Shopping, Education, Health, Social, Beauty, Other);
            break;*/
        
        
            


        case 2:
            cout << "DELETE DATA" << endl;
            cout << "Enter the position you want to delete:";//Enter the day you want to delete or change
            InsertData();
            break;
        case 3:
            cout << "FIND DATA";
            cout << "Enter the day you want to find:";
            InsertData();
            break;
        case 4:
            int selectPrint;
            cout << "1 - Print data of all the previous days " << endl;
            cout << "2 - print data of a particular day" << endl;
            cin >> selectPrint;
            if (selectPrint == 1)
            {
                dll1.PrintDataofAll();
                //dll1.PrintData();
            }
            else if (selectPrint == 2)
            {
                int day;
                cout << "Enter the day that you want to print: ";
                cin >> day;
                dll1.PrintDataofoneDate(day);
            }
            //cout << "PRINT DATA" << endl;             
            break;
        case 5:
            cout << "SET A GOAL" << endl;
            savingData();
            break;
        case 6:
            cout << "EDIT DATA" << endl;
            Editdata();
            break;
        case 7:
            break;
        }
        cout << "Do you want to return to the menu?{y/n}" << endl;
        cin >> choice;
        if (choice == 'y') {
            InsertData();
        }
        else if (choice == 'n') {
            cout << "Have a nice day!!!" << endl;
        }
        else {
            cout << "Enter a valid input y for YES or n for NO" << endl;

        }
    }

    void InsertDataTocategory()
    {
        cout << "Select the number of the option that you want to select" << endl;
        cout << "1.Expenses" << endl;
        cout << "2.Incomes" << endl;
        cin >> select_3;

        if (select_3 == 1) {
           
            ExpenseData();
            while (select_4 != 11) {
                switch (select_4) {
                case 1:
                    cout << "Enter the expense on food:";
                    cin >> food;
                    ExpenseData();
                    break;
                case 2:
                    cout << "Enter the expense on transport:";
                    cin >> transport;
                    ExpenseData();
                    break;
                case 3:
                    cout << "Enter the expense on bills:";
                    cin >> Bills;
                    ExpenseData();
                    break;
                case 4:
                    cout << "Enter the expense on clothing:";
                    cin >> Clothing;
                    ExpenseData();
                    break;
                case 5:
                    cout << "Enter the expense on shopping:";
                    cin >> Shopping;
                    ExpenseData();
                    break;
                case 6:
                    cout << "Enter the expense on education:";
                    cin >> Education;
                    ExpenseData();
                    break;
                case 7:
                    cout << "Enter the expense on health:";
                    cin >> Health;
                    ExpenseData();
                    break;
                case 8:
                    cout << "Enter the expense on social:";
                    cin >> Social;
                    ExpenseData();
                    break;
                case 9:
                    cout << "Enter the expense on beauty:";
                    cin >> Beauty;
                    ExpenseData();
                    break;
                case 10:
                    cout << "Enter the expense on other:";
                    cin >> Other;
                    ExpenseData();
                    break;
                case 11:
                    break;
                default:
                    cout << "Enter a valid number!!" << endl;
                    ExpenseData();
                }
            }
        }
        else if (select_3 == 2) {
            IncomeData();
        }
        else {
            cout << "Enter a valid number!!!" << endl;
        }

        //dll1.InsertAt(Date, food, transport, Bills, Clothing, Shopping, Education, Health, Social, Beauty, Other);
        
    }

    void Editdata() 
    { 
       // int  transport , food , Bills , Clothing , Shopping ,
           //Education , Health , Social , Beauty , Other ,option;
        
        int editDataDate, option;
        cout << "1 - Do you want to add data to a previous day that you already entered before" << endl;
        cout << "2 - Do you want to add new data for a day that you entered before" << endl;
        cin >> option;
        if (option == 1)
        {

        }
        else if (option == 2)
        {
            cout << "Enter the day you want add new data: " << endl;
            cin >> editDataDate;
            InsertDataTocategory();
            dll1.InsertAt(editDataDate, food, transport, Bills, Clothing, Shopping, Education, Health, Social, Beauty, Other);
        }      
    }

    void adddatatoprevnode()
    {
        cout << "this is prevadd node"<<endl;
        int date;
        cout << "Enter the Date" << endl;
        cin >> date;
        ExpenseData();
        while (select_4 != 11) {
            switch (select_4) {
            case 1:
                dll1.AddDatatoPreviousNode("food", date);
                //cout << "Enter the expense on food:";
                //cin >> food;
                
                ExpenseData();
                break;
            case 2:
                dll1.AddDatatoPreviousNode("tran", date);
                //cout << "Enter the expense on transport:";
                //cin >> transport;              
                ExpenseData();
                break;
            case 3:
                dll1.AddDatatoPreviousNode("bil", date);
                //cout << "Enter the expense on bills:";
                //cin >> Bills;
                ExpenseData();
                break;
            case 4:
                dll1.AddDatatoPreviousNode("clo", date);
                //cout << "Enter the expense on clothing:";
                //cin >> Clothing;

                ExpenseData();
                break;
            case 5:
                dll1.AddDatatoPreviousNode("shop", date);
                //cout << "Enter the expense on shopping:";
                //cin >> Shopping;

                ExpenseData();
                break;
            case 6:
                dll1.AddDatatoPreviousNode("edu", date);
                //cout << "Enter the expense on education:";
                //cin >> Education;

                ExpenseData();
                break;
            case 7:
                dll1.AddDatatoPreviousNode("hea", date);
                //cout << "Enter the expense on health:";
                //cin >> Health;
               
                ExpenseData();
                break;
            case 8:
                dll1.AddDatatoPreviousNode("soci", date);
                //cout << "Enter the expense on social:";
                //cin >> Social;
                
                ExpenseData();
                break;
            case 9:
                dll1.AddDatatoPreviousNode("beau", date);
                //cout << "Enter the expense on beauty:";
                //cin >> Beauty;
                
                ExpenseData();
                break;
            case 10:
                dll1.AddDatatoPreviousNode("othr", date);
                //cout << "Enter the expense on other:";
                //cin >> Other;
                
                ExpenseData();
                break;
            case 11:
                break;
            default:
                cout << "Enter a valid number!!" << endl;
                ExpenseData();
            }
       
        }
        cout << "Do you want to return to the menu?{y/n}" << endl;
        cin >> choice;
        if (choice == 'y') {
            InsertData();
        }
        else if (choice == 'n') {
            cout << "Have a nice day!!!" << endl;
        }
        else {
            cout << "Enter a valid input y for YES or n for NO" << endl;
        }
    }
    void DeleteData() { cout << "This is DeleteData" << endl; }
    void FindData() { cout << "This is FindData" << endl; }
    void printdata() { cout << "This is PrintData" << endl; }


};
