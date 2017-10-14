#include <iostream>
#include "eConvert.h"

using namespace std;

// number of distinct numbers (single and double digit numbers)
int length = MIN;

// array to hold each distinct digit
int digits[LIMIT] = {'\0'};

// array to hold words equivalent of each distinct number
char dWord[LIMIT][WIDTH] = {'\0'};

/**
 * splits the inputed number into separate digits,
 * beginning from the end, it takes 2 digits as one number (0 - 99)
 * then a single digit(hundreds), alternating double and single digit numbers till input is 
 * exhasuted
 * i.e unit and tens digit = one number, digit in hundreds place = second number
 * e.g 123456; 1st number = 56, second = 4, third = 23, fourth = 1.
 */ 
void splitNum(long long *input)
{
    for (int i = MIN; i < LIMIT; i++)
    {
        // number is 0 exit loop!
        if (*input == MIN)
        {
            // 0 is the distinct number
            digits[i] = *input;
            break;
        }

        // pick last 2 digits out of those left, as a single number
        if (i % 2 == MIN)
        {
            digits[i] = *input % 100;
            *input /= 100;
        }

        // pick last digit out of those left, as a single number
        else
        {
            digits[i] = *input % 10;
            *input /= 10;
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
								
        // input is 0, print "zero" and quit!
        print();
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

    // hundreds place has no value e.g 10002
    if ((digits[MIN] != MIN && digits[1] == MIN) && (digits[2] != MIN || digits[3] != MIN || digits[4] != MIN || digits[5] != MIN || digits[6] != MIN || digits[7] != MIN))
        strcat(dWord[1], "and ");
    
    // identify and assign thousands
    if ((digits[2] > MIN || digits[3] > MIN))
        strcat(dWord[2], " thousand ");
    
    // identify and assign millions
    if (digits[4] > MIN || digits[5] > MIN)
        strcat(dWord[4], " million ");

    // identify and assign billions
    if (digits[6] > MIN || digits[7] > MIN)
        strcat(dWord[6], " billion ");
}

/**
 * prints out strings
 */
void print(void)
{
    for (int i = length; i >= 0; i--)
    {
        // print out content of each sub array
        cout << dWord[i];
    }
}