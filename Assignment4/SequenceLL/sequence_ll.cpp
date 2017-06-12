//  FILE: sequence_ll.cpp

#include <iostream>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include "node1.h"
#include "sequence_ll.h"

using namespace std;
//using namespace delpe_sequencell_h;

namespace delpe_sequencell_h
{
    //CONSTRUCTOR:
    SequenceLL::SequenceLL()
    {
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        node_count = 0;
    }

    SequenceLL::SequenceLL(const SequenceLL& seq)
    {
        node *tail_ptr;
        list_copy(seq.head_ptr,head_ptr,tail_ptr);
        node_count = seq.node_count;
    }

    void SequenceLL::start()
    {
        cursor = head_ptr;
        precursor = NULL;
    }

    bool SequenceLL::is_item() const
    {
        return (cursor != NULL);
    }

    void SequenceLL::advance()
    {
        assert(is_item());
        precursor = cursor;
        cursor = cursor->link();
    }

    void SequenceLL::insert_first(const value_type& element)
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

    void SequenceLL::attach(const value_type& element)
    {
        if(is_item())
        {
            if(cursor == tail_ptr)
            {
                precursor = cursor;
                list_insert(precursor, element);
                cursor = cursor->link();
                tail_ptr = tail_ptr->link();
            }
            else
            {
                precursor = cursor;
                list_insert(precursor, element);
                cursor = cursor->link();
            }
        }

        if(!is_item())
        {
            if((head_ptr == NULL) && (tail_ptr == NULL))
            {
                list_head_insert(head_ptr, element);
                cursor = head_ptr;
                precursor = NULL;
                tail_ptr = head_ptr;
            }
            else
            {
                precursor = list_locate(head_ptr, list_length(head_ptr));
                list_insert(precursor, element);
                cursor = precursor->link();
                tail_ptr = tail_ptr->link();
            }
        }
        ++node_count;
    }

    void SequenceLL::remove_current()
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

    void SequenceLL::erase_back()
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

    void SequenceLL::erase_first(const value_type& element)
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

    void SequenceLL::erase_last(const value_type& element)
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


    void SequenceLL::erase_occurrence(const value_type& element, const int& occurrence)
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

    void SequenceLL::erase_from(const size_type& INDEX)
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


    int SequenceLL::count(const value_type& element)
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

    void SequenceLL::insert(const value_type& element)
    {
        list_insert(tail_ptr,element);
        node_count++;
    }

    void SequenceLL::insert_at(const value_type& element, const size_type& index)
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

    void SequenceLL::operator=(const SequenceLL& seq)
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

    SequenceLL SequenceLL::operator+=(const SequenceLL& seq)
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

    SequenceLL operator+(const SequenceLL& seq1, const SequenceLL& seq2)
    {
        SequenceLL temp = seq1;

        temp += seq2;

        return temp;
    }

    bool operator==(const SequenceLL& seq1, const SequenceLL& seq2)
    {
       return seq1 == seq2;
    }

    std::ostream& operator<<(std::ostream& os, SequenceLL& seq)
    {
        int count = 0;
        os << "Seq:= {";
        for(seq.start(); seq.is_item(); seq.advance())
        {
            cout << seq.current();
            if(count < seq.size()-1)
            {
                os << ",";
                count++;
            }
        }
        os << "}" << std::endl;
        return os;
    }

    std::istream& operator>>(std::istream& is, const SequenceLL& seq)
    {
        SequenceLL::value_type element;

        is >> element;
        list_insert(seq.tail_ptr, element);

        return is;
    }

    void print_sequence(SequenceLL seq)
    {

        for(seq.start(); seq.is_item(); seq.advance())
        {
            cout << seq.current() << endl;
        }
    }

    SequenceLL::~SequenceLL()
    {
        list_clear(head_ptr);
        node_count = 0;
    }
}
