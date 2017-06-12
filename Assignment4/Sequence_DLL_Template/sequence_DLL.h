//  FILE: sequence_DLL.h
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

    template<class Item>
    class SequenceDLL
    {
        public:
            typedef Item value_type;
            typedef std::size_t size_type;

            SequenceDLL() { head_ptr = NULL; }

            SequenceDLL(const SequenceDLL& seq)
            {
                head_ptr = NULL;
                tail_ptr = NULL;
                dnode * temp_ptr = seq.head_ptr;

                if(temp_ptr != NULL) return;

                insert_first((temp_ptr)->data());
                tail_ptr = head_ptr;

                temp_ptr = temp_ptr->fwd();
                while(temp_ptr != NULL)
                {
                    insert_back(temp_ptr->data());
                    tail_ptr = tail_ptr->fwd();
                    temp_ptr = temp_ptr->fwd();
                }
            }

            void create_list(const value_type& element)
            {
                dnode *cursor, *temp_ptr;
                temp_ptr = new(dnode);
                temp_ptr->set_data(element);
                temp_ptr->set_fwd(NULL);
                if(head_ptr == NULL)
                {
                    temp_ptr->set_prev(NULL);
                    head_ptr = temp_ptr;
                }
                else
                {
                    cursor = head_ptr;
                    while(cursor->fwd() != NULL) cursor = cursor->fwd();
                    cursor->set_fwd(temp_ptr);
                    temp_ptr->set_prev(cursor);
                }
            }

            void print()
            {
                dnode *cursor;
                if(head_ptr == NULL)
                {
                    return;
                }
                cursor = head_ptr;
                while(cursor != NULL)
                {
                    std::cout << cursor->data();
                    cursor = cursor->fwd();
                }
            }

            void insert_back(const value_type& element)
            {
                reverse();
                insert_first(element);
                reverse();
            }

            void reverse()
            {
                dnode *p1, *p2;
                p1 = head_ptr;
                p2 = p1->fwd();
                p1->set_fwd(NULL);
                p1->set_prev(p2);
                while(p2 != NULL)
                {
                    p2->set_prev(p2->fwd());
                    p2->set_fwd(p1);
                    p1 = p2;
                    p2 = p2->prev();
                }
                head_ptr = p1;
            }

            void erase_back()
            {
                if(head_ptr == NULL) return;

                dnode *temp_ptr = head_ptr;
                if(temp_ptr->prev() == temp_ptr->fwd())
                {
                    head_ptr = NULL;
                    delete temp_ptr;
                }
                else {
                    while(temp_ptr->fwd() != NULL)
                    {
                        temp_ptr = temp_ptr->fwd();
                        (temp_ptr->prev())->set_fwd(NULL);
                        delete temp_ptr;
                    }
                }
            }

            void erase_first(const value_type& element)
            {
                dnode *temp_ptr, *cursor;
                if(head_ptr->data() == element)
                {
                    temp_ptr = head_ptr;
                    head_ptr = head_ptr->fwd();
                    head_ptr->set_prev(NULL);
                    delete temp_ptr;
                    return;
                }
                cursor = head_ptr;
                while(cursor->fwd()->fwd() != NULL)
                {
                    if((cursor->fwd())->data() == element)
                    {
                        temp_ptr = cursor->fwd();
                        cursor->set_fwd(temp_ptr->fwd());
                        (temp_ptr->fwd())->set_prev(cursor);
                        delete temp_ptr;
                        return;
                    }
                    cursor = cursor->fwd();
                }
                if(cursor->fwd()->data() == element)
                {
                    temp_ptr = cursor->fwd();
                    delete temp_ptr;
                    cursor->set_fwd(NULL);
                    return;
                }
            }

            void erase_last(const value_type& element)
            {
                reverse();
                dnode *temp_ptr, *cursor;
                if(head_ptr->data() == element)
                {
                    temp_ptr = head_ptr;
                    head_ptr = head_ptr->fwd();
                    head_ptr->set_prev(NULL);
                    delete temp_ptr;
                    return;
                }
                cursor = head_ptr;
                while(cursor->fwd()->fwd() != NULL)
                {
                    if((cursor->fwd())->data() == element)
                    {
                        temp_ptr = cursor->fwd();
                        cursor->set_fwd(temp_ptr->fwd());
                        (temp_ptr->fwd())->set_prev(cursor);
                        delete temp_ptr;
                        reverse();
                        return;
                    }
                    cursor = cursor->fwd();
                }
                if((cursor->fwd())->data() == element)
                {
                    temp_ptr = cursor->fwd();
                    delete temp_ptr;
                    cursor->set_fwd(NULL);
                    return;
                }
            }

            void erase_occurrence(const value_type& element,const int& occurrence)
            {
                value_type count = 0,occured = 0;
                dnode *temp_ptr;
                for(dnode *cursor = head_ptr; cursor != NULL; cursor = cursor->fwd())
                {
                    count++;
                    if((cursor->fwd())->data() == element)
                    {
                        occured++;
                        if(occured == occurrence)
                        {
                            temp_ptr = cursor->fwd();
                            cursor->set_fwd(temp_ptr->fwd());
                            (temp_ptr->fwd())->set_prev(cursor);
                            delete temp_ptr;
                            return;
                        }
                    }
                }
            }

            void erase_from(const size_type& INDEX)
            {
                dnode *temp_ptr = head_ptr;
                if(INDEX == 0)
                {
                    if(temp_ptr->prev() == temp_ptr->fwd())
                    {
                        head_ptr = NULL;
                        delete temp_ptr;
                    }
                    else {
                        head_ptr = temp_ptr->fwd();
                        head_ptr->set_prev(NULL);
                        delete temp_ptr;
                    }
                }

                if((INDEX >= 1) && (temp_ptr != tail_ptr))
                {
                    dnode *cursor;
	                  size_t i;

	                  cursor = head_ptr;
	                  for (i = 1; (i < INDEX) && (cursor != NULL); i++)
	                  cursor = cursor->fwd();
	                  temp_ptr = cursor;
                    dnode *remove_ptr = temp_ptr->fwd();
                    temp_ptr->set_fwd(remove_ptr->fwd());
                    delete remove_ptr;
                }
                else {
                    erase_back();
                }
            }

            int count(const value_type& element)
            {
                size_type count = 0;
                for(dnode *cursor = head_ptr; cursor != NULL; cursor = cursor->fwd())
                {
                    if(cursor->data() == element)
                    {
                        count++;
                    }
                }
                return count;
            }

            void insert_first(const value_type& element)
            {
                if(head_ptr == NULL)
                {
                    return;
                }
                dnode *temp_ptr;
                temp_ptr = new(dnode);
                temp_ptr->set_prev(NULL);
                temp_ptr->set_data(element);
                temp_ptr->set_fwd(head_ptr);
                head_ptr->set_prev(temp_ptr);
                head_ptr = temp_ptr;
            }

            void insert_at(const value_type& element, int index)
            {
                if(head_ptr == NULL)
                {
                    return;
                }
                dnode *temp_ptr, *cursor;
                cursor = head_ptr;
                for(int i = 0; i < index - 1; i++)
                {
                    cursor = cursor->fwd();
                    if(cursor == NULL)
                    {
                        return;
                    }
                }
                temp_ptr = new(dnode);
                temp_ptr->set_data(element);
                if(cursor->fwd() == NULL)
                {
                    cursor->set_fwd(temp_ptr);
                    temp_ptr->set_fwd(NULL);
                    temp_ptr->set_prev(cursor);
                }
                else
                {
                    temp_ptr->set_fwd(cursor->fwd());
                    (temp_ptr->fwd())->set_prev(temp_ptr);
                    cursor->set_fwd(temp_ptr);
                    temp_ptr->set_prev(cursor);
                }
            }

            SequenceDLL operator=(const SequenceDLL& seq)
            {
                SequenceDLL temp(seq);
                std::swap(temp.head_ptr,head_ptr);
                return *this;
            }

            SequenceDLL operator+=(const SequenceDLL& seq)
            {
                dnode *interate = seq.head_ptr;
                value_type x;
                value_type *addr_x = &x;

                while(interate != NULL)
                {
                    x = interate->data();
                    insert_back(*addr_x);
                    interate = interate->fwd();
                }
                return *this;
            }


            friend SequenceDLL operator+(const SequenceDLL& seq1, const SequenceDLL& seq2);

            friend bool operator==(const SequenceDLL& seq1, const SequenceDLL& seq2);

            template<class Stream>
            friend std::ostream& operator<<(std::ostream& os, SequenceDLL<Stream>& seq);

            template<class Stream>
            friend std::istream& operator>>(std::istream& is, const SequenceDLL<Stream>& seq);



            size_type size()
            {
                dnode *cursor = head_ptr;
                int count = 0;
                while(cursor != NULL)
                {
                    cursor = cursor->fwd();
                    count++;
                }
                return count;
            }

            value_type current() const { return cursor->data(); }

            ~SequenceDLL()
            {
                while(head_ptr != NULL)
                {
                    dnode *remove_ptr = head_ptr;
                    head_ptr = head_ptr->fwd();
                    delete remove_ptr;
                }
            }

        private:
            dnode* head_ptr;
            dnode* tail_ptr;
            dnode* cursor;
            dnode* precursor;
            size_type node_count;

    };

    template<class Item>
    void print_sequence(SequenceDLL<Item> seq);

    template<class Item>
    std::ostream& operator<<(std::ostream& os, SequenceDLL<Item>& seq);

    template<class Item>
    std::istream& operator>>(std::istream& is, const SequenceDLL<Item>& seq);


    template<class Item>
    Item operator+(const SequenceDLL<Item>& seq1, const SequenceDLL<Item>& seq2);

    template<class Item>
    bool operator==(const SequenceDLL<Item>& seq1, const SequenceDLL<Item>& seq2);

}

#include "sequence_DLL.template"
#endif
