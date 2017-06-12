//FILE: sequence_Dll.cpp

#include "sequence_DLL.h"

namespace delpe_sequenceDll_h
{
    SequenceDLL::SequenceDLL()
    {
        head_ptr = NULL;
    }

    SequenceDLL::SequenceDLL(const SequenceDLL& seq)
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

    SequenceDLL::~SequenceDLL()
    {
        while(head_ptr != NULL)
        {
            dnode *remove_ptr = head_ptr;
            head_ptr = head_ptr->fwd();
            delete remove_ptr;
        }
    }

    void SequenceDLL::create_list(const value_type& element)
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

    void SequenceDLL::print()
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

   void SequenceDLL::insert_first(const value_type& element)
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

   void SequenceDLL::insert_back(const value_type& element)
   {
       reverse();
       insert_first(element);
       reverse();
   }

   void SequenceDLL::insert_at(const value_type& element, int index)
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

   void SequenceDLL::erase_back()
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

   void SequenceDLL::erase_first(const value_type& element)
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

   int SequenceDLL::count(const value_type& element)
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

   void SequenceDLL::erase_last(const value_type& element)
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

   void SequenceDLL::erase_occurrence(const value_type& element, const int& occurrence)
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

   void SequenceDLL::erase_from(const size_type& INDEX)
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
       else
       {
           erase_back();
       }
   }

   SequenceDLL::size_type SequenceDLL::size()
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

   void SequenceDLL::reverse()
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

   std::ostream& operator<<(std::ostream& os, SequenceDLL& seq)
   {
        int count = 0;
        os << "Seq:= {";
        dnode *cursor = seq.head_ptr;
        while(cursor != NULL)
        {
            std::cout << cursor->data();
            if(count < seq.size()-1)
            {
                os << ",";
                count++;
            }
            cursor = cursor->fwd();
        }
        os << "}" << std::endl;
        return os;
   }

   std::istream& operator>>(std::istream& is, SequenceDLL& seq)
   {
       SequenceDLL::value_type element;

       is >> element;

       seq.insert_back(element);

       return is;
   }

   SequenceDLL  SequenceDLL::operator=(const SequenceDLL& seq)
   {
       SequenceDLL temp(seq);
       std::swap(temp.head_ptr,head_ptr);
       return *this;
   }

   SequenceDLL SequenceDLL::operator+=(const SequenceDLL& seq)
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

   SequenceDLL operator+(const SequenceDLL& seq1, const SequenceDLL& seq2)
   {
       SequenceDLL temp = seq1;

       temp += seq2;

       return temp;
   }

   bool operator==(const SequenceDLL& seq1, const SequenceDLL& seq2)
   {
       return seq1 == seq2;
   }
}
