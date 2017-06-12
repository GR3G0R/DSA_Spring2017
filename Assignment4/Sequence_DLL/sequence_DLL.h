//  FILE: sequence.h
//  CLASS PROVIDED: Sequence (part or namespace delpe_sequence_h)
//
//  CONSTRUCTOR for sequence class:
//    Sequence()
//    Postcondition: sequence has been initialized as an empty sequence
//
//  MEMBER FUNCTIONS for sequence class:
//    size_type size() const
//    Postcondition: The returned value is number of items contained in sequence
//
//    void insert(const value_type& entry)
//    Postcondition: A new copy of entry has been inserted in the sequence
//    before the current item. If current item does not exist then new entry
//    is inserted at the front of sequence. In either case, the new item is
//    now the current item of sequence.
//
//    bool erase_first()
//    Postcondition: remove first occurance of value
//
//    bool erase_last()
//    Postcondition: remove last occurance of value
//
//    bool erase_occurrence()
//    Postcondition: remove the occurance of specified value
//
//    bool erase_from()
//    Precondition: accepts INDEX of an element
//    Postcondition: erases the element from that index
//
//    int count()
//    Postcondition: count occurrence of a value
//
//    void insert_first()
//    Postcondition:inserts an element as the first index
//
//    void insert_at()
//    Postcondition: insert some element at a specific index
//
//    void print_sequence()
//    Postcondition: prints each element in index
//
//    void insert()
//    Postcondition: insert to the end of the sequence
//
//    std::ostream& operator<<(std::ostream& os, const Sequence& seq);
//    Postcondition: ostream operator overload to facilitate printing  sequence
//
//    std::istream& operator>>(std::istream& os, const Sequence& seq);
//    Postcondition: instream operator to retrive user input
//
//    Sequence operator+(const Sequence& seq1, const Sequence& seq2);
//    Postcondition: connects a sequence to a number and return the result
//
//    bool operator!=(const Sequence& seq1, const Sequence& seq2);
//    Postcondition: connects a sequence to a number and return the result
//
//    bool operator==(const Sequence& seq1, const Sequence& seq2);
//    Postcondition: verifies equality of two sequences
//
//  DESTRUCTOR
//    ~Sequence()
//    Postcondition: dealocate dynamic memory when Sequence object is out of scope
//
//  VALUE SEMANTICS for the sequence class:
//    Assignment and copy constructor may be used with sequence object

#ifndef DELPE_SEQUENCELL_H
#define DELPE_SEQUENCELL_H
#include <iostream>
#include "dnode.h"

namespace delpe_sequenceDll_h
{

    class SequenceDLL
    {
        public:
            typedef double value_type;
            typedef std::size_t size_type;

            SequenceDLL();
            SequenceDLL(const SequenceDLL& seq);

            void create_list(const value_type& element);
            void print();
            void start();
            void advance();
            void insert(const value_type& element);
            void insert_back(const value_type& element);
            void attach(const value_type& element);
            void reverse();
            void remove_current();
            void erase_back();

            void erase_first(const value_type& element);
            void erase_last(const value_type& element);
            void erase_occurrence(const value_type& element,const int& occurrence);
            void erase_from(const size_type& INDEX);

            int count(const value_type& element);
            //void size();

            void insert_first(const value_type& element);
            void insert_at(const value_type& element, int index);
            //void insert_at(const value_type& element, const size_type& index);

            SequenceDLL operator=(const SequenceDLL& seq);
            SequenceDLL operator+=(const SequenceDLL& seq);

            //void print_sequence(SequenceDLL seq);

            friend SequenceDLL operator+(const SequenceDLL& seq1, const SequenceDLL& seq2);
            friend bool operator==(const SequenceDLL& seq1, const SequenceDLL& seq2);
            friend bool operator!=(const SequenceDLL& seq1, const SequenceDLL& seq2);

            friend std::ostream& operator<<(std::ostream& os, SequenceDLL& seq);
            friend std::istream& operator>>(std::istream& is, const SequenceDLL& seq);



            size_type size();
            bool is_item() const;
            value_type current() const { return cursor->data(); }

            ~SequenceDLL();

        private:
            dnode* head_ptr;
            dnode* tail_ptr;
            dnode* cursor;
            dnode* precursor;
            size_type node_count;

    };

    void print_sequence(SequenceDLL seq);

    std::ostream& operator<<(std::ostream& os, SequenceDLL& seq);
    std::istream& operator>>(std::istream& is, const SequenceDLL& seq);


    SequenceDLL operator+(const SequenceDLL& seq1, const SequenceDLL& seq2);
    bool operator!=(const SequenceDLL& seq1, const SequenceDLL& seq2);
    bool operator==(const SequenceDLL& seq1, const SequenceDLL& seq2);

}

#endif
