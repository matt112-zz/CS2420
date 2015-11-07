// FILE: Sequence.h
// CLASS PROVIDED: Sequence (part of the namespace main_savitch_4)
// There is no implementation file provided for this class since it is
// an exercise from Chapter 4 of "Data Structures and Other Objects Using C++"
//
// TYPEDEFS and MEMBER CONSTANTS for the Sequence class:
//   typedef ____ value_type
//     Sequence::value_type is the data type of the items in the Sequence. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   static const int DEFAULT_CAPACITY = _____
//     Sequence::DEFAULT_CAPACITY is the initial capacity of a Sequence that is
//     created by the default constructor.
//
// CONSTRUCTORS for the Sequence class:
//   Sequence(int initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The Sequence has been initialized as an empty Sequence.
//     The insert/attach functions will work efficiently (without allocating
//     new memory) until this capacity is reached.
//
//   Sequence(const Sequence& source)
//     Postcondition: the Sequence has made a deep copy of the source Sequence.
//
//  DESTRUCTOR:
//	 ~Sequence()
//		Poscondition: all dynamically allocated memory has been destroyed.
//
//	OPERATOR:
//	  void operator =(const Sequence& source);
//	  Postondition: a deep copy of the source Sequence replaces the current Sequence.
//                  Unused dynamic memory is deallocated.
//
// MODIFICATION MEMBER FUNCTIONS for the Sequence class:
//   void resize(int new_capacity)
//     Postcondition: The Sequence's current capacity is changed to the
//     new_capacity (but not less that the number of items already on the
//     list). The insert/attach functions will work efficiently (without
//     allocating new memory) until this new capacity is reached.
//
//   void start( )
//     Postcondition: The first item on the Sequence becomes the current item
//     (but if the Sequence is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     Sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the Sequence
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the Sequence. In either case, the newly
//     inserted item is now the current item of the Sequence.
//
//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the Sequence after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the Sequence. In either case, the newly
//     inserted item is now the current item of the Sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the Sequence, and the
//     item after this (if there is one) is now the new current item.
//	   else there is no current item.
//
// CONSTANT MEMBER FUNCTIONS for the Sequence class:
//   int size( ) const
//     Postcondition: The return value is the number of items in the Sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the Sequence.
//
// VALUE SEMANTICS for the Sequence class:
//    Assignments and the copy constructor may be used with Sequence objects.
//


#pragma once

typedef double value_type;

class Sequence
{
public:
	// TYPEDEFS and MEMBER CONSTANTS

	static const int DEFAULT_CAPACITY = 5;
	// CONSTRUCTORS and DESTRUCTOR
	Sequence(int initial_capacity = DEFAULT_CAPACITY);
	Sequence(const Sequence& source);
	~Sequence( );
	// MODIFICATION MEMBER FUNCTIONS
	void resize(int new_capacity);
	void start( );
	void advance( );
	void insert(const value_type& entry);
	void attach(const value_type& entry);
	void remove_current( );
	void operator =(const Sequence& source);
	// CONSTANT MEMBER FUNCTIONS
	int size( ) const;
	bool is_item( ) const;
	value_type current( ) const;
private:
	value_type* data;
	int used;
	int current_index;
	int capacity;
};
