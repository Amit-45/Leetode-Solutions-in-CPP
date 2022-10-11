================================BRUTE FORCE=================================================================================TLE==================

#include<bits/stdc++.h>
using namespace std;

int longestSubArrWithSumK_BF(int arr[], int n, int k) {
  int maxLength = 0;
  // finding subarrays using i and j loop 
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      //Also finding the sum of all the sub arrays suring the sme iteration 
      sum += arr[j];
      //When you reach  your desired sum
      if (sum == k)
        //Record the lengths of those sub arrays and keep comparing with maxLength 
        //Update max if you find any subaray length greater than the maxLength
        //(j-i+1 gives the length of the subarray)
        maxLength = max(maxLength, (j - i + 1));
    }

  }
  return maxLength;
}

int main() {

  int arr[] = {7,1,6,0};
  int n = sizeof(arr) / sizeof(arr[0]), k = 7;

  cout << "Length of the longest subarray with sum K is " << 
  longestSubArrWithSumK_BF(arr, n, k);

  return 0;
}

==================================================================================SLIDING WINDOW APPROACH=================================================
  (ONLY WORKS FOR POSITIVE INPUTS)
  ----------------------------------
public:
long maximumSumSubarray(int K, vector<int> &Arr, int N)
{

  // sliding window approach

  // both pointers pointing to 0 index
  int i = 0;
  int j = 0;

  // max will store the maximum sum value
  long int maxi = INT_MIN;
  //sum taken to store sum array sum
  long int sum = 0;

  // Till j goess out of the array
  while (j < N)
  {
    // saare sum nikalte jaoo
    sum = sum + Arr[j];

    // size of window =j - i + 1
    //  sum tab matter karega when size of window == k hoga . Agar size of window chota hai  k sey ,  jst j ko increment karoo
    //  tab tak incremant karoo jab tak size of window ==k nhi ho jata
    if ((j - i + 1) < K)
    {
      j++;
    }

    // jab window ka size == k hoga
    // humko maximm sum store karna hai
    // phir iTH element ko delete karoo
    // phir window ko aage badhaoo (i++ and j++)
    else if ((j - i + 1) == K)
    {
      maxi = max(maxi, sum);
      sum = sum - Arr[i];
      i++;
      j++;
    }
  }
  return maxi;
}
}
;
