// kk4036_hw8_q4.cpp : PIN Challenge
// Randomizing challenge-response system for passwords
// The user enters different info every time based on a secret 
// in response to a randomly generated challenge.

// The password consists of 5-digit PIN number (00000 to 99999)
// Each digit is assigned a random number that is 1, 2, or 3.
// The user enters the random numbers that corespond to their PIN 
// instead of their actual PIN numbers
// e.g. PIN number = 12345.  What they will see on the screen is:
// PIN: 0 1 2 3 4 5 6 7 8 9
// NUM: 3 2 3 1 1 3 2 2 1 3  (sequence of random #s consisting of 1, 2, or 3)
// The user would enter 23113 instead of 12345. 
// The hacker cannot intercept the entry becase 23113 could correspond to 
// other PIN's like 69440 or 70439
// The next time the user logs in, a different sequence of random numbers 
// would be generated.

// Write a program to simulate the authentication process. 
// Store an actual 5-digit PIN numbers in your program as a constant
// The program should use an array to assign random #s to the digits 0 ~ 9
// Output the random digits to the screen, input the response from the user, 
// and output whether or not the user's response correctly matches the PIN.

#include "pch.h"
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

int main1();	// uses PIN num array
const int PIN_ARR[5] = { 5, 4, 3, 2, 1 };

int main2();	// uses PIN num string
const string PIN_STR = "54321";

void printPinArr(int arr[], int arrSize);
void printRandomArr(int arr[], int arrSize);
const int ARR_SIZE = 10;

int main()
{
	main1();
	cout << endl;
	main2();
	cout << endl;
	return 0;
}

int main1()
{
	int pinArr[ARR_SIZE];
	cout << "Enter your PIN according to the following mapping: " << endl;
	cout << "PIN: \t";
	printPinArr(pinArr, ARR_SIZE);
	cout << endl;

	int randomArr[ARR_SIZE];
	cout << "NUM: \t";
	printRandomArr(randomArr, ARR_SIZE);
	cout << endl;

	string inputPIN;
	cin >> inputPIN;
	int n = inputPIN.length();

	// Compare the user input elements to the randomized array 
	// but with the values of actual pin number
	// if inputPIN(x)'s i loc = randomArr(PIN(x))'s loc, inputPIN is correct
	// Delete elements in the array with trailing and leading 0's
	// char arr[] = "12345"; -> length = 5, but size = 6
	// because of the trailing '\0' in the array
	bool pinCorrect = true;
	for (int i = 0; i < n; i++) {
		if((inputPIN[i] - '0') != randomArr[PIN_ARR[i]])
			pinCorrect = false;
	}

	if (pinCorrect)
		cout << "Your PIN is correct." << endl;
	else
		cout << "Your PIN is incorrect. Try again." << endl;

	return 0;
}

int main2()
{
	int pinArr[ARR_SIZE];
	cout << "Enter your PIN according to the following mapping: " << endl;
	cout << "PIN: \t";
	printPinArr(pinArr, ARR_SIZE);
	cout << endl;

	int randomArr[ARR_SIZE];
	cout << "NUM: \t";
	printRandomArr(randomArr, ARR_SIZE);
	cout << endl;

	string inputPIN;
	cin >> inputPIN;
	int n = inputPIN.length();

	string inputPINdig = "";
	string actualPINdig = "";
	
	// loop through each digit of user-input PIN to determine 
	// if mapped correctly to actual PIN
	// since PIN_STR's order = idx's order, use PIN dig as idx # of randomArr
	bool pinCorrect = true;
	for (int i = 0; i < n; i++) {
		inputPINdig = inputPIN[i];		//inputPINdig = * * * * *
		actualPINdig = PIN_STR[i];		//PINdig = 1 2 3 4 5
		if (stoi(inputPINdig) != randomArr[stoi(actualPINdig)])
			pinCorrect = false;
	}

	if (pinCorrect)
		cout << "Your PIN is correct." << endl;
	else
		cout << "Your PIN is incorrect. Try again." << endl;
	
	return 0;
}

void printPinArr(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		arr[i] = i;
		cout << arr[i] << " ";
	}
}

void printRandomArr(int arr[], int arrSize) {
	//creating the SEED for the random # generator.
	srand((unsigned int)time(0));
	
	for (int i = 0; i < arrSize; i++) {
		arr[i] = (rand() % 3) + 1;		// psudo-random # bet 0 and 2 + 1
		cout << arr[i] << " ";
	}
}

/* Just some randome password function
const string password = "wtfisthepassword";
void pwCheck(string password) {
	const string password = "wtfisthepassword";
	string input;

	cout << "Enter your password: " << flush;
	cin >> input;

	while (input != password) {
		cout << "Incorrect password.  Try again: " << flush;
		cin >> input;
	}
	cout << endl;
	cout << "Password accepted.";  
	cout << "Please check your email to validate your account." << endl;
}
*/