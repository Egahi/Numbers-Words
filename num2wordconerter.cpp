/***
 * num2wordconverter.cpp
 *
 * this program takes a numerical value in digits and prints it out in words
 *
 * @s_egahi
 *
 * this is num2wordconverter.
 */

#include <iostream>

#include "eConvert.h"

using namespace std;

int main(void)
{
    // variable to get and hold number from user
    long long input;
    
    cout << "Number: ";
    cin >> input;
    
    // accept only numbers between 0 and 999 999 999 999
    while (input < MIN || input > MAX)
    {
        cout << "Enter a number between 0 and " << MAX << endl;
        cout << "Number: ";
        cin >> input;
    }
        
    // separate digits of input into distinct numbers
    splitNum(&input);

    // convert each distinct number to word if number is 0, quit
    if (!numToWord())   
        return 0;

    // assign place value to each distinct number
    placeValues();     

    // print out digits converted to words    
    print();

    return 0;
}