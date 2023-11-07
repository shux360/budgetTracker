#pragma once
#include <iostream>
#include "Node.h"

using namespace std;
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
		Node* temp = new Node(d,vFood,vTransport,vBills,vClothing,vShopping,vEducation,vHealth,vSocial,vBeauty,vOther);
		if (head == NULL) {
			head = temp;
			tail = temp;
			//size++;
		}
		else {
			temp->next = head;
			head->prev = temp;
			head = temp;

			//size++;
		}

	}
	void InsertLast(int d, int vFood, int vTransport, int vBills, int vClothing, int vShopping, int vEducation, int vHealth, int vSocial, int vBeauty, int vOther) {
		Node* temp = new Node(d, vFood, vTransport, vBills, vClothing, vShopping, vEducation, vHealth, vSocial, vBeauty, vOther);
		if (head == NULL) {
			head = temp;
			tail = temp;
			//size++;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
			tail->next = NULL;
			//size++;
		}
	}
	void InsertAt(int d, int vFood, int vTransport, int vBills, int vClothing, int vShopping, int vEducation, int vHealth, int vSocial, int vBeauty, int vOther) {
		if (d < 1 || d > 31) { // need to edit 
			cout << "Invalid Date" << endl;
		}
		else if (d == 1) {
			InsertFirst(d, vFood, vTransport, vBills, vClothing, vShopping, vEducation, vHealth, vSocial, vBeauty, vOther);
			
		}
		else if (d == size) {
			InsertLast(d, vFood, vTransport, vBills, vClothing, vShopping, vEducation, vHealth, vSocial, vBeauty, vOther);
		}
		else {
			Node* temp = new Node(d, vFood, vTransport, vBills, vClothing, vShopping, vEducation, vHealth, vSocial, vBeauty, vOther);
			Node* current = head;
			for (int i = 0; i < d-2; i++) {
				current = current->next;
			}
			temp->next = current->next;
			temp->prev = current;
			current->next = temp;
			(temp->next)->prev = temp;
			//size++;
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
	void FindData() { cout << "This is FindData" << endl; }
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