// File: main.cpp

#include <iostream>
#include <cstdlib>
#include "node1.h"
#include "sequence_ll.h"

using namespace delpe_sequencell_h;
using namespace std;

int main()
{
    SequenceLL linked_list_seq;
    linked_list_seq.insert_first(2);
    linked_list_seq.insert_first(6);
    linked_list_seq.insert_first(8);
    linked_list_seq.insert_first(6);
    linked_list_seq.insert_first(5);
    linked_list_seq.insert_first(7);

    cout << "Raw Sequence: " << endl;
    print_sequence(linked_list_seq);

    cout << "----------------------" << endl;

    cout << "Ostream Overload -> " << linked_list_seq << endl;

    cout << "----------------------" << endl;

    linked_list_seq.erase_from(2);
    cout << endl << "erase_from(2) -> " << linked_list_seq << endl;

    cout << endl << "size() -> " << linked_list_seq.size() << endl;

    cout << endl << "count(6) -> " << linked_list_seq.count(6) << endl;

    linked_list_seq.insert_first(2);
    cout << endl << "insert_first(2) -> " << linked_list_seq << endl;

    linked_list_seq.insert(1);
    cout << "insert(1) -> " << linked_list_seq << endl;

    linked_list_seq.erase_first(2);
    cout << "erase_first(2) -> " << linked_list_seq << endl;

    linked_list_seq.insert_first(5);
    cout << "insert_first(5) -> " << linked_list_seq << endl;

    linked_list_seq.insert_at(9,3);
    cout << "insert_at(9,3) -> " << linked_list_seq << endl;
}
