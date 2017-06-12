#include "node2.h"
#include "point.h"
#include <iostream>
#include <string>

using namespace main_savitch_6B;
using namespace main_savitch_2A;
using namespace std;

int main() {

node<int>* ages = NULL;
list_head_insert(ages,18);
node<string> name;
name.set_data("Jorge");
node<point> *seat;
seat = new node<point>;
(*seat).set_data(point(2,4));

cout << "Ages: ";
while(ages != NULL)
{
    cout << ages->data();
    ages = ages->link();
}
cout << endl;

cout << "Name: " << name.data() << endl;

cout << "Seat: ";
point tmp = seat->data();
cout << tmp.get_x() << tmp.get_y() << endl;
}
