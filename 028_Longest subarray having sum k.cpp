/*
Question-Longest Subarray with given Sum K

Input:arr = {7,1,6,0}, k = 7
Output: Length of the longest subarray with sum K is 3
Explanation:
 1 + 6 + 0 = 7, it is the longest subarray with sum 7 and length 3.

==============================================================================================================================================
--------------------------VARIABLE SLIDING WINDOW APPROACH-----------------------------------------------------------------------
===============================================================================================================================================
Q. Will the discussed approach work with negative numbers in the array?
A. No. (Will not work on leetcode submissions because it takes negative number into consideration too)
Because let's say in the given array [4,1,1,1,2,3,5] when we found the sum within the window to be greater than the desired value 5 (i=0, j=2 -> [4,1,1]), we started reducing the size of the window by doing i++. Here we assumed that once the sum of elements within the window becomes greater than 5 then increasing the window size will just add to the sum and hence we will not attain the sum 5 again. This is true when all the element are positive and hence reducing the window size by doing i++ makes sense. But this might not be true if array also contains negative numbers. Consider the array [4,1,1,-2,1,5], here we would have found the sum to be greater than 5 for i=0, j=2 and if we would have now started reducing the window size by doing i++, we would have missed the potential subarray (i=0, j=4).
In short, the discussed approach will not work with array having negative numbers.
*/
================================================================================================================================================
------------------------NORMAL CODE----------------------------------------------------------------------------------------------------------- ==============================================================================================================================================

int longestSubArrWithSumK_Optimal2(int arr[], int n, int k)
{

  int i = 0;
  int j = 0;
  int sum = 0;
  int mxl = INT_MIN;

  while (j < n)
  {
    sum += arr[j];
-------------------case1--------------------------------
    if (sum > k)
    {

      if (sum == k)
      {
        mxl = max(mxl, j - i + 1);
      }
      j++;
    }
    -------------------case2----------------------------------------------
    else if (sum == k)
    {
      mxl = max(mxl, j - i + 1);
      j++;
    }
    --------------------case3----------------------------------------------
    else if (sum < k)
    {
      j++;
    }
  }
  return mxl;
}




===================================================================================================================================================
----------------------------EXPLAINED CODE------------------------------------------------------------------------------------------------------
====================================================================================================================================================
int longestSubArrWithSumK_Optimal2(int arr[], int n, int k)
{

  int i = 0;
  int j = 0;
  int sum = 0;
  int mxl = INT_MIN;
  
  //while loop till j goes out of array 
  while (j < n)
  {
    //sab ka sum nikalte jaoo jab tak ye 3 condition nhi face karoge 
    // sum>k,sum==k,sum>k
    sum += arr[j];
     ---------------------case1---------------------------------------------------------------------------------
    if (sum > k) //case1
    {
      //pehle ith element delete hoga 
      //phir i ko tab tak move karna hoga aur element ko tab tak delete karna hoga jab tak sum<k  hoo ya sum=k koo
      while (sum > k) //comes out of loop when the condition(sum == k or sum < k) fails as sum cannot exceed k
        
        // this is necessary because we have successfully handled case where we are adding and then checking with k
      // what if we are subtracting and we get the result after it
      // we come out of while loop in two cases ie either sum == k or sum < k

        sum = sum - arr[i++];   //deleting element and then incrementing i
      
      if (sum == k) 
      {
        mxl = max(mxl, j - i + 1);  //updating max value 
        //instead of this we can also write if(size>max){max=j-i+1;}
      }
      j++; //incrementing j
    }
    --------------------case2---------------------------------------------------------------------------------
    else if (sum == k) //case 2
    {
      mxl = max(mxl, j - i + 1); //update max 
      j++;
    }
    ---------------------case3--------------------------------------------------------------------------------------------------
    else if(sum<k) //case 3
    {
      j++; //just increment j
    }
  }
  return mxl;
}
int main()
{

  int arr[] = {7, 1, 6, 0};
  int n = sizeof(arr) / sizeof(arr[0]), k = 7;
  cout << "Length of the longest subarray with sum K is " << longestSubArrWithSumK_Optimal2(arr, n, k);

  return 0;
}
