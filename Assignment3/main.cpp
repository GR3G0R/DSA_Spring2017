//  FILE: main.cpp

#include <iostream>
#include <cmath>
#include "sequence.h"

using namespace std;
using namespace delpe_sequence_h;


int main() {
    Sequence dynamic_sequence;

    dynamic_sequence.insert(1);
    dynamic_sequence.insert(2);
    dynamic_sequence.insert(3);
    dynamic_sequence.insert(2);
    dynamic_sequence.insert(5);

    dynamic_sequence.insert_at(7,5);

    cout << "Raw sequence: " << endl;
    dynamic_sequence.print_sequence();

    cout << "----------------------" << endl;

    cout << endl;
    cout << "Ostream overload: " << endl;
    cout << dynamic_sequence << endl;

    cout << "----------------------" << endl;

    dynamic_sequence.erase_from(2);
    cout << "erase_from(2) -> " << dynamic_sequence << endl;

    cout << "count(2): " << dynamic_sequence.count(2) << endl << endl;

    cout << "erase_first(2) -> ";
    dynamic_sequence.erase_first(2); cout << dynamic_sequence << endl;

    cout << "erase_last(2) -> ";
    dynamic_sequence.erase_last(2); cout << dynamic_sequence << endl;

    cout << "erase_occurrence(5,1) -> ";
    dynamic_sequence.erase_occurrence(5,1); cout << dynamic_sequence << endl;

    cout << "insert_first(7) -> ";
    dynamic_sequence.insert_first(7); cout <<  dynamic_sequence << endl;

    cout << "insert_at(6,0) -> ";
    dynamic_sequence.insert_at(6,0); cout << dynamic_sequence << endl;

    cout << "----------------------" << endl;

    cout << "LOOP..." << endl;

    for(int i = 0; i < pow(10.0,9.0); i++)
    {
        Sequence loop_sequence_object;
        for(int j = 0; j < 1; j++)
        {
            loop_sequence_object.insert(j);
        }
        break;
    }
    //When executing the sequence class withought a destructor to dealocate the memory it took
    //almost twice as long for the process utilization memory (%MEM) to return to it's resting threshold
    //of 24kb. After 21 seconds, execution with the uncomented destructor had already reached the resting
    //threshold of 24kb with comparison to a 42 second period of fluctuation exhibited during the commented
    //execution of the sequence class without a destructor. I also noticed rapid fluctuation in
    //processing utilization memory during the violent decent of the uncomented sequence class with destructors execution.
    //The comented execution was a bit more subtle in it's de-escalation to the common resting threshold of 24kb.

}
