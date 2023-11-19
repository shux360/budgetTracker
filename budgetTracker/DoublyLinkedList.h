#pragma once
#include <iostream>
#include "DisplayFunction.h"
#include "Node.h"

using namespace std;

//DisplayFunction df;
class DoublyLinkedList {
private:
	Node* head;
	Node* tail;
	int size;
public:
	int d = 0, vTransport = 0, vFood = 0, vBills = 0, vClothing = 0, vShopping = 0,
		vEducation = 0, vHealth = 0, vSocial = 0, vBeauty = 0, vOther = 0;

	DoublyLinkedList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void CreateNodes(int daysOfmonth) {
		for (int i = 0; i < daysOfmonth; i++) {
			d = i+1;
			Node* temp = new Node(d, vFood, vTransport, vBills, vClothing, vShopping, vEducation, vHealth, vSocial, vBeauty, vOther);	
			if (head == NULL) {
				head = temp;
				tail = temp;
				size++;
			}
			else {
				tail->next = temp;
				temp->prev = tail;
				tail = temp;
				tail->next = NULL;
				size++;
			}
		}
		
	}
	void InsertFirst(int d, int vFood, int vTransport, int vBills, int vClothing, int vShopping, int vEducation, int vHealth, int vSocial, int vBeauty, int vOther) {
		Node* temp = new Node(d, vFood, vTransport, vBills, vClothing, vShopping, vEducation, vHealth, vSocial, vBeauty, vOther);
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			temp->next = head->next;
			(head->next)->prev = temp;
			head = temp;
			size++;
		}
	}
	void InsertLast(int d, int vFood, int vTransport, int vBills, int vClothing, int vShopping, int vEducation, int vHealth, int vSocial, int vBeauty, int vOther) {
		Node* temp = new Node(d, vFood, vTransport, vBills, vClothing, vShopping, vEducation, vHealth, vSocial, vBeauty, vOther);
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			/*tail->next = temp;
			temp->prev = tail;
			tail = temp;
			tail->next = NULL;*/
			//size++;
			temp->next = tail;
			temp->prev = tail->prev;
			(tail->prev)->next = temp;
			tail->prev = temp;
			tail = temp;
			tail->next = NULL;
			//size++;
		}
	}
	void InsertAt(int d, int vFood, int vTransport, int vBills, int vClothing, int vShopping, int vEducation, int vHealth, int vSocial, int vBeauty, int vOther) {


		/*if (d < 1 || d > size) {
			cout << "Invalid Date" << endl;
		}*/
		if (d == 1) {
			InsertFirst(d, vFood, vTransport, vBills, vClothing, vShopping, vEducation, vHealth, vSocial, vBeauty, vOther);
			
		}
		else if (d == size) {
			InsertLast(d, vFood, vTransport, vBills, vClothing, vShopping, vEducation, vHealth, vSocial, vBeauty, vOther);

		}
		else {
			Node* temp = new Node(d, vFood, vTransport, vBills, vClothing, vShopping, vEducation, vHealth, vSocial, vBeauty, vOther);
			Node* current = head;
			for (int i = 0; i < d - 2; i++) {
				current = current->next;
			}
			temp->next = (current->next)->next;
			temp->prev = current;
			current->next = temp;
			(temp->next)->prev = temp;
			size++;
			Node* currentNew = head;
			for (int i = 0; i < size; i++)
			{
				currentNew->date = i + 1;
				currentNew = currentNew->next;
			}

		}
	}

	void DeleteFirst() {
		if (head == NULL)
			cout << "List is empty" << endl;

		else {
			Node* temp = head;
			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				head = head->next;
				head->prev = NULL;
				delete temp;
				size--;
			}
		}
	}
	void DeleteLast() {
		if (head == NULL)
			cout << "List is empty" << endl;

		else {
			Node* temp = tail;
			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {

				tail = tail->prev;
				tail->next = NULL;
				delete temp;
				size--;
			}

		}
	}

	void DeleteAt(int d) {
		if (d < 1 || d > 31) {
			cout << "Invalid date" << endl;
		}
		else {
			if (d == 1) {
				DeleteFirst();
			}
			else if (d == size) {
				DeleteLast();
			}
			else {
				Node* current = head;
				for (int i = 0; i < d; i++) {
					current = current->next;
				}
				Node* temp = current;
				(current->prev)->next = temp->next;
				(current->next)->prev = temp->prev;
				delete temp;
				size--;
				Node* currentNew = head;
				for (int i = 0; i < size; i++)
				{
					currentNew->date = i + 1;
					currentNew = currentNew->next;
				}
			}
		}
	}
	void AddDatatoPreviousNode(string select, int dy)
	{
		Node* current = head;
		for (int i = 0; i < dy - 1; i++) {
			current = current->next;
		}
		char option;
		int fd, trans, bill, cloth, shop, ed, heal, socio, beau, oth;
		if (select == "food")
		{
			if (current->Food != 0)
			{
				cout << "You already entered expenses for food category, the amount you entered is: ";
				cout << current->Food << endl;
				cout << "do you want to change the exsisting amount(y / n) ? ";
				cin >> option;
				if (option == 'y')
				{
					cout << "Enter the new amount for food: ";
					cin >> fd;
					current->Food = fd;
				}
				else if (option == 'n')
				{
				}
				else
				{
					cout << "Enter a valid option" << endl;
				}
			}
			else if (current->Food == 0)
			{
				cout << "Enter the expense on food:";
				cin >> fd;
				current->Food = fd;
			}
		}
		if (select == "tran")
		{
			if (current->Transport != 0)
			{
				cout << "You already entered expenses for transport category, do you want to change the exsisting amount(y/n)?" << endl;
				cin >> option;
				if (option == 'y')
				{
					cout << "Enter the new amount for transport: ";
					cin >> trans;
					current->Transport = trans;
				}
				else if (option == 'n')
				{
				}
				else
				{
					cout << "Enter a valid option" << endl;
				}
			}
			else if (current->Transport == 0)
			{
				cout << "Enter the expense on transport:";
				cin >> trans;
				current->Transport = trans;
			}
		}
		if (select == "bil")
		{
			if (current->Bills != 0)
			{
				cout << "You already entered expenses for bills category, do you want to change the exsisting amount(y/n)?" << endl;
				cin >> option;
				if (option == 'y')
				{
					cout << "Enter the new amount for bills: ";
					cin >> bill;
					current->Bills = bill;
				}
				else if (option == 'n')
				{
				}
				else
				{
					cout << "Enter a valid option" << endl;
				}
			}
			else if (current->Bills == 0)
			{
				cout << "Enter the expense on bills:";
				cin >> bill;
				current->Bills = bill;
			}
		}
		if (select == "clo")
		{
			if (current->Clothing != 0)
			{
				cout << "You already entered expenses for clothing category, do you want to change the exsisting amount(y/n)?" << endl;
				cin >> option;
				if (option == 'y')
				{
					cout << "Enter the new amount for clothing: ";
					cin >> cloth;
					current->Clothing = cloth;
				}
				else if (option == 'n')
				{
				}
				else
				{
					cout << "Enter a valid option" << endl;
				}
			}
			else if (current->Clothing == 0)
			{
				cout << "Enter the expense on clothing:";
				cin >> cloth;
				current->Clothing = cloth;
			}
		}
		if (select == "shop")
		{
			if (current->Shopping != 0)
			{
				cout << "You already entered expenses for shopping category, do you want to change the exsisting amount(y/n)?" << endl;
				cin >> option;
				if (option == 'y')
				{
					cout << "Enter the new amount for shopping: ";
					cin >> shop;
					current->Shopping = shop;
				}
				else if (option == 'n')
				{
				}
				else
				{
					cout << "Enter a valid option" << endl;
				}
			}
			else if (current->Shopping == 0)
			{
				cout << "Enter the expense on shoping:";
				cin >> shop;
				current->Shopping = shop;
			}
		}
		if (select == "edu")
		{
			if (current->Education != 0)
			{
				cout << "You already entered expenses for education category, do you want to change the exsisting amount(y/n)?" << endl;
				cin >> option;
				if (option == 'y')
				{
					cout << "Enter the new amount for education: ";
					cin >> ed;
					current->Education = ed;
				}
				else if (option == 'n')
				{
				}
				else
				{
					cout << "Enter a valid option" << endl;
				}
			}
			else if (current->Education == 0)
			{
				cout << "Enter the expense on education:";
				cin >> ed;
				current->Education = ed;
			}
		}
		if (select == "hea")
		{
			if (current->Health != 0)
			{
				cout << "You already entered expenses for health category, do you want to change the exsisting amount(y/n)?" << endl;
				cin >> option;
				if (option == 'y')
				{
					cout << "Enter the new amount for health: ";
					cin >> heal;
					current->Health = heal;
				}
				else if (option == 'n')
				{
				}
				else
				{
					cout << "Enter a valid option" << endl;
				}
			}
			else if (current->Health == 0)
			{
				cout << "Enter the expense on health:";
				cin >> heal;
				current->Health = heal;
			}
		}
		if (select == "soci")
		{
			if (current->Social != 0)
			{
				cout << "You already entered expenses for social category, do you want to change the exsisting amount(y/n)?" << endl;
				cin >> option;
				if (option == 'y')
				{
					cout << "Enter the new amount for social: ";
					cin >> socio;
					current->Social = socio;
				}
				else if (option == 'n')
				{
				}
				else
				{
					cout << "Enter a valid option" << endl;
				}
			}
			else if (current->Social == 0)
			{
				cout << "Enter the expense on social:";
				cin >> socio;
				current->Social = socio;
			}
		}
		if (select == "beau")
		{
			if (current->Beauty != 0)
			{
				cout << "You already entered expenses for beauty category, do you want to change the exsisting amount(y/n)?" << endl;
				cin >> option;
				if (option == 'y')
				{
					cout << "Enter the new amount for beauty: ";
					cin >> beau;
					current->Beauty = beau;
				}
				else if (option == 'n')
				{
				}
				else
				{
					cout << "Enter a valid option" << endl;
				}
			}
			else if (current->Beauty == 0)
			{
				cout << "Enter the expense on beauty:";
				cin >> beau;
				current->Beauty = beau;
			}
		}
		if (select == "othr")
		{
			if (current->Other != 0)
			{
				cout << "You already entered expenses for other category, do you want to change the exsisting amount(y/n)?" << endl;
				cin >> option;
				if (option == 'y')
				{
					cout << "Enter the new amount for other: ";
					cin >> oth;
					current->Other = oth;
				}
				else if (option == 'n')
				{
				}
				else
				{
					cout << "Enter a valid option" << endl;
				}
			}
			else if (current->Other == 0)
			{
				cout << "Enter the expense on other:";
				cin >> oth;
				current->Other = oth;
			}
		}

	}

	void FindData() { cout << "This is FindData" << endl; }

	void PrintDataofAll() {
		Node* current = head;
		for (int i = 0; i < size; i++)
		{
			if (current->Food != 0 || current->Transport != 0 || current->Bills != 0 || current->Clothing != 0 || current->Shopping != 0 || current->Education != 0 || current->Health != 0 || current->Social != 0 || current->Beauty != 0 || current->Other != 0)
			{
				cout << "PRINT DATA" << endl;
				cout << "Expenses for the Day " << current->date << endl;
				cout << "Food:" << current->Food << endl;
				cout << "Transport:" << current->Transport << endl;
				cout << "Bills:" << current->Bills << endl;
				cout << "Clothing:" << current->Clothing << endl;
				cout << "Shopping:" << current->Shopping << endl;
				cout << "Education:" << current->Education << endl;
				cout << "Health:" << current->Health << endl;
				cout << "Social:" << current->Social << endl;
				cout << "Beauty:" << current->Beauty << endl;
				cout << "Other:" << current->Other << endl;
				cout << "Total expense of the day:" << (current->Food + current->Transport + current->Bills + current->Clothing + current->Shopping +
					current->Education + current->Health + current->Social + current->Beauty + current->Other) << endl;
				cout << " " << endl;
			}

			current = current->next;
		}
		cout << endl;
		//cout << "" << size << endl;
	}

	void PrintDataofoneDate(int Dy) {
		Node* current = head;
		for (int i = 0; i < Dy - 1; i++)
		{
			current = current->next;
		}
		cout << "PRINT DATA" << endl;
		cout << "Expenses for the Day " << current->date << endl;
		cout << "Food:" << current->Food << endl;
		cout << "Transport:" << current->Transport << endl;
		cout << "Bills:" << current->Bills << endl;
		cout << "Clothing:" << current->Clothing << endl;
		cout << "Shopping:" << current->Shopping << endl;
		cout << "Education:" << current->Education << endl;
		cout << "Health:" << current->Health << endl;
		cout << "Social:" << current->Social << endl;
		cout << "Beauty:" << current->Beauty << endl;
		cout << "Other:" << current->Other << endl;
		cout << "Total expense of the day:" << (current->Food + current->Transport + current->Bills + current->Clothing + current->Shopping +
			current->Education + current->Health + current->Social + current->Beauty + current->Other) << endl;
		cout << " " << endl;


		//cout << endl;
		//cout << "" << size << endl;

	}


	void PrintData() {
		Node* current = head;
		for (int i = 0; i < size; i++)
		{
			cout << "Expenses for the Day " << current->date << endl;
			cout << "Food:" << current->Food << endl;
			cout << "Transport:" << current->Transport << endl;
			cout << "Bills:" << current->Bills << endl;
			cout << "Clothing:" << current->Clothing << endl;
			cout << "Shopping:" << current->Shopping << endl;
			cout << "Education:" << current->Education << endl;
			cout << "Health:" << current->Health << endl;
			cout << "Social:" << current->Social << endl;
			cout << "Beauty:" << current->Beauty << endl;
			cout << "Other:" << current->Other << endl;
			cout << "Total expense of the day:" << (current->Food+current->Transport+current->Bills+current->Clothing+current->Shopping+
				current->Education+current->Health+current->Social+current->Beauty+current->Other) << endl;
			cout << " " << endl;
	
			current = current->next;
		}
		cout<<endl;
		cout << "" << size << endl;
		
	}
};
