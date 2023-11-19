#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

class Bill {
public:
    string name;
    double amount;
    time_t dueDate;

    // Default constructor
    Bill() : name(""), amount(0.0), dueDate(0) {}

    Bill(const string& n, double a, time_t d) : name(n), amount(a), dueDate(d) {}
};

class CompareBills {
public:
    bool operator()(const Bill& lhs, const Bill& rhs) const {
        return lhs.dueDate > rhs.dueDate; // Min heap based on due date
    }
};

class BillManager {
private:
    static const int MAX_BILLS = 100;
    Bill bills[MAX_BILLS];
    int size;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (CompareBills()(bills[parent], bills[index])) {
                break;
            }
            swap(bills[parent], bills[index]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        while (2 * index + 1 < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = leftChild;
            if (rightChild < size && CompareBills()(bills[rightChild], bills[leftChild])) {
                smallest = rightChild;
            }
            if (CompareBills()(bills[index], bills[smallest])) {
                break;
            }
            swap(bills[index], bills[smallest]);
            index = smallest;
        }
    }

public:
    BillManager() : size(0) {}

    void checkUpcomingBills() {
        cout << "Upcoming Bills:\n";

        for (int i = 0; i < size; ++i) {
            const Bill& bill = bills[i];

            // Calculate days remaining for the due date
            time_t currentTime = time(nullptr);
            double secondsRemaining = bill.dueDate - currentTime;
            double daysRemaining = ceil(secondsRemaining / (60 * 60 * 24));

            // Convert due date to YYYY-MM-DD format
            tm* dueDateStruct = localtime(&bill.dueDate);
            char buffer[11];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", dueDateStruct);

            cout << "Name: " << bill.name << endl;
            cout << "Amount: " << bill.amount << endl;
            cout << "Due Date: " << buffer << endl;
            cout << "Days Remaining: " << daysRemaining << " days" << endl;
        }
    }

    void addBill() {
        if (size < MAX_BILLS) {
            // Get bill information from the user
            string name;
            double amount;
            string dueDateStr;

            cout << "Enter bill information\n";
            cout << "Name of the bill: ";
            cin >> name;

            cout << "Amount: ";
            cin >> amount;

            cout << "Due Date (YYYY-MM-DD): ";
            cin >> dueDateStr;

            // Convert user-provided due date to timestamp
            tm dueDateStruct = {};
            istringstream(dueDateStr) >> get_time(&dueDateStruct, "%Y-%m-%d");
            time_t dueDate = mktime(&dueDateStruct);

            // Add the user-provided bill to the array and maintain the heap property
            bills[size] = Bill(name, amount, dueDate);
            heapifyUp(size);
            size++;
        }
        else {
            cout << "Cannot add more bills. Maximum limit reached.\n";
        }
    }

    void displayQueue() {
        checkUpcomingBills();
    }

    void billReminder() {
        BillManager billManager;
        int choice;

        do {
            cout << "1. Add Bill Reminder\n";
            cout << "2. Display Existing Bill Reminders\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                billManager.addBill();
                break;

            case 2:
                billManager.displayQueue();
                break;

            case 3:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
            }

        } while (choice != 3);
    }
};

