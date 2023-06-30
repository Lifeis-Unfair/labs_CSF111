#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Reports if the given non-empty array of the given length is sorted in a non-decreasing order.
 *
 * Examples:
 *  true  is_sorted([1], 1)
 *  true  is_sorted([1, 2], 2)
 *  false is_sorted([2, 1], 2)
 *  false is_sorted([1, 2, 1], 3)
 */
bool is_sorted(int nums[], int length)
{
  bool answer = false;
  
  for (int i = 0; i < length-1; i++)
  {
    if(nums[i]>nums[i+1])
    {
      return false;
    }
    
  }
  answer = true;
  
  return answer;
}

/**
 * @brief Returns the index at which the given `key` is found in the non-decreasing, non-empty array `nums` of size `length`. -1 if `key` is not found. It performs the search using a binary search algorithm and prints the index it is checking in each step.
 *
 * Requires: nums is non-decreasing, non-empty
 *
 * Examples:
 *  0  binary_search([7], 1, 7)
 *  -1 binary_search([7], 1, 6)
 *  1 binary_search([7, 9], 2, 9)
 *  -1 binary_search([7, 9], 2, 8)
 */
int binary_search(int nums[], int length, int key)
{
  const int NOT_FOUND_INDEX = -1;
  int mid = (length-1)/2;
  int ans;

  if (length==0)
  {
    return -1;
  }
  
  if(nums[mid]==key)
  {
    return mid;
  }

  else if(nums[mid]<key)
  {
    int arr[length-mid-1];
    for(int i=0; i<length-mid-1;i++)
    {
      arr[i]=nums[mid+1+i];
    }
    if (binary_search(arr, length-mid-1,key)==-1)
    {
      return -1;
    }
    ans= mid+1 + binary_search(arr, length-mid-1,key);

  }

  else if(nums[mid]>key)
  {
    int arr[mid];
    for(int i=0; i<mid;i++)
    {
      arr[i]=nums[i];
    }
    if (binary_search(arr, mid,key)==-1)
    {
      return -1;
    }
    ans= binary_search(arr, mid,key);
  }
  return ans;
  return NOT_FOUND_INDEX;
}

/**
 * @brief Populates the given array with the user's input and returns the number of integers entered. The `operation` parameter is used to customise the prompt.
 *
 */
int get_numbers(int nums[], int operation)
{
  int length = 0;
  printf("How many numbers do you want to enter? ");
  scanf("%d", &length);
  printf("Enter %d integers", length);

  if (operation == 2)
    printf(" in non-decreasing order (no duplicates): ");
  else
    printf(" (duplicates allowed): ");

  for (int i = 0; i < length; ++i)
    scanf("%d", &nums[i]);
  return length;
}

int main()
{
  printf("This program supports TWO operations:\n");
  printf("\t1. Check if the given sequence of integers is in a non-decreasing order,\n");
  printf("\t2. Search a key in a non-decreasing sequcne of integers.\n\n");
  printf("Choose an operation: ");
  int operation = 0;
  scanf("%d", &operation);

  const int MAX_LENGTH = 100;
  int nums[MAX_LENGTH];

  if (operation == 1)
  {
    int length = get_numbers(nums, operation);
    printf("The integers %s in a non-decreasing order.\n",
           is_sorted(nums, length) ? "are" : "are not");
  }
  else if (operation == 2)
  {
    int length = get_numbers(nums, operation);
    int key = 0;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int index = binary_search(nums, length, key);

    printf("%d", key);
    if (index >= 0)
      printf(" found at %d\n", index);
    else
      printf(" not found.\n");
  }

  // int nums[8]={1,4,6,9,11,13,15,19};
  // printf("%d",binary_search(nums,8,6));
  return 0;
}