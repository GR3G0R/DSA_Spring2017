//FILE: mainDll.cpp
//Due to it's bidirectional treversale capabilities, doubly linked list facilitate
//a simpler Implementation for many of the required functions with comparison to
//that of the singly linked list which can only be traveresed in one direction.
//Also, it is easier to delete nodes from doubly linked list when compared to
//singly linked list where it is required to set a pointere to the previous node;
//all nodes in a doubly linked list have pointers to the next and previous node.

#include "sequence_DLL.h"

using namespace delpe_sequenceDll_h;
using namespace std;

int main()
{
    SequenceDLL doubly_linked_list_seq;

    doubly_linked_list_seq.create_list(1);
    doubly_linked_list_seq.insert_first(2);
    doubly_linked_list_seq.insert_first(2);


    cout << "Raw Sequence: ";
    doubly_linked_list_seq.print();
    cout << endl;

    cout << "----------------------" << endl;

    cout << "Ostream Overload: " << doubly_linked_list_seq << endl;

    cout << "----------------------" << endl;

    doubly_linked_list_seq.insert_at(4,1);
    cout << "insert_at(4,1) -> " << doubly_linked_list_seq << endl;

    cout << "----------------------" << endl;

    doubly_linked_list_seq.erase_from(1);
    cout << "erase_from(1) -> " << doubly_linked_list_seq << endl;

    cout << "----------------------" << endl;

    cout << endl << "size() -> " << doubly_linked_list_seq.size() << endl;

    cout << endl << "count(2) -> " << doubly_linked_list_seq.count(2) << endl;

    cout << endl << "erase_first(2) -> ";
    doubly_linked_list_seq.erase_first(2);
    cout << doubly_linked_list_seq;

    doubly_linked_list_seq.insert_first(2);
    cout << endl << "insert_first(2) -> " << doubly_linked_list_seq << endl;

    doubly_linked_list_seq.insert_back(3);
    cout << endl << "insert_back(3) -> " << doubly_linked_list_seq << endl;

    doubly_linked_list_seq.erase_last(2);
    cout << endl << "erase_last(2) -> " << doubly_linked_list_seq << endl;

    doubly_linked_list_seq.insert_first(2);
    cout << endl << "insert_first(2) -> " << doubly_linked_list_seq << endl;

    doubly_linked_list_seq.erase_first(3);
    cout << endl << "erase_firt(3) -> " << doubly_linked_list_seq << endl;

    doubly_linked_list_seq.erase_occurrence(2,1);
    cout << endl << "erase_occurrence(2,1) -> " << doubly_linked_list_seq << endl;

    doubly_linked_list_seq.insert_first(2);
    cout << endl << "insert_first(2) -> " << doubly_linked_list_seq << endl;

    doubly_linked_list_seq.erase_from(1);
    cout << endl << "erase_from(1) -> " << doubly_linked_list_seq << endl;
}
