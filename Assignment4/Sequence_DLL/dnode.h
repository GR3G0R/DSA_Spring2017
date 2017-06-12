// FILE: dnode.h
// PROVIDES: A class for a node in a doubly linked list, and list manipulation
// functions, all within the namespace main_savitch_5
//
// TYPEDEF for the dnode class:
//     Each node of the list contains a piece of data and a pointers to the
//     previous and next nodes. The type of the data is defined as
//     dnode::value_type in a typedef statement. The value_type may be any
//     of the built-in C++ classes (int, char, ...) or a class with a copy
//     constructor, an assignment operator, and a test for equality (x == y).
//
// CONSTRUCTOR for the dnode class:
//   dnode(
//     const value_type& init_data = value_type(),
//     node* init_fore = NULL,
//     node* init_back = NULL
//   )
//     Postcondition: The node contains the specified data and links.
//     NOTE: The default value for the init_data is obtained from the default
//     constructor of the value_type. In the ANSI/ISO standard, this notation
//     is also allowed for the built-in types, providing a default value of
//     zero. Both links have a default value of NULL.
//
// NOTE:
//   Some of the functions have a return value which is a pointer to a node.
//   Each of these  functions comes in two versions: a non-const version (where
//   the return value is dnode*) and a const version (where the return value
//   is const dnode*).
// EXAMPLES:
//    const dnode *c;
//    c->fore( ) activates the const version of fore
//    node *p;
//    p->fore( ) activates the non-const version of fore
//
// MEMBER FUNCTIONS for the dnode class:
//   void set_data(const value_type& new_data)
//     Postcondition: The node now contains the specified new data.
//
//   void set_fore(node* new_fore)
//   and
//   void set_back(node* new_back)
//     Postcondition: The node now contains the specified new link.
//
//   value_type data( ) const
//     Postcondition: The return value is the data from this dnode.
//
//   const node* fore( ) const <----- const version
//   node* fore( ) <----------------- non-const version
//   const node* back( ) const <----- const version
//   node* back( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is a link from this dnode.

#ifndef DELPE_SEQUENCEDLL_H
#define DELPE_SEQUENCEDLL_H
#include <cstdlib> // Provides size_t and NULL

namespace delpe_sequenceDll_h
{
    class dnode
    {
    public:
        //TYPEDEF
	      typedef double value_type;

	      //CONSTRUCTOR
	      dnode(const value_type& init_data = value_type( ),
                dnode* init_fwd = NULL, dnode* init_prev = NULL)
        {
            data_field = init_data;
		        link_fwd = init_fwd;
		        link_prev = init_prev;
	      }

	      //Member functions to set the data and link fields:
    	  void set_data(const value_type& new_data) { data_field = new_data; }
    	  void set_fwd(dnode* new_fwd) { link_fwd = new_fwd; }
    	  void set_prev(dnode* new_prev) { link_prev = new_prev; }

	      //Const member function to retrieve the current data:
	      value_type data( ) const { return data_field; }

	      //Two slightly different member functions to retrieve each current link:
	      const dnode* fwd( ) const { return link_fwd; }
    	  dnode* fwd( ) { return link_fwd; }
	      const dnode* prev( ) const { return link_prev; }
    	  dnode* prev( ) { return link_prev; }
    private:
	      value_type data_field;
	      dnode *link_fwd;
	      dnode *link_prev;
    };

}

#endif
