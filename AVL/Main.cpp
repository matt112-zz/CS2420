//Matthew Castro
//Section 1
//
//Disclaimer:
//
//I Matthew Castro have not used any code other than my own (or that in the textbook) for this project. I also
//
//have not used any function or data-structure from the Standard-Template Library. I understand that any
//
//violation of this disclaimer will result in a 0 for the project.

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include "AVL.h"
//#include "Queue.h"
#include <cctype>       // Provides toupper
#include <cstdlib>      // Provides EXIT_SUCCESS


using namespace std;

// PROTOTYPES for functions used by this test program:
void print_menu( );
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command( );
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters),
// and this character has been returned.

int get_number( );
// Postcondition: The user has been prompted to enter a real number. The
// number has been read, echoed to the screen, and returned by the function.



int main( )
{
    AVL test; // A AVL that we'll perform tests on
    char choice;   // A command character entered by the user

    cout << "I have initialized an empty AVL Tree" << endl;

    do
    {
        print_menu( );
        choice = toupper(get_user_command( ));
        switch (choice)
        {

            case 'S': cout << "Size is " << test.Size() << endl;
                      break;
            case 'I': test.insert(get_number( ));
                      break;
			case 'F': if (test.search(get_number()))
						  cout << "The number is in the AVL" << endl;
					  else
						  cout << "The number is not in the AVL" << endl;
					  break;
            case 'R': test.remove(get_number());
                      break;
			case 'P': test.print();
					  break;
            case '1': test.preorder();
					  break;
            case '2': test.inorder();
                      break;
            case '3': test.postorder();
					  break;
			case 'Q': cout << "Thanks for playing!" << endl;
                      break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));

    return EXIT_SUCCESS;
}

void print_menu( )
// Library facilities used: iostream.h
{
    cout << endl; // Print blank line before the menu
    cout << "The following choices are available: " << endl;
    cout << " P   Print a copy of the entire AVL with indents" << endl;
    cout << " S   Print the result from the size( ) function" << endl;
    cout << " R   Remove a number from the tree" << endl;
    cout << " 1   Print the list in a PreOrder manner" << endl;
    cout << " 2   Print the list in a InOrder manner" << endl;
    cout << " 3   Print the list in a PostOrder manner" << endl;
	cout << " F   Search for a number in the AVL using the Search() function" << endl;
    cout << " I   Insert a new number with the Insert(...)" << endl;
    cout << " Q   Quit this test program" << endl;
}

char get_user_command( )
// Library facilities used: iostream
{
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character

    return command;
}

int get_number( )
// Library facilities used: iostream
{
   int result;

    cout << "Please enter an integer: ";
    cin  >> result;
    cout << result << " has been read." << endl;
    return result;
}
