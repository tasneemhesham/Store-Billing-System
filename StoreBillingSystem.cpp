#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;


struct node {
	node* prev;
	node* next;
	int quantity, price, sum, data;  
	string name, nam;   
};


struct node* head = NULL;
node* insert_node() {
	node* n = new node;
	cout << "\n\t\t\t\tEnter product ID: ";
	cin >> n->data;
	cout << "\n\t\t\t\tEnter product name: ";
	cin >> n->name;
	cout << "\n\t\t\t\tEnter quantity: ";
	cin >> n->quantity;
	cout << "\n\t\t\t\tEnter price of each: ";
	cin >> n->price;
	n->next = NULL;
	n->prev = NULL;
	if (head == NULL) {
		head = n;
	}
	else {
		node* last = head;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = n;
		n->prev = last;
	}
	return n;
}

string check(int quant)
{
	if (quant <= 0)
	{
		return "out of stock!";
	}
		return to_string(quant);

}


void display() {
	node* last;
	last = head;
	cout << "\n\n\t\t\t\t\t----------STORE PRODUCTS----------\n" << endl;
	cout << "\t\t\tEXISTING PRODUCTS ARE:\n\n";
	cout << "\t\t\tID\t\tPRODUCT NAME\t\tPRICE\t\tQUANTITY\n";
	while (last != NULL) {
		cout << "\t\t\t" << last->data << "\t\t" << last->name << "\t\t\t" << last->price << "\t\t" << check(last->quantity) << endl;
		last = last->next;

	}
}

void delete_beg()
{
	if (head == NULL)
	{
		cout << "\t\t\tThe store is empty! \n";
	}
	else {
		node* temp;
		temp = head;
		head = head->next;
		cout << "\n\t\t\tThe Product whose ID is [" << temp->data << "] has been deleted!\n";
		delete(temp);
	}
	
}

void delete_end() 
{
	node* last;
	last = head;
	while (last->next != NULL) {
		last = last->next;
	}
	last->prev->next = NULL;
	cout << "\n\t\t\tThe Product whose ID is [" << last->data << "] has been deleted!\n";
	delete(last);
}

void delete_node() {
	int value;
	cout << "\t\t\t\t\tEnter the product id that you will Delete : ";
	cin >> value;
	node* last;
	last = head;
	if (head == NULL)
	{
		system("cls");
		cout << "\n\n\t\t\t\t\t--THERE IS NO PRODUCT TO DELETE--" << endl;
		cout << "\n\t\t\t\t\t--STORE IS EMPTY !!-- " << endl;
	}
	else
	{
		if (head->next == NULL)
		{
			cout << "\t\t\t\t\t[" << last->data << " ] has been deleted" << endl;
			delete (head);
			head = NULL;
		}
		else
		{
			while (last->data != value)
			{
				last = last->next;
			}
			last->prev->next = last->next;
			last->next->prev = last->prev;
			cout << "\t\t\t\t\t[" << last->data << " ] has been deleted" << endl;
			delete (last);
		}
	}
}



int password()
{
	string username;
	string password;
	cout << "\t\t\t-------------LOGIN PAGE-------------" << endl;
	cout << "\t\t\tEnter username : ";
	cin >> username;
	cout << "\t\t\tEnter password : ";
	cin >> password;
	if (username == "admin")
	{
		if (password == "0000")
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

void buy()
{
	int id, q, price, total;
	node* p = head;
	if (head == NULL)
	{
		cout << "\t\t\tTHE STORE IS EMPTY\n";
	}
	else
	{
		cout << "\t\t\tEXISTING PRODUCTS ARE:\n";
		cout << "\t\t\tID\t\tPRODUCT NAME\t\tPRICE\t\tQUANTITY\n";
		while (p != NULL)
		{
			cout << "\t\t\t" << p->data << "\t\t" << p->name << "\t\t\t" << p->price << "\t\t" << check(p->quantity) << endl;
			p = p->next;
		}
		cout << "\t\t\tENTER PRODUCT ID TO BUY:";
		cin >> id;
		cout << "\t\t\tENTER QUANTITY TO BUY:";
		cin >> q;
		p = head;
		while (p != NULL)
		{
			if (p->data == id)
			{
				if (p->quantity >= q)
				{
					price = p->price;
					total = price * q;
					p->quantity -= q;
					cout << "\t\t\tTOTAL PRICE: " << total << endl;
					cout << "\t\t\tYOU BOUGHT: " << q << " OF " << "[" << p->name << "]" << endl;
					break;
				}
				else
				{
					cout << "\t\t\tSORRY! Not enough quantity available. Available quantity is: " << p->quantity << endl;
				}
			}
			p = p->next;
		}
		if (p == NULL)
		{
			cout << "\t\t\tPRODUCT ID NOT FOUND !\n";
		}
	}
}

void search()
{
	string n;
	node* p = head;

	if (head == NULL)
	{
		cout << "\n\t\t\tTHE STORE IS EMPTY!\n";
	}
	else
	{
		cout << "\t\t\tENTER THE NAME OF THE PRODUCT YOU WANT TO BUY: ";
		cin >> n;
		while (p != NULL)
		{
			if (p->name == n)
			{
				cout << "\t\t\tPRODUCT FOUND\n";
				cout << "\t\t\tID\t\tNAME\t\tPRICE\t\tQUANTITY\n";
				cout << "\t\t\t" << p->data << "\t\t" << p->name << "\t\t\t" << p->price << "\t\t" << check(p->quantity) << endl;
				return;
			}
			p = p->next;
		}
		cout << "\t\t\tPRODUCT NOT FOUND!\n";
	}
}


int main() {
menu:
	system("cls");
	cout << "\n\t\t\t\t\t----------STORE SYSTEM----------\n";
	cout << "\n\n\t\t\t\t\t\t1.CUSTOMER\n\t\t\t\t\t\t2.STAFF\n\t\t\t\t\t\t3.EXIT\n";
	int choice;
	int  a;
	cin >> a;
	system("cls");
	switch (a)
	{
	case 1:
		while (true) {
			cout << "\n\t\t\t\t\tPICK A CHOICE FROM THE LIST BELOW:\n";
			cout << "\n\t\t\t\t\t---------------------------------\n";
			cout << "\n\n\t\t\t\t\t1.BUY A PRODUCT\n";
			cout << "\t\t\t\t\t2.VIEW ALL PRODUCTS\n";
			cout << "\t\t\t\t\t3.SEARCH\n";
			cout << "\t\t\t\t\t4.BACK TO MAIN PAGE\n";
			int x;
			cin >> x;

			switch (x)
			{
			case 1:
				system("cls");
				buy();
				break;
			case 2: 
				system("cls");
				display();
				break;
			case 3: 
				system("cls");
				search();
				break;
			case 4:
				goto menu;
				break;
			default:
				system("cls");
				cout << "\t\t\t\t\tINVALID CHOICE!\n\t\t\t\t\tPLEASE TRY AGAIN!" << endl;
				cout << endl;
				break;
			}
		}



	case 2:

		if (password() == 0)
		{
			system("cls");
			for (int i = 0; i < 2; i++)
			{
				cout << "\n\t\t\t\t\tINCORRECT PASSWORD!\n\t\t\t\t\t[1 ATTEMPT REMAINING]\n\n\n";
				if (password())
				{
					goto last;
					system("cls");
				}
				else
				{
					cout << endl << "\t\t\t\t\tALL ATTEMPTS FAILED.\n";
					exit(0);
				}

			}
			cout << "\t\t\t\tSORRY ALL ATTEMPTS FAILED.\n";
		}
		else
		{
			system("cls");
			cout << "\t\t\t\t\tSUCCESSFULLY LOGGED IN.\n";
		last:;
		m:;

		{
			cout << "\n\t\t\t\t\tPICK A CHOICE FROM THE LIST BELOW:\n";
			cout << "\n\t\t\t\t\t---------------------------------\n";
			cout << "\n\n\t\t\t\t\t1.ADD PRODUCT\n";
			cout << "\t\t\t\t\t2.DELETE PRODUCT AT LAST POSITION\n";
			cout << "\t\t\t\t\t3.DELETE PRODUCT AT FIRST POSITION\n";
			cout << "\t\t\t\t\t4.DELETE PRODUCT AT AFTER A GIVEN POSITION\n";
			cout << "\t\t\t\t\t5.VIEW ALL PRODUCTS\n";
			cout << "\t\t\t\t\t6.SEARCH\n";
			cout << "\t\t\t\t\t7.BACK TO MAIN PAGE\n";
			int  y;
			cin >> y;
			switch (y)
			{
			case 1:
				system("cls");
				insert_node();
				break;
			case 2:
				system("cls");
				delete_end();
				break;
			case 3:
				system("cls");
				delete_beg();
				break;
			case 4:
				system("cls");
				delete_node();
				break;
			case 5:
				system("cls");
				display();
				break;
			case 6:
				system("cls");
				search();
				break;
			case 7:
				goto menu;
				break;
			default:
				system("cls");
				cout << "\t\t\t\t\tINVALID CHOICE!\n\t\t\t\t\tPLEASE TRY AGAIN!" << endl;
				cout << endl;
				break;
			}
			goto m;

		}
		} 
		break;
	}

	return 0;
}