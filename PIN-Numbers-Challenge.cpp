// Randomizing challenge-response system for passwords
// The user enters different info every time based on a secret 
// in response to a randomly generated challenge.

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
