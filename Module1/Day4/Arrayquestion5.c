#include <stdio.h>
 
int abs(int a)
{
  int abs = a;
  if(abs < 0)
    abs = abs * (-1);
  return abs;
}
 
// Function to calculate absolute difference
void EvenOddAbsoluteDifference(int arr[], int n)
{
  int even = 0;
  int odd = 0;
 
  for (int i = 0; i < n; i++) {
 
    // Loop to find even, odd absolute difference
    if (i % 2 == 0)
      even = abs(even - arr[i]);
    else
      odd = abs(odd - arr[i]);
  }
 
  printf("Even Index absolute difference : %d\n",even);
  printf("Odd Index absolute difference : %d\n",odd);
}
 
// Driver Code
int main()
{
  int arr[] = { 1, 2, 3, 4, 5, 6 };
  int n = sizeof(arr) / sizeof(arr[0]);
 
  EvenOddAbsoluteDifference(arr, n);
 
  return 0;
}