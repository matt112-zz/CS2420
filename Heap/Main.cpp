//Matthew Castro
//Section 1
//
//Disclaimer:
//
//I Matthew Castro have not used any code other than my own (or that in the textbook) for this project. I also
//
//have not used any function or data-structure from the Standard-Template Library. I understand that any
//
//violation of this disclaimer will postfixExpression in a 0 for the project.

//Git push test!

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Heap.h"
#include <cctype>       // Provides toupper
#include <cstdlib>      // Provides EXIT_SUCCESS

using namespace std;

void heapSort();
void makeHeap(const int A[], int size, heap& T);
void printArray(const int A[], int size);

// PROTOTYPES for functions used by this test program:
void print_menu();
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command();
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters),
// and this character has been returned.

int get_number();
// Postcondition: The user has been prompted to enter a real number. The
// number has been read, echoed to the screen, and returned by the function.


int main() {
	srand(time(NULL));
	char choice;   // A command character entered by the user
	int frontValue;

		cout << "I have initialized an empty heap. This heap works on numbers greater than 0." << endl;
		heap test;

		do
		{
			print_menu();
			choice = toupper(get_user_command());
			switch (choice)
			{
			case 'H': heapSort();
				break;
			case 'I': test.insert(get_number());
				break;
			case 'R': frontValue = test.removeFront();
                if(frontValue) {
                    cout << "\nThe next value in the heap is " << frontValue << endl;
                }
                else {
                    cout << "\nThe heap is empty. No values to remove." << endl;
                }
				break;
            case 'A':
                test.print();
                break;
            case 'P': test.printTree();
				break;
			case 'Q': cout << "\nThanks for playing!" << endl;
				break;
			default:  cout << "\n" << choice << " is invalid." << endl;
			}
		} while ((choice != 'Q'));

		return EXIT_SUCCESS;
}

	void print_menu()
		// Library facilities used: iostream.h
	{
		cout << endl; // Print blank line before the menu
		cout << "The following choices are available: " << endl;
		cout << " H   Create a new heap out of 20 random numbers, then print it." << endl;
		cout << " I   Insert a value into the heap" << endl;
		cout << " R   Remove the first value from the heap and print it" << endl;
		cout << " A   Print the array that is storing the values of the heap" << endl;
		cout << " P   Print the heap in an indented manner" << endl;
		cout << " Q   Quit this test program" << endl;
	}

	char get_user_command()
		// Library facilities used: iostream
	{
		char command;

		cout << "Enter choice: ";
		cin >> command; // Input of characters skips blanks and newline character

		return command;
	}

	int get_number()
		// Library facilities used: iostream
	{
		int result;

		cout << "\nPlease enter an integer: ";
		cin >> result;
		cout <<  "\n" << result << " has been read." << endl;
		return result;
	}


void heapSort() {
	const int size = 20;
	int A[size];

	for (int i = 0; i < size; i++) {
		A[i] = (rand() % 50) + 1;
	}

    cout << "\nHere are the values being used to create the heap:" << endl;
    printArray(A, size);

	heap test;
    makeHeap(A, size, test);

	test.print();

	cout << "\nHere is the heap printed in an indented manner:" << endl;
	test.printTree();

	for (int i = 0; i < size; i++) {
		A[i] = test.removeFront();
	}

    cout << "\nHere are the sorted values of the heap:" << endl;
	printArray(A, size);

}

void makeHeap(const int A[], int size, heap& T) {
    for (int i = 0; i < size; i++) {
      T.insert(A[i]);
	}
}

void printArray(const int A[], int size) {
	cout << "[";
	for (int i = 0; i < size - 1; i++) {
		cout << A[i] << ",";
	}
	cout << A[size - 1];
	cout << "]" << endl;
}
