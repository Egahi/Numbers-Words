#include <iostream>

#include "num2word.h"

using namespace std;

// variable to get and hold number from user
long long input;

// number of distinct numbers (single and double digit numbers)
int length;

// array to hold each distinct digit
int digits[LIMIT];

// array to hold words equivalent of each distinct number
char dWord[LIMIT][WIDTH];

/**
 * welcomes user and initialises variables and arrays for fresh input
 */
void welcome (void)
{
    cout << "\nHello! thanks for using num2word.\n"
				   << "This program converts a number to words!\n"
				   << "Input a number to get started." << endl;
		
    input = 0;
		 length = 0;
			
			// initialise arrays with null indicator to clear any previous input	
    for (int i = 0; i < LIMIT; i++)
			{
		     digits[i] = {'\0'};
								
        for (int j = 0; j < WIDTH; j++)
        {
             dWord[i][j] = {'\0'};
        }
			}
}

/**
 * Takes input from user and validates that it is a number
 * between 0 and 999 999 999 999
 */
void getInput(void)
{
    // variable to validate input
    bool validate;
						
    // accept only numbers between 0 and 999 999 999 999
    do
    {
        cout << "\nNumber: ";
							
					 // constrain input to numbers	
        if (!(cin >> input))
        {
            cout << "Enter only numbers between " << MIN
												<< " and " << MAX << " inclusive." << endl;
            cin.clear();
            cin.ignore(15, '\n');
								 validate = false;
        }
						
					 // constrain number to range 0 - 999 999 999 999
        else if (input < MIN || input > MAX)
        {
            cout << "Enter a number between " << MIN
												<< " and " << MAX << " inclusive." << endl;
            cin.ignore(15, '\n');
							  validate = false;
        }
								
        else
            validate = true;
    } while (validate == false);
}

/**
 * splits the inputed number into separate digits,
 * beginning from the end, it takes 2 digits as one number (0 - 99)
 * then a single digit(hundreds), alternating double and single digit numbers till input is 
 * exhasuted
 * i.e unit and tens digit = one number, digit in hundreds place = second number and so on...
 * e.g 123456; 1st number = 56, second = 4, third = 23, fourth = 1.
 */ 
void splitNum(void)
{
    for (int i = MIN; i < LIMIT; i++)
    {
        // number is 0 exit loop!
        if (input == MIN)
        {
									// number is 0 which is a distinct number
								 if (length == MIN)
                length = 1;

            // number is zero or has been successfilly split up exit loop
            digits[i] = input;
            break;
        }

        // pick last 2 digits out of those left, as a single number
        if (i % 2 == MIN)
        {
            digits[i] = input % 100;
            input /= 100;
        }

        // pick last digit out of those left, as a single number
        else
        {
            digits[i] = input % 10;
            input /= 10;
        }

        length += 1;
    }
}

/**
 * converts each distinct number to word, returns false if input is 0 and true otherwise
 */
bool numToWord(void)
{
    int check = MIN;
    
    for (int i = MIN; i <= length; i++)
    {
        // if any digit of number is greater than 0, increament check and exit loop
        if (digits[i] > MIN)
        {
            check += 1;
            break;
        }
    }

    // if check = 0, number is zero    
    if (check == MIN)
    {
        // assign "zero"    
        strcpy(dWord[MIN], "zero");

        return false;
    }

    else
    {
        for (int i = MIN; i < length; i++)
        {
            // converts numbers from 1 - 19 to words
            if (digits[i] > MIN && digits[i] <= 19)
                oneNineteen(digits[i], &i);
																            
            // converts numbers from 20 - 99 to words
            else
            {
                // isolate unit digit
                int unit = digits[i] % 10;
                
                // isolate tens digit
                int tens = digits[i] / 10;

											// convert tens digit to words
                tensConverter(&tens, &i);

											// convert numbers unit digit to words												
											oneNineteen(unit, &i);
            }
        }
    }

    return true;
}

/**
 * converts digits from 1 - 9 and numbers from 10 - 19 to words
 */
void oneNineteen(int unit, int *i)
{
    switch (unit)
    {
        case 1:
            strcat(dWord[*i], "one");
            break;
        case 2:
            strcat(dWord[*i], "two");
            break;
        case 3:
            strcat(dWord[*i], "three");
            break;
        case 4:
            strcat(dWord[*i], "four");
            break;
        case 5:
            strcat(dWord[*i], "five");
            break;
        case 6:
            strcat(dWord[*i], "six");
            break;
        case 7:
            strcat(dWord[*i], "seven");
            break;
        case 8:
            strcat(dWord[*i], "eight");
            break;
        case 9:
            strcat(dWord[*i], "nine");
            break;
        case 10:
            strcpy(dWord[*i], "ten");
            break;
        case 11:
            strcpy(dWord[*i], "eleven");
            break;
        case 12:
            strcpy(dWord[*i], "twelve");
            break;
        case 13:
            strcpy(dWord[*i], "thirteen");
            break;
         case 14:
            strcpy(dWord[*i], "fourteen");
            break;
         case 15:
            strcpy(dWord[*i], "fifteen");
            break;
         case 16:
            strcpy(dWord[*i], "sixteen");
            break;
         case 17:
            strcpy(dWord[*i], "seventeen");
            break;
         case 18:
            strcpy(dWord[*i], "eigteen");
            break;
         case 19:
            strcpy(dWord[*i], "nineteen");
            break;
         default:
            strcat(dWord[*i], "\0");
     }            
}

/**
 * converts numbers from 20 - 99 to words
 */
void tensConverter (int *tens, int *i)
{
    switch (*tens)
    {
        case 2:
            strcpy(dWord[*i], "twenty ");
            break;
        case 3:
            strcpy(dWord[*i], "thirty ");
            break;
        case 4:
            strcpy(dWord[*i], "forty ");
            break;
        case 5:
            strcpy(dWord[*i], "fifty ");
            break;
        case 6:
            strcpy(dWord[*i], "sixty ");
            break;
        case 7:
            strcpy(dWord[*i], "seventy ");
            break;
        case 8:
            strcpy(dWord[*i], "eigty ");
            break;
        case 9:
            strcpy(dWord[*i], "ninety ");
            break;
        default:
            strcpy(dWord[*i], "\0");
    }
}

/**
 * assigns relevant place values to each distinct number 
 */
void placeValues(void)
{
    for (int i = MIN; i < length; i++)
    {
        // identify hundreds with tens and unit e.g 123
        if (i % 2 != MIN && digits[i] != MIN && digits[i - 1] != MIN)
            strcat(dWord[i], " hundred and ");

        // identify hundreds with no tens or unit e.g 100
        if (i % 2 != MIN && digits[i] != MIN && digits[i - 1] == MIN)
            strcat(dWord[i], " hundred");
    }

    // hundreds place has no value e.g 10002 add "and"
    if ((digits[MIN] > MIN && digits[1] == MIN) && (digits[2] > MIN || digits[3] > MIN || digits[4] > MIN || digits[5] > MIN || digits[6] > MIN || digits[7] > 0))
        strcat(dWord[1], "and ");
    
    // identify and assign thousands,
    if (digits[2] > MIN || digits[3] > MIN)
			{
        // if followed by a hundred add a comma
        if (digits[1] > MIN)
            strcat(dWord[2], " thousand, ");
			    else
			        strcat(dWord[2], " thousand ");
			}
    
    // identify and assign millions
    if (digits[4] > MIN || digits[5] > MIN)
			{
						// if followed by a digit in hundreds place, add a comma
        if (digits[3] > MIN || digits[2] > MIN || digits[1] > MIN)
            strcat(dWord[4], " million, ");
					 else
		         strcat(dWord[4], " million ");
    }

    // identify and assign billions
    if (digits[6] > MIN || digits[7] > MIN)
			{
						// if followed by a digit in hundreds place, add a comma
        if (digits[5] > MIN || digits[4] > MIN || digits[3] > MIN || digits[2] > MIN || digits[1] > MIN)
            strcat(dWord[6], " billion, ");
					 else
            strcat(dWord[6], " billion ");
			}

			// add a full stop
			strcat(dWord[MIN], ".");
}

/**
 * prints out strings with first letter of first word capitalised
 */
void print(void)
{
			//change first character of first word to upper case
			dWord[length - 1][MIN] -= DIFF;
				
    for (int i = length; i >= 0; i--)
    {					
        // print out content of each sub array
        cout << dWord[i];
    }
}

/**
 * prompt to run program again,
 * returns true to run again and false otherwise.
 */
bool runAgain(void)
{
			char ans = 'a';
			bool validate;
			
		 // prompt repeatedly until valid response is entered
		 do
    {
         cout << "\n\nRun again?\n"
              << "Yes (y) or No (n)" << endl;
						
						cin >> ans;
							
						// constrain reply to 'Y', 'y', 'N' or 'n'	
				   if (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n')
						{
						    cout << "\n\nType \"y\" for yes or \"n\" for no" << endl;
									validate = false;
									cin.clear();
									cin.ignore(15, '\n');
				   }
								
			    else
			        validate = true;
    	} while (validate == false);
				
    if (ans == 'Y' || ans == 'y')
			    return true;
			
			else
        cout << "\nAll done, Goodbye." << endl;

    return false;
}