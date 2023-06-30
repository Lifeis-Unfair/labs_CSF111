#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/**
 * @brief Returns the number of vowels in a given string.
 * 
 * Requires: The given string has no spaces. Can contain uppercase, lowercase characters and digits.  
 * 
 * Examples:
 *  4  num_vowels("BitsPilani")
 *  2  num_vowels("GOA")
 *  0  num_vowels("CSF111")
 */
int num_vowels(char str[])
{
  int count = 0;
  int n = strlen(str);

  for(int i=0; i<n; i++)
  {
    if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
    {
      count++;
    }
  }
  
  return count;
}

/**
 * @brief Prints the longest substring in a given string with no repeating characters.
 * A character in lowercase and uppercase is treated different. ('a' is different than 'A')
 * If there are multiple substrings of the same length, print the substring whose starting index in the original string is higher. 
 *
 * Requires: The given string has no spaces. Can contain uppercase, lowercase characters and digits.
 *
 * Examples:
 *  Prints "abcd" for longest_substring("abcd")
 *  Prints "est" for longest_substring("test")
 *  Prints "BITSPilan" for longest_substring("BITSPilaniGoaCampus")
 *  Prints "TSPILAN"  longest_substring("BITSPILANIGOACAMPUS")
 */ 



void longest_substring(char str[])
{
  char longest[100]=" ";
  int n=strlen(str);
  int i=0;

  while(i<n-1)
  {    
    int j = 0;
    char substr[n+1];
    substr[n]='\0';
    int k=i;
    substr[0]=str[i];

    while (str[i+1]!=substr[j] && i+1>j)
      {
        substr[j]=str[k];
        j++;
      }
    
    
    i=j;
    if(strcmp(substr,longest)==1)
    {
      strcpy(longest,substr);
    }
    
    i++;
  }
  
  printf("Longest substring with no repeating characters: %s\n", longest);

}
 



int main()
{
  printf("This program supports TWO operations:\n");
  printf("\t1. Count the number of vowels in a string,\n");
  printf("\t2. Find the longest substring with no repeating characters.\n\n");
  printf("Choose an operation (1 or 2): ");
  int operation = 2;
  scanf("%d", &operation);

  const int MAX_LENGTH = 100;
  char str[MAX_LENGTH]="bitspilani";

  printf("Enter the string: ");
  scanf("%s", str);

  if (operation == 1)
  {
    printf("The number of vowels in %s is %d\n", str, num_vowels(str));
  }

  else if (operation == 2)
  {
    longest_substring(str);
  }

  return 0;
}