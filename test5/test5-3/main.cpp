#include "Point.h"
#include <iostream>
using namespace std;
extern int test_int;
int main()
{
    Point::print_test_int();
    cout << &test_int << endl;
}
