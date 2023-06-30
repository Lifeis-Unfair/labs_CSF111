#include <stdio.h>

/**
 * @author 2022A7PS1127G (ANWESH DAS)
*/

/**
 * @brief - Convert quantities from metric system to imperial system based on user options.
 *        - The function begins by printing the following menu on the console:
 *            1. meters to yards, 2. grams to ounces, 3. exit
 *        - Read the user's choice by reading one of the integers 1,2,3; assume that the user's inputs are one of these.
 *        - On receiving input 3 from the user, print 'exiting' and exit from the program.
 *        - On receiving an input 1 or an input 2 from the user, read a 'double' number from the user 
 *          and convert it into yards or ounces using the following formulae:
 *            1 meter ~ 1.0936 yards
 *            1 gram ~ 0.0353 ounces 
 *        - After printing the converted quantites go back to printing the menu and repeating the above steps. 
 *        
 * Example: 
 *        - A possible run due to the function-call 'metricToImperial()' is given below:
            1. meters to yards, 2. grams to ounces, 3. exit
            1
            10
            10.936000 yards
            1. meters to yards, 2. grams to ounces, 3. exit
            1
            20
            21.872000 yards
            1. meters to yards, 2. grams to ounces, 3. exit
            2
            20
            0.706000 ounces
            1. meters to yards, 2. grams to ounces, 3. exit
            3
            exiting
 *    
 */
void metricToImperial()
{
  printf("1. meters to yards, 2. grams to ounces, 3. exit\n");
  int inp;
  scanf("%d",&inp);
  if(inp==1)
  {
    double mtr;
    scanf("%lf",&mtr);
    printf("%lf yards\n", mtr*1.0936);
    metricToImperial();
  }
  else if(inp==2)
  {
    double grm;
    scanf("%lf",&grm);
    printf("%lf ounces\n", grm*0.0353);
    metricToImperial();
  }
  else if(inp==3)
  {
    printf("exiting\n");
    return;
  }
}


/**
 * @brief - Perform simple arithmetic operations on the parameter 'balance' depending on 
 *          the options entered by the user.
 *        - The function begins by printing the 'balance' and then asks for an option from the user.
 *        - The option entered by the user could be one of the following characters:
 *          '+', '-', 'e', 'c'.
 *        - On receiveing an option 'e', the function does not ask as for any more 
 *          options to be entered and returns 'e'.
 *        - On receiving one of '+', '-' as an option, the function waits for the user 
 *          to enter an integer 'n' and performs the corresponding operation between 'balance' and 'n'.
 *        - On receiving the option 'c', cancel the last operation and continues from there;
 *          stop if there are no operations before the current one. 
 *        - On receiving any options other than 'e', the function continues to wait for the user to
 *          enter the next option.
 *        
 * Example: 
 *        - A possible run due to the function-call 'calculator(0)' is given below:
            Balance: 0
            +
            10
            Balance: 10
            +
            10
            Balance: 20
            +  
            10
            Balance: 30
            e
 *     - Another possible run due to the function-call 'calculator(0)' is given below:
            Balance: 0
            +
            10
            Balance: 10
            +
            10
            Balance: 20
            -
            5
            Balance: 15
            c
            Balance: 20
            +  
            10
            Balance: 30
            c
            Balance: 20
            c
            Balance: 10
            e
 */
char calculator(int balance)
{
  printf("Balance: %d\n", balance);
  char temp;
  char inp;
  scanf(" %c",&inp);

  if(inp=='+')
  {
    int add;
    scanf("%d",&add);
    temp = calculator(balance+add);
  }
  else if(inp=='-')
  {
    int sub;
    scanf("%d",&sub);
    temp = calculator(balance-sub);
  }
  else if(inp=='e')
  {
    return 'e';
  }
  else if(inp=='c')
  {
    return 'c';
  }

  if(temp=='e')
  {
    return 'e';
  }
  else if(temp=='c')
  {
    calculator(balance);
  }

}

int main()
{
  printf("1. metricToImperial()  2. calculator(0) \n");
  printf("Which function do you want to test? Enter 1,2 accordingly.\n");

  int option;
  scanf(" %d",&option);

  if (option == 1)
  {
    metricToImperial();
  }
  else if(option == 2)
  {
    calculator (0);
  }
  return 0;
}