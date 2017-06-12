//  FILE: sequence.cpp

#include <iostream>
#include "sequence.h"

namespace delpe_sequence_h {

//Sequence constructors:
Sequence::Sequence(const Sequence& cap)
{

    data = new value_type[cap.capacity];
    capacity = cap.capacity;
    used = cap.used;

    for(size_type i = 0; i < used; i++)
    {
       data[i] = cap.data[i];
    }
}

Sequence::Sequence(size_type cap)
{

    data = new value_type[cap];
    capacity = cap;
    current_index = 0;
    used = 0;

}

//Overload assignment operator
void Sequence::operator=(const Sequence& seq)
{
    if(this == &seq) return; //Check for self assignment

    if(capacity != seq.capacity)
    {
        value_type *new_value_type = new value_type[seq.capacity];
        delete [] data;
        data = new_value_type;
        capacity = seq.capacity;
    }

    for(size_type i = 0; i < seq.used; i++)
    {
        data[i] = seq.data[i];
        used = seq.used;
    }
}

//Function expands capacity of sequence container
void Sequence::growSequence(size_type seq)
{
    if(capacity == seq) return;

    if(seq < used) seq = used;

    value_type *new_data = new value_type[seq];

    for(size_type i = 0; i < used; i++)
    {
        new_data[i] = data[i];
        delete [] data;
        data = new_data;
        capacity = seq;
    }
}

//Insertion modifire adds element to the end of sequence
void Sequence::insert(const value_type& element)
{

    if(used == capacity)
        growSequence(capacity + 1);
        data[used] = element;
        used++;
}

//Insert element into the zero index of sequence container
void Sequence::insert_first(const value_type& element)
{
    if(used == capacity)
        growSequence(capacity + 1);
        for(int i = used; i > 0; --i)
        {
            data[i] = data[i-1];
        }
        data[0] = element;
        used++;
}

//Insert element into any arbitrarily designated index of sequence
void Sequence::insert_at(const value_type& element, const size_type& index)
{
    if(used == capacity)
        growSequence(capacity + 1);

        used++;

        if(index+2 == used)
        {
            data[used] = element;
            for(int i = used; i > index; --i)
            {
                data[i] = data[i-1];
            }
        }

        if(index == 0)
        {
            for(int i = used; i > 0; --i)
            {
                data[i] = data[i-1];
            }
            data[0] = element;
        }

        for(int i = 0; i < used; i++)
        {
            if(data[i] == index)
            {
                for(int j = used; j > index; --j)
                {
                    data[j] = data[j-1];
                }
                break;
            }
        }
        data[index] = element;
}

//Remove element from sequence
bool Sequence::remove(const value_type& element)
{
    for(size_type i = 0; (i < used) && (data[i] != element); i++)
    {
        if(i == element) return false;
        data[i] = data[i+1];
    }
    used--;
    return true;
}

//Function points to current_index of Sequence object
void Sequence::start()
{
    current_index = 0;
}

//Test for empty sequence
bool Sequence::is_item() const
{
    if(current_index < used) { return true; }
    else return false;
}

//Return current element of Sequence
Sequence::value_type Sequence::current() const
{
    return data[current_index];
}

//Move to next element of sequence
void Sequence::advance()
{
    if((is_item() == true) && (current_index != used)) current_index++;
}

//Erase initial (zero index) value of sequence
bool Sequence::erase_first(const value_type& element)
{
    int count = 0;
    for(int i = 0; i < used; i++)
    {
        count++;
        if(data[i] == element)
        {
            for(int j = count-1; j < used; j++)
            {
                data[j] = data[j+1];
            }
            break;
        }
    }
    used--;
    return true;
}

//Erase last element in sequence
bool Sequence::erase_last(const value_type& element)
{
    int count = 0;
    for(int i = used; i > 0; --i)
    {
        count++;
        if(data[i] == element)
        {
            for(int j = (used-(count-1)); j < used; j++)
            {
                data[j] = data[j+1];
            }
            break;
        }
    }
    used--;
    return true;
}

//Erase occurance of designated element
bool Sequence::erase_occurrence(const value_type& element, const int& occurence)
{
    //Sequence counts;
    int count = 0, occurred = 0;
    for(int i = 0; i < used; i++)
    {
        count++;
        if(data[i] == element)
        {
            occurred++;
            if(occurred == occurence)
            {
            //counts.insert(count);
                for(int j = count-1; j < used; j++)
                {
                    //int index = counts.getData(occurence);
                    data[j] = data[j+1];
                }
                break;
            }
        }
    }
    used--;
    return true;
}

//Remove element @ INDEX
bool Sequence::erase_from(const size_type& INDEX)
{
    for(int j = INDEX; j < used; j++)
    {
        data[j] = data[j+1];
    }
    used--;
    return true;
}

//Count number of element in sequence
int Sequence::count(const value_type& element)
{
    int count = 0;
    for(int i = 0; i < used; i++)
    {
        if(data[i] == element) count++;
    }
    return count;
}

//Overload combination assignment operator
void Sequence::operator+=(const Sequence& seq)
{
    if(used + seq.used > capacity)
    {
        growSequence(used + seq.used);
    }

    for(size_type i = 0; i < seq.used; i++)
    {
        data[used+i] = seq.data[i];
        used += seq.used;
    }
}

//Overload addition operator
Sequence operator+(const Sequence& seq1, const Sequence& seq2)
{
    Sequence add(seq1.capacity + seq2.capacity);

    add += seq1;
    add += seq2;

    return add;
}

//Print each elememt in sequence
void Sequence::print_sequence () const
{
    for(size_type i = 0; i < used; i++)
    {
        std::cout << data[i] << std::endl;
    }
}

//Overload equality operator 
bool operator==(const Sequence& seq1, const Sequence& seq2)
{
    int i =0;
    return seq1.data[i] == seq2.data[i];
}

//Overload non-equality operator
bool operator!=(const Sequence& seq1, const Sequence& seq2)
{
    return !(seq1 == seq2);
}

//Overload ostream operator
std::ostream& operator<<(std::ostream& os, const Sequence& seq)
{
    int count = 0;
    os << "Seq:= {";
   for(int i = 0,len = seq.size(); i < len; i++)
   {
        os << seq.data[i];
            if(count < seq.size()-1) { os << ","; count++; }
   }
   os << "}" << std::endl;
   return os;
}

//Overload istream operator
std::istream& operator>>(std::istream& is, const Sequence& seq)
{
    int i;
    std::size_t current_index;
    double element;

    is >> current_index >> i >> element;

    seq.data[i] = current_index;
    seq.data[i] = element;

    return is;
}

//Sequence class destructor
Sequence::~Sequence() { delete [] data; }

}
