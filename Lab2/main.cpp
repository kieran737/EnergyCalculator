/*-----------------------------------------------------------------------------

Name: Kieran Hodge

Date: 06.11.2014

Lab number: 2

--------------------------------------------------------------------------------
Program Description: This program will prompt the user for the amount of kilowatts they 
have used, then if their entry is over 1000 every unit over would be multiplied by 0.45 
but for anything under 1000 or equal to will be multiplied by 0.60.
--------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

float kilowatt;
float priceUnder1000 = 0.60;
float priceOver1000 =  0.45;
string validationString;

int main ()
{
	//This will welcome the customer to the program.
	cout << setw (50) << "Welcome to E-Watt's" << endl;
	//The Do-Loop will allow the program to restart if customer requests.
	int returntoStart;
	do
	{
		//This will prompt the user to input the amount of kilowatts used.
		cout << endl << setw (53) << "Amount of Kilowat used: ";
		cin >> kilowatt;
		//The code bellow will validate the users input, it will make sure that the user does not input any characters.
		cin.ignore();
		while (cin.fail())
		{
			cin.clear();
			getline (cin, validationString);
			system ("color 04");
			cout << setw (64) << "Invalid Input, Please Enter a Numeric Value: ";
			cin >> kilowatt;
		}
		//The program will now do the multiplications and it will choose which statement depending on whether the customers input is either under/equal to 1000 or over 1000.
		//The setprecision line of code rounds the multiplications answer to the second nearest decimal place.
		if (kilowatt <= 1000)
		{	
			cout << fixed << showpoint << setprecision(2);
			cout << system ("color 07") << setw (44) << "Total Price: " << char(156) << kilowatt*priceUnder1000 << endl;
		}
		else
		{	
			cout << fixed << showpoint << setprecision(2);
			cout << system ("color 07") << setw (57) << "Total Price, Including Discount: " << char(156) << (kilowatt - 1000) * priceOver1000 + 600 << endl;
		}
		//The program will now prompt the user to either restart the program or close it.
		cout << endl << setw (50) << "Enter 1 to Restart." << endl;
		cout << setw (55) << "Enter 0 to Close the program" << endl;
		cin >> returntoStart;
	}while (returntoStart == 1);
	if (returntoStart == 0)
		//If the customer wants to close the program then the following code will display a simple message for a couple of micro-seconds.
			cout << setw (55) << "Thank You for using E-Watts." << endl;
	Sleep (1000);
}
