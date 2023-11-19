#pragma once
#include <iostream>
#include "DoublyLinkedList.h"
#include "billReminder.h"
#include<fstream>
#include<string>
#include<queue>


using namespace std;

DoublyLinkedList dll1;
BillManager bm;

class DisplayFunction {
public:
    int select_4;
	void LogInData(){ 
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
	void Login(){ 
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
	void createNewAccount(){ 
        string uGoodName, uGender, uOccupation, uUsername, uPassword;
        int uAge;
        system("cls");

        cout << "Enter your Good name: " << endl;
        cin >> uGoodName;
        cout << "Enter your age: " << endl;
        cin >> uAge;
        cout << "Enter your gender (Male/Female): " << endl;
        cin >> uGender;
        cout << "Enter your occupation: " << endl;
        cin >> uOccupation;
        cout << "Enter a Username" << endl;
        cin >> uUsername;
        cout << "Enter Password" << endl;
        cin >> uPassword;

        ofstream input("records.txt", ios::app);
        input << uGoodName << " " << uAge << " " << uGender << " " << uOccupation << " " << uUsername << " " << uPassword << endl;
        system("cls");
        cout << "Registration Successfull!" << endl;
        LogInData();
    }

	void savingData(){
        double mon_Salary; //monthly salary of the user
        double save_Money; //how much money does user want to save
        double gen_Expenses; //basic expenses that user got
        double ot_Income; //other incomes instead of the salary    
        double daily_exp;
        int daysOfMonth;
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

        daily_exp = ((mon_Salary + ot_Income) - (save_Money)) / 30; //what is the meaning of gen expenses 
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
	
	void op_Data(){ cout << "This is op_Data" << endl; } //taking users options to an action

    int ExpenseData(){
        
        cout << "Select the number of the option that you want to select" << endl;
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

    void IncomeData(){
        cout << "1.Salary" << endl;
        cout << "2.Part time salary" << endl;
        cout << "3.Interests" << endl;
    }

	void InsertData(){
        int select_2,select_3,Date,transport = 0,food = 0,Bills = 0,Clothing = 0,Shopping = 0,
            Education = 0,Health = 0,Social = 0,Beauty = 0,Other = 0;
        char choice;
        cout << "1.Insert Data" << endl;
        cout << "2.Delete Data" << endl;
        cout << "3.Find Data" << endl;
        cout << "4.Print Data" << endl;//Modify categories seperately
        cout << "5.Set a Goal" << endl;
        cout << "6.Add a reminder" << endl;
        cout << "7.Exit" << endl;
        
        cin >> select_2;

        switch (select_2) {
        case 1:
            cout << "INSERT DATA" << endl; 
            cout << "Enter the Date" << endl;
            cin >> Date;
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
                        cout << "Enter a valid number!!"<<endl;
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
            break;
            

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
            cout << "PRINT DATA" <<endl;
            dll1.PrintData();
            break;
        case 5:
            cout << "SET A GOAL" << endl;
            savingData();
            break;
        case 6:
            cout << "ADD A REMINDER" << endl;
            cout << "By using this option you can add a reminder on your pay bills" << endl;
            billingReminder();
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
	void DeleteData(){ cout << "This is DeleteData" << endl; }
	void FindData(){ cout << "This is FindData" << endl; }
	void printdata(){ cout << "This is PrintData" << endl; }
    void billingReminder() {
        bm.billReminder();
    }

};
