//Gregory Delpe
//Assignment#5: Templated Hashtable With Linkedlist->BST Optimization
//FILE: main.cpp

#include <iostream>
#include "hashtable.h"

using namespace std;
using namespace delpe_hashtable_h;

int main() {
    HashTable<int> hash_test;

    cout << "20 Record Hashtable Of Linkedlist:" << endl << endl;

    hash_test.put(1,4);
    hash_test.put(2,1);
    hash_test.put(3,5);
    hash_test.put(3,11);
    hash_test.put(3,6);
    hash_test.put(3,7);
    hash_test.put(3,9);
    hash_test.put(3,2);
    hash_test.put(4,4);
    hash_test.put(5,4);
    hash_test.put(6,4);
    hash_test.put(7,4);
    hash_test.put(8,4);
    hash_test.put(9,4);
    hash_test.put(10,4);
    hash_test.put(11,4);
    hash_test.put(12,4);
    hash_test.put(13,4);

    hash_test.show_table();
    cout << "Record 3 (Linkedlist): ";
    hash_test.get(3);
    cout << endl;
    cout << "Table Size: " << hash_test.size() << endl;


    cout << "----------------" << endl << endl;

    cout << "Table Breaches 75\% Capacity Threshold & Rehashed: " << endl << endl;
    hash_test.put(3,22);
    hash_test.put(14,4);
    hash_test.put(15,4);
    hash_test.put(16,4);
    hash_test.put(17,4);
    hash_test.put(18,4);
    hash_test.put(19,4);
    hash_test.put(20,4);
    hash_test.put(21,4);
    hash_test.put(22,4);
    hash_test.put(23,4);
    hash_test.put(24,4);
    hash_test.put(25,4);
    hash_test.put(26,4);

    hash_test.show_table();
    cout << endl;
    cout << "Record 3 (Transition Node/Link): ";
    hash_test.get(3);
    cout << endl;
    cout << "Table Size: " << hash_test.size() << endl;

    cout << "----------------" << endl << endl;
    cout << "Table Rehashed: " << endl << endl;
    hash_test.put(3,14);
    hash_test.put(27,4);
    hash_test.put(28,4);
    hash_test.put(29,4);
    hash_test.put(30,4);
    hash_test.put(31,4);
    hash_test.put(32,4);
    hash_test.put(60,4);

    hash_test.show_table();

    cout << "Record 3 (Inorder Binary Search Tree): " << endl << endl;
    hash_test.get(3);
    cout << endl;
    cout << "Table Size: " << hash_test.size() << endl;

    cout << "----------------" << endl << endl;
    cout << "Record 60 Removed: " << endl;
    hash_test.remove(60);
    hash_test.show_table();

    cout << "Table Size: " << hash_test.size() << endl;
}
