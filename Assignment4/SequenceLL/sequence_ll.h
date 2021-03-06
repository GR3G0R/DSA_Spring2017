//  FILE: sequence_ll.h
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
#include "node2.h"
#include "node1.h"

namespace delpe_sequencell_h 
{

    class SequenceLL 
    {
        public:
            typedef double value_type;
            typedef std::size_t size_type;

            SequenceLL();
            SequenceLL(const SequenceLL& seq);

            void start();
            void advance();
            void insert(const value_type& element);
            void attach(const value_type& element);
            void remove_current();
            void erase_back();

            void erase_first(const value_type& element);
            void erase_last(const value_type& element);
            void erase_occurrence(const value_type& element,const int& occurrence);
            void erase_from(const size_type& INDEX);

            int count(const value_type& element);

            void insert_first(const value_type& element);
            void insert_at(const value_type& element, const size_type& index);

            void operator=(const SequenceLL& seq);
            SequenceLL operator+=(const SequenceLL& seq);

            //void print_sequence(SequenceLL seq);

            friend SequenceLL operator+(const SequenceLL& seq1, const SequenceLL& seq2);
            friend bool operator==(const SequenceLL& seq1, const SequenceLL& seq2);
            friend bool operator!=(const SequenceLL& seq1, const SequenceLL& seq2);

            friend std::ostream& operator<<(std::ostream& os, SequenceLL& seq);
            friend std::istream& operator>>(std::istream& is, const SequenceLL& seq);



            size_type size() { return node_count; }
            bool is_item() const;
            value_type current() const { return cursor->data(); }



            /*size_type size() const { return used; }
            void growSequence(size_type seq);
            void insert(const value_type& element);
            bool remove(const value_type& element);
           //value_type getData(const int& index) { return data[index]; }
            value_type* getData() const { return data; }

            void start();
            bool is_item() const;
            value_type current() const;
            void advance();

            bool erase_first(const value_type& element);
            bool erase_last(const value_type& element);
            bool erase_occurrence(const value_type& element,const int& occurrence);
            bool erase_from(const size_type& INDEX);

            int count(const value_type& element);

            void insert_first(const value_type& element);
            void insert_at(const value_type& element, const size_type& index);

            void operator=(const Sequence& seq);
            void operator+=(const Sequence& seq);
            value_type& operator[](int x) { return data[x]; }

            void print_sequence () const;

            friend Sequence operator+(const Sequence& seq1, const Sequence& seq2);
            friend bool operator==(const Sequence& seq1, const Sequence& seq2);
            friend bool operator!=(const Sequence& seq1, const Sequence& seq2);

            friend std::ostream& operator<<(std::ostream& os, const Sequence& seq);
            friend std::istream& operator>>(std::istream& os, const Sequence& seq);*/


            ~SequenceLL();

        private:
            node* head_ptr;
            node* tail_ptr;
            node* cursor;
            node* precursor;
            size_type node_count;

    };

    void print_sequence(SequenceLL seq);

    std::ostream& operator<<(std::ostream& os, SequenceLL& seq);
    std::istream& operator>>(std::istream& is, const SequenceLL& seq);


    SequenceLL operator+(const SequenceLL& seq1, const SequenceLL& seq2);
    bool operator!=(const SequenceLL& seq1, const SequenceLL& seq2);
    bool operator==(const SequenceLL& seq1, const SequenceLL& seq2);

}

#endif
