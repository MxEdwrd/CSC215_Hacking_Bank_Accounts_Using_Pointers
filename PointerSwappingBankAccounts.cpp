/*
Author: Max Edward
Email : maxedwar@uat.edu
Assignment Name : Hacking Bank Accounts Using Pointers
*/

// Include libraries & header files
#include <iostream>
#include <string>
#include <Windows.h>

// Namespace Block
using namespace std;

// Variable Block
string agentName = "";
string assignAns = "";
string coffeeShop = "Max's Coffee Cove";


// Function Block
int runAssign();

void opening() {
    cout << "\n------------------------------------\n\n";
    cout << "Today we will be spying on a terrorist organization's bank account at Night Bank." << endl;
    cout << "When the time comes, we will swap their bank account balance with the balance of a local coffee shop, " << coffeeShop << "." << endl;
    cout << "When we send you the cue to strike, you will type 'swap' and swap the account balances." << endl;
    cout << "Accept the assignment by entering 'yes'. Deny the assignment by entering 'no'.\n";
    cout << "\n------------------------------------\n\n";
}

void normBal(double terrBal, double coffeeBal) { 
	// This function is for the normal balance readout. It does not involve any swapping and 
	// essentially reads terrBal as the terrorist's balance and the coffeeBal as the coffee shop's balance.
	double tempSwap = terrBal; // Sets tempSwap as the terrBal, in order to store the value when we swap the balances.
	terrBal = coffeeBal; // Sets the current terrBal to the coffeeBal's amount.
	coffeeBal = tempSwap; // Sets the coffeeBal's amount to the original terrBal's amount, finishing the swap. 
}

void swapBal(double* const terrBalSwap, double* const coffeeBalSwap) {
	// This function is for the swapped balance radout. It involves pointing to the original variable values and swapping them.
	double tempSwap = *terrBalSwap; // Sets the tempSwap as terrBalSwap, the new pointed variable from terrBal. This will store its current value for later use.
	*terrBalSwap = *coffeeBalSwap; // Sets the current terrBalSwap to the coffeeBalSwap's amount.
	*coffeeBalSwap = tempSwap; // Sets the coffeeBalSwap's amount to the original terrBalSwap's amount, finishing the swap with pointers.
}

int main() {
	cout << "Please log in to verify credentials.\n";
	cout << "Enter Last Name: ";
	cin >> agentName;
	cout << "\nWelcome, Agent " << agentName << ".\n";
	Sleep(3000); // Delays output for three seconds. 

	opening();
	cout << ": ";
	cin >> assignAns;
	// If assignment answer is yes, run the assignment.
	if (assignAns == "yes" || assignAns == "Yes" || assignAns == "YES") {
		runAssign();
	}
	// If the user types anything but yes after the introduction of the assignment, return a value of 0 and end the program.
	else {
		cout << "\nConnection Terminated... Goodbye Agent " << agentName << ".\n";
		return 0;
	}
}

int runAssign() {
	// Variables for balances & swap string.
	double terrBal = 151623.88;
	double coffeeBal = 304.36;
	string swap = "";

	normBal(terrBal, coffeeBal); // Calls the normbal function to activate.
	cout << "\nOkay Agent " << agentName << ", today is the day we make the switch." << endl;
	cout << "First we will check the current balance of the coffee shop.\n" << endl;
	Sleep(5000); // Delays the output for five seconds.
	cout.precision(10); // Sets the precision of cout to up to 10 number places, including decimals. Necessary for balance readout.
	cout << "Currently viewing " << coffeeShop << " account balance..." << endl;
	cout << coffeeShop << " balance is $" << coffeeBal << "" << endl;
	cout << "\nNow we will look at the terrorist's current balance.\n" << endl;
	Sleep(5000); // Delays the output for five seconds.
	cout.precision(10); // Sets the precision of cout to up to 10 number places, including decimals. Necessary for balance readout.
	cout << "Currently viewing 'TERR_ORG' account balance..." << endl;
	cout << "'TERR_ORG' balance is $" << terrBal << "" << endl;
	Sleep(3000); // Delays the output for three seconds.

	cout << "\nOkay, we know both account's current balances. Now we have to swap them." << endl;
	cout << "On my mark, type 'swap' and the account's balances will switch.\n" << endl;
	Sleep(5000); // Delays the output for five seconds.
	cout << "3...\n" << endl;
	Sleep(1000); // Delays the output for one seconds.
	cout << "2...\n" << endl;
	Sleep(1000); // Delays the output for one seconds.
	cout << "1...\n" << endl;
	Sleep(1000); // Delays the output for one seconds.
	cout << "Swap them!\n" << endl;

	// While the user has not typed swap, loop.
	while (swap != "swap" || swap != "Swap") {
		cout << ": ";
		cin >> swap;
		// Once the user correctly types swap, break the loop.
		if (swap == "swap" || swap == "Swap") {
			break;
		}
		// If the user has not correctly typed swap, loop.
		else {
			cout << "\nNot quite, you need to type 'swap'.\n\n";
		}
	}

	swapBal(&terrBal, &coffeeBal); // Calls the swapBal function to activate.
	cout << "\nGood work, lets see the new account balances.\n\n";
	Sleep(5000); // Delays the output for five seconds.
	cout.precision(10); // Sets the precision of cout to up to 10 number places, including decimals. Necessary for balance readout.
	cout << "Currently viewing " << coffeeShop << " account balance..." << endl;
	cout << coffeeShop << " balance is $" << coffeeBal << "" << endl;
	cout << "\nNow we will look at the terrorist's current balance.\n" << endl;
	Sleep(5000); // Delays the output for five seconds.
	cout.precision(10); // Sets the precision of cout to up to 10 number places, including decimals. Necessary for balance readout.
	cout << "Currently viewing 'TERR_ORG' account balance..." << endl;
	cout << "'TERR_ORG' balance is $" << terrBal << "" << endl;
	Sleep(3000); // Delays the output for three seconds.

	cout << "\nGreat work Agent " << agentName << ". We have successfully drained the bank account of the terrorist organization and benefitted " << coffeeShop << "." << endl;
	cout << "\nA new assigment will be given to you within the coming weeks. Until then, wait for further instruction." << endl;
	cout << "\nConnection Terminated... Goodbye Agent " << agentName << "." << endl;
	return 0;
}
