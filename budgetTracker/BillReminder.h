#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>

using namespace std;

struct Bill {
    string name;
    double amount;
    time_t dueDate;
};

class BillManager {
private:
    static const int MAX_BILLS = 100;
    Bill bills[MAX_BILLS];
    int size;

public:
    BillManager() : size(0) {}

    void checkUpcomingBills() {
        time_t currentTime = time(nullptr);

        cout << "==============================================" << endl;
        cout << "|----------------UPCOMING BILLS--------------|" << endl;
        cout << "==============================================" << endl;
        cout << " " << endl;

        for (int i = 0; i < size; ++i) {
            const Bill& bill = bills[i];

            // Calculate days remaining for the due date
            double secondsRemaining = bill.dueDate - currentTime;
            double daysRemaining = ceil(secondsRemaining / (60 * 60 * 24));

            // Convert due date to YYYY-MM-DD format
            tm* dueDateStruct = localtime(&bill.dueDate);
            char buffer[11];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", dueDateStruct);

            cout << "-------------------------------------------" << endl;
            cout << "|BILL NO        : " << i + 1 << endl;
            cout << "-------------------------------------------" << endl;
            cout << "|Name          : " << bill.name << endl;
            cout << "-------------------------------------------" << endl;
            cout << "|Amount        : " << bill.amount << endl;
            cout << "-------------------------------------------" << endl;
            cout << "|Due Date      : " << buffer << endl;
            cout << "-------------------------------------------" << endl;
            cout << "|Days Remaining: " << daysRemaining << endl;
            cout << "-------------------------------------------" << endl;
            cout << "" << endl;
            cout << "" << endl;
        }
    }

    void addBill() {
        if (size < MAX_BILLS) {
            // Get bill information from the user
            Bill newBill;

            cout << "======================================================" << endl;
            cout << "|----------------ENTER BILL INFORMATION--------------|" << endl;
            cout << "======================================================" << endl;
            cout << "" << endl;
            cout << "Name of the bill: ";
            cin >> newBill.name;

            cout << "Amount: ";
            cin >> newBill.amount;

            cout << "Due Date (YYYY-MM-DD): ";
            string dueDateStr;
            cin >> dueDateStr;
            system("cls");

            // Convert user-provided due date to timestamp
            tm dueDateStruct = {};
            sscanf(dueDateStr.c_str(), "%d-%d-%d", &dueDateStruct.tm_year, &dueDateStruct.tm_mon, &dueDateStruct.tm_mday);
            dueDateStruct.tm_year -= 1900;
            dueDateStruct.tm_mon -= 1;
            newBill.dueDate = mktime(&dueDateStruct);

            // Add the user-provided bill to the array
            bills[size] = newBill;
            size++;

            // Sort bills based on dueDate in ascending order (bubble sort algorithm)
            for (int i = 0; i < size - 1; ++i) {
                for (int j = i + 1; j < size; ++j) {
                    if (bills[i].dueDate > bills[j].dueDate) {
                        swap(bills[i], bills[j]);
                    }
                }
            }
        }
        else {
            cout << "Cannot add more bills. Maximum limit reached.\n";
        }
    }

    void displayQueue() {
        checkUpcomingBills();
    }

    void billReminder() {
        int choice;

        do {
            cout << "----------------------------------------------" << endl;
            cout << "| 1\t|Add Bill Reminder                   |" << endl;
            cout << "| 2\t|Display Existing Bill Reminders     |" << endl;
            cout << "| 3\t|Exit                                |" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "|Insert an option (1,2 or 3)                 |" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            system("cls");

            switch (choice) {
            case 1:
                addBill();
                break;

            case 2:
                displayQueue();
                break;

            case 3:
                cout << "Exiting the program.\n";
                system("cls");
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
            }

        } while (choice != 3);
    }
};
