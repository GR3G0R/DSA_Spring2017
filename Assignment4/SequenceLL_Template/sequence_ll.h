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
    template<class Item>
    class SequenceLL
    {
        public:
            typedef Item value_type;
            typedef Item size_type;

            SequenceLL()
            {
                head_ptr = NULL;
                tail_ptr = NULL;
                cursor = NULL;
                precursor = NULL;
                node_count = 0;
            }

            SequenceLL(const SequenceLL& seq)
            {
                node *tail_ptr;
                list_copy(seq.head_ptr,head_ptr,tail_ptr);
                node_count = seq.node_count;
            }

            void start()
            {
                cursor = head_ptr;
                precursor = NULL;
            }

            void advance()
            {
                assert(is_item());
                precursor = cursor;
                cursor = cursor->link();
            }

            void insert(const value_type& element)
            {
                list_insert(tail_ptr,element);
                node_count++;
            }

            void remove_current()
            {
                node *temp_ptr;
                value_type temp;

                temp = cursor->data();
                temp_ptr = list_search(head_ptr, temp);

                if((temp_ptr != NULL) && (head_ptr != NULL))
                {
                    temp_ptr->set_data(head_ptr->data());
                    list_head_remove(head_ptr);
                    --node_count;
                }

                if(temp_ptr == head_ptr)
                {
                    list_head_remove(head_ptr);
                    --node_count;
                }

                if(temp_ptr->link() == NULL)
                {
                    temp_ptr->set_data(head_ptr->data());
                    list_head_remove(head_ptr);
                    cursor = head_ptr;
                    precursor->set_link(NULL);
                    tail_ptr = precursor;
                    --node_count;
                }
            }

            void erase_back()
            {
                node *one = head_ptr;
                node *two = head_ptr->link();
                while(two->link() != NULL)
                {
                    two = two->link();
                    one = one->link();
                }
                two->set_data(one->data());
                list_remove(one);
            }

            void erase_first(const value_type& element)
            {
                node *temp_ptr;

                temp_ptr = list_search(head_ptr, element);

                if(temp_ptr != tail_ptr)
                {
                temp_ptr->set_data((temp_ptr->link())->data());

                list_remove(temp_ptr);
                }
                if(temp_ptr == tail_ptr)
                {
                    erase_back();
                }
                --node_count;
            }

            void erase_last(const value_type& element)
            {
                value_type count = 0, occurrence = 0;
                for(node *cursor = head_ptr; cursor != NULL; cursor = cursor->link())
                {
                    if(cursor->data() == element) count++;
                }
                if(count == 1) erase_first(element);
                if(count > 1)
                {
                    for(node *cursor = list_search(head_ptr,element); cursor != NULL; cursor = cursor->link())
                    {
                        occurrence++;
                    }
                    node *temp_ptr = list_locate(head_ptr,occurrence);
                    list_remove(temp_ptr);
                }
                node_count--;
            }

            void erase_occurrence(const value_type& element,const Item& occurrence)
            {
                value_type count = 0, occurred = 0;
                for(node *cursor = head_ptr; cursor != NULL; cursor = cursor->link())
                {
                    count++;
                    if(cursor->data() == element)
                    {
                        occurred++;
                        if(occurred == occurrence)
                        {
                            list_remove(list_locate(head_ptr,count-1));
                            --node_count;
                        }
                    }
                }
            }

            void erase_from(const size_type& INDEX)
            {
                node *temp_ptr;
                if(INDEX == 0)
                {
                    remove_current();
                }
                else if((INDEX >= 1) && (temp_ptr != tail_ptr))
                {
                    temp_ptr = list_locate(head_ptr,INDEX);
                    list_remove(temp_ptr);
                }
                else
                {
                    erase_back();
                }
                --node_count;
            }

            int count(const value_type& element)
            {
                size_type count = 0;
                for(node *cursor = head_ptr; cursor != NULL; cursor = cursor->link())
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
                if((precursor == NULL) || (!is_item()))
                {
                    list_head_insert(head_ptr, element);
                    cursor = head_ptr;
                    precursor = NULL;

                    if(node_count == 0)
                    {
                        tail_ptr = head_ptr;
                    }
                }
                else
                {
                    list_insert(precursor,element);
                    cursor = precursor->link();
                }

                ++node_count;
            }

            void insert_at(const value_type& element, const size_type& index)
            {
                node *temp_ptr = list_locate(head_ptr,index+1);
                if(index == 0)
                {
                    insert_first(element);
                    ++node_count;
                }

                if((index != 0) && (temp_ptr != tail_ptr))
                {
                    list_insert(temp_ptr,element);
                }
                if(temp_ptr == tail_ptr)
                {
                    insert(element);
                }
                node_count++;
            }

            void operator=(const SequenceLL& seq)
            {
                if(this == &seq) return;

                if (seq.cursor == NULL)
                {
                    list_copy(seq.head_ptr, head_ptr, tail_ptr);
                    cursor = NULL;
                    precursor = NULL;
                }
                if (seq.node_count == 1)
                {
                    list_copy(seq.head_ptr, head_ptr, tail_ptr);
                    cursor = head_ptr;
                    precursor = NULL;
                }

                if (seq.node_count > 1)
                {
                    list_piece(seq.head_ptr, seq.cursor, head_ptr, precursor);
                    list_piece(seq.cursor, NULL, cursor, tail_ptr);
                    precursor->set_link(cursor);
                }

                node_count = seq.node_count;

                return;
            }

            SequenceLL operator+=(const SequenceLL& seq)
            {
                node *interate = seq.head_ptr;
                value_type x;
                value_type *addr_x = &x;

                while(interate != NULL)
                {
                    x = interate->data();
                    list_insert(tail_ptr, *addr_x);
                    interate = interate->link();
                }
                return *this;
            }


            friend SequenceLL operator+(const SequenceLL& seq1, const SequenceLL& seq2);
            friend bool operator==(const SequenceLL& seq1, const SequenceLL& seq2);
            friend bool operator!=(const SequenceLL& seq1, const SequenceLL& seq2);

            template<class Stream>
            friend std::ostream& operator<<(std::ostream& os, SequenceLL<Stream>& seq);

            template<class Stream>
            friend std::istream& operator>>(std::istream& is, const SequenceLL<Stream>& seq);

            size_type size() { return node_count; }

            bool is_item() const
            {
                return (cursor != NULL);
            }

            value_type current() const { return cursor->data(); }

            ~SequenceLL()
            {
                list_clear(head_ptr);
                node_count = 0;
            }

        private:
            node* head_ptr;
            node* tail_ptr;
            node* cursor;
            node* precursor;
            size_type node_count;

    };

    template<class Item>
    void print_sequence(SequenceLL<Item> seq);

    template<class Item>
    std::ostream& operator<<(std::ostream& os, SequenceLL<Item>& seq);

    template<class Item>
    std::istream& operator>>(std::istream& is, const SequenceLL<Item>& seq);


    template<class Item>
    Item operator+(const SequenceLL<Item>& seq1, const SequenceLL<Item>& seq2);

    template<class Item>
    bool operator!=(const SequenceLL<Item>& seq1, const SequenceLL<Item>& seq2);

    template<class Item>
    bool operator==(const SequenceLL<Item>& seq1, const SequenceLL<Item>& seq2);

}

#include "sequence_ll.template"
#endif
