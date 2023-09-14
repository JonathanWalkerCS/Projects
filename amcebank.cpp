#include <iostream>
#include <fstream>
using namespace std;

int main()
{ 	

ifstream myfile;
int a1, a2, a3, amount;
string action, option, account, transfer; 
myfile.open("smith.accounts");
myfile >> a1;
myfile >> a2;
myfile >> a3;

do
{ 
cout << "\nAccount 1: " << a1 << endl;
cout << "Account 2: " << a2 << endl;
cout << "Account 3: " << a3 << endl; 

cout << "\n\nOptions: " << endl;
cout << "1.Deposit" << endl;
cout << "2.Withdrawal" << endl;
cout << "3.Transfer" << endl;
cout << "4.Exit" << endl;
	
cout << "\n\nPlease make a selection: " << endl;
cout << "(Enter 1 to make a Deposit)" << endl;
cout << "(Enter 2 to make Withdraw)" << endl;
cout << "(Enter 3 to make a Transfer)" << endl;
cout << "(Enter 4 to exit the ATM)" << endl;
cin >> action;

if (action == "1")
{

cout << "Enter the amount you would like to deposit:" << endl;
cin >> amount; 
	if (amount > 0)
	{
	cout << "Which account do you want to deposit " << amount << " into?" << endl;
	cout << "Enter 1 for Account 1" << endl;
	cout << "Enter 2 for Account 2" << endl;
	cout << "Enter 3 for Account 3" << endl; 
	cin >> account;
		if (account == "1")
		{
		a1 = a1 + amount;
		cout << "You deposited " << amount << " into account 1 during this transaction" << endl;
		cout << "The new balance of account 1 is: " << a1 << endl;
		}

		else if (account == "2")
		{
		a2 = a2 + amount;
		cout << "You deposited " << amount << " into account 2 during this transaction" << endl;		
		cout << "The new balance of account 2 is: " << a2 << endl;
		}

		else if (account == "3")
		{
		a3 = a3 + amount;
		cout << "You deposited " << amount << " into account 3 during this transaction" << endl;		
		cout << "The new balance of account 3 is: " << a3 << endl;
		}

		else 
		cout << "Error retrieving account" << endl;
	}
	else
	cout << "Invalid amount entered" << endl;
}

else if (action == "2")
{

cout << "Enter the amount you would like to withdraw:" << endl;
cin >> amount; 
	if (amount > 0)
	{
	cout << "Which account do you want to withdraw " << amount << " from?" << endl;
	cout << "Enter 1 for Account 1" << endl;
	cout << "Enter 2 for Account 2" << endl;
	cout << "Enter 3 for Account 3" << endl; 
	cin >> account;
		if (account == "1" && amount <= a1)
		{
		a1 = a1 - amount;
		cout << "\nYou withdrew " << amount << " during this transaction" << endl;
		cout << "The new balance of account 1 is: " << a1 << endl;
		}

		else if (account == "2" && amount <= a2)
		{
		a2 = a2 - amount;
		cout << "\nYou withdrew " << amount << " during this transaction" << endl;
		cout << "The new balance of account 2 is: " << a2 << endl;
		}

		else if (account == "3" && amount <= a3)
		{
		a3 = a3 - amount;
		cout << "\nYou withdrew " << amount << " during this transaction" << endl;
		cout << "The new balance of account 3 is: " << a3 << endl;
		}

		else if (account != "1" && account != "2" && account != "3")
		{
		cout << "Error retrieving account" << endl;
		}
		
		else 
		cout << "Amount entered is greater than account balance" << endl;
	}
	else
	cout << "Invalid amount entered" << endl;
}

else if (action == "3")
{

cout << "Enter the amount you would like to transfer:" << endl;
cin >> amount; 
	if (amount > 0)
	{
	cout << "Which account do you want to transfer " << amount << " from?" << endl;
	cout << "Enter 1 for Account 1" << endl;
	cout << "Enter 2 for Account 2" << endl;
	cout << "Enter 3 for Account 3" << endl; 
	cin >> account;

		if (account == "1" && amount <= a1)
		{
		cout << "Which account do you want to transfer " << amount << " to?" << endl;
		cout << "Enter 1 for Account 2" << endl;
		cout << "Enter 2 for Account 3" << endl;
		cin >> transfer; 
			if (transfer == "1")
			{
			a1 = a1 - amount;
			a2 = a2 + amount; 
			cout << "You transferred " << amount << " from account 1 to account 2 during this transaction" << endl;
			cout << "The new balance of account 1 after the transfer is: " << a1 << endl;
			cout << "The new balance of account 2 after the transfer is: " << a2 << endl; 
			}

			else if (transfer == "2")
			{
			a1 = a1 - amount;
			a3 = a3 + amount; 
			cout << "You transferred " << amount << " from account 1 to account 3 during this transaction" << endl;			
			cout << "The new balance of account 1 after the transfer is: " << a1 << endl;
			cout << "The new balance of account 3 after the transfer is: " << a3 << endl; 
			}

			else 
			cout << "Invalid account selection" << endl;

		}

		else if (account == "2" && amount <= a2)
		{
		cout << "Which account do you want to transfer " << amount << " to?" << endl;
		cout << "Enter 1 for Account 1" << endl;
		cout << "Enter 2 for Account 3" << endl;
		cin >> transfer; 
			if (transfer == "1")
			{
			a2 = a2 - amount;
			a1 = a1 + amount; 
			cout << "You transferred " << amount << " from account 2 to account 1 during this transaction" << endl;			
			cout << "The new balance of account 2 after the transfer is: " << a2 << endl;
			cout << "The new balance of account 1 after the transfer is: " << a1 << endl; 
			}

			else if (transfer == "2")
			{
			a2 = a2 - amount;
			a3 = a3 + amount; 
			cout << "You transferred " << amount << " from account 2 to account 3 during this transaction" << endl;			
			cout << "The new balance of account 2 after the transfer is: " << a2 << endl;
			cout << "The new balance of account 3 after the transfer is: " << a3 << endl; 
			}

			else 
			cout << "Invalid account selection" << endl;

		}


		else if (account == "3" && amount <= a3)
		{
		cout << "Which account do you want to transfer " << amount << " to?" << endl;
		cout << "Enter 1 for Account 1" << endl;
		cout << "Enter 2 for Account 2" << endl;
		cin >> transfer; 
			if (transfer == "1")
			{
			a3 = a3 - amount;
			a1 = a1 + amount; 
			cout << "You transferred " << amount << " from account 3 to account 1 during this transaction" << endl;
			cout << "The new balance of account 3 after the transfer is: " << a3 << endl;
			cout << "The new balance of account 1 after the transfer is: " << a1 << endl; 
			}

			else if (transfer == "2")
			{
			a3 = a3 - amount;
			a2 = a2 + amount; 
			cout << "You transferred " << amount << " from account 3 to account 2 during this transaction" << endl;			
			cout << "The new balance of account 3 after the transfer is: " << a3 << endl;
			cout << "The new balance of account 2 after the transfer is: " << a2 << endl; 
			}

			else 
			cout << "Invalid account selection" << endl;
		}
		else
		cout << "Amount entered is greater than account balance" << endl;
	}
	else
	cout << "Invalid amount entered" << endl;
	
}


}
while(action != "4");
cout << "Have a nice day!" << endl;
}