#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h" 
#include "CommissionEmployee.h"  
#include "BasePlusCommissionEmployee.h" 
using namespace std;

void virtualViaReference( const Employee & ); // prototype

int main()
{
   // set floating-point output formatting
   cout << fixed << setprecision( 2 );

   // create derived-class objects
   SalariedEmployee salariedEmployee( 
      "John", "Smith", "111-11-1111", Date(6, 15, 1994), 800 );
   CommissionEmployee commissionEmployee( 
      "Sue", "Jones", "333-33-3333", Date(5, 14, 1960), 10000, .06 );
   BasePlusCommissionEmployee basePlusCommissionEmployee( 
      "Bob", "Lewis", "444-44-4444", Date(9, 8, 1954), 5000, .04, 300 );
   // create vector of three base-class pointers
   vector < Employee * > employees( 3 );

   // initialize vector with Employees
   employees[ 0 ] = &salariedEmployee;
   employees[ 1 ] = &commissionEmployee;
   employees[ 2 ] = &basePlusCommissionEmployee;

   cout << "Employees processed polymorphically via dynamic binding:\n\n";

   for ( const Employee *employeePtr : employees )
      virtualViaReference( *employeePtr ); // note dereferencing

    return 0;
} // end main

// call Employee virtual functions print and earnings off a 
// base-class reference using dynamic binding
void virtualViaReference( const Employee &baseClassRef )
{
   baseClassRef.print();
   SYSTEMTIME curTime;
   GetLocalTime(&curTime);
   Date curBirthDay = baseClassRef.getBirthDate();

   if(curBirthDay.getDay() == curTime.wDay && curBirthDay.getMonth() == curTime.wMonth) {
       cout << "\nHAPPY BIRTHDAY!"
            << "\nearned $" << baseClassRef.earnings() + 100 << "\n\n";
   }
   else
        cout << "\nearned $" << baseClassRef.earnings() << "\n\n";
} // end function virtualViaReference
