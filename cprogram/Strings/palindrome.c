/*
 *
 * Minimum number of deletions to make a string palindrome
Last Updated : 22 May, 2024
Given a string of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome.

Note: The order of characters should be maintained.

Examples :

Input : aebcbda
Output : 2
Remove characters 'e' and 'd'
Resultant string will be 'abcba'
which is a palindromic string
Input : geeksforgeeks
Output : 8
A simple solution is to remove all subsequences one by one and check if the remaining string is palindrome or not. The time complexity of this solution is exponential.

Take two indexes first as ‘i’ and last as a ‘j’
Compare the character at the index ‘i’ and ‘j’
If characters are equal, then
Recursively call the function by incrementing ‘i’ by ‘1’ and decrementing ‘j’ by ‘1’
else
Recursively call the two functions, the first increment ‘i’ by ‘1’ keeping ‘j’ constant, second decrement ‘j’ by ‘1’ keeping ‘i’ constant.
Take a minimum of both and return by adding ‘1’ */


#include <stdio.h>
#include <string.h>

int min(int x, int y) 
{ 
  return (x < y) ? x : y; 
}

// Utility function for calculating
// Minimum element to delete
int utility_fun_for_del(char* str, 
                          int i, int j)
{
    if (i >= j)
        return 0;

    // Condition to compare characters
    if (str[i] == str[j]) 
    {

        // Recursive function call
        return utility_fun_for_del(str,i + 1, j - 1);
    }

    // Return value, incrementing by 1
    return 1 + min(utility_fun_for_del(str, i + 1, j), utility_fun_for_del(str, i, j - 1));
}

// Function to calculate the minimum
// Element required to delete for
// Making string palindrome
int min_ele_del( char* str)
{

    // Utility function call
    return utility_fun_for_del(str, 0, 
                               strlen(str) - 1);
}

// Driver code
int main()
{
   // char* str = "abefbac";
   // char* str = "geeksforgeeks";
      char* str = "esakkibabu";
    printf( "Minimum element of deletions = %d\n", min_ele_del(str));
    return 0;
}

