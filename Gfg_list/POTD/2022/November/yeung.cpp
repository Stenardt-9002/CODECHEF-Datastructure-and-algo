#include <iostream>
using namespace std;
char monthNames[][4]={ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
char dayNames[][10] ={ "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
class Date {
enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
enum Day { Mon, Tue, Wed, Thr, Fri, Sat, Sun };
typedef unsigned int UINT;
UINT date_; Month month_; UINT year_;
public:
Date(UINT d, UINT m, UINT y) : date_(d), month_((Month)m), year_(y) { cout << "ctor: "; print(); }
~Date() { cout << "dtor: "; print(); }
void print() { cout << date_ << "/" << monthNames[month_ - 1] << "/" << year_ << endl; }
// bool validDate() { /* Check validity */ return true; } // Not implemented
// Day day() { /* Compute day from date using time.h */ return Mon; } // Not implemented
};

int main() 
{
    Date d(30, 7, 1961);
    d.print();
}