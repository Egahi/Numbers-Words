/***
 * num2word.cpp
 *
 * this program takes a positive integer in digits and prints it out in words
 *
 * @s_egahi
 *
 * this is num2word.
 */

#include <iostream>

#include "num2word.h"

using namespace std;

int main(void)
{
			do
			{
			    // welcome user
			    welcome();

		     // get number from user
        getInput();
        
        // separate digits of input into distinct numbers
        splitNum();

        // convert each distinct number to word if number is 0, quit
        numToWord();   

        // assign place value to each distinct number
        placeValues();     

        // print out digits converted to words    
        print();
				
        // prompt to run again
			} while (runAgain());

    return 0;
}