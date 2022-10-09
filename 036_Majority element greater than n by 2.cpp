https://leetcode.com/problems/majority-element/description/
===============================BRUTE FORCE==============================================================================================
#include <bits/stdc++.h>
using namespace std;
 

//we have to just add the main condition 
Total approach of brute force:
1. Check the count of occurrences of all elements of the array one by one.
2. Start from the first element of the array and count the number of times it occurs in the array.
3. Main condition :If the count is greater than the floor of N/2 then return that element as the answer. 
   If not, proceed with the next element in the array and repeat the process.
  
//this function returns the frequency of all elements in array(step 1 and step 2)
void countFreq(int arr[], int n)
{
    vector<bool> visited(n, false);
 
    for (int i = 0; i < n; i++) {
 
        // Skip this element if already processed
        if (visited[i] == true)
            continue;
 
        // Count frequency
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " " << count << endl;
    }
}
 
int main()
{
    int arr[] = {10,5,10,15,10,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    countFreq(arr, n);
    return 0;
}
================================BETTER SOLUTION [not the unordered map solution]==========================================================================================================
The definition of majority element in the question is, THE ELEMENT that occurs MORE THAN n/2 times. 
It means that MORE THAN HALF of the array is occupied by MAJORITY ELEMENT. It means that index n/2 (of sorted array) 
  definitely contains the majority element. So will just return that.

So first of all we sort the array and return the element at index n/2. If you like the solution do upvote:)

  

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
		
        sort(nums.begin(),nums.end());
		
        return nums[n/2];
        
    }
};
=========================================================================================================================================================
=============================================Using MOORE VOTING ALGO=====================================================================================
===========================================================================================================================================================
Moore’s Voting Algorithm INTUTION:-
	
The question clearly states that the nums array has a majority element. Since it has a majority element we can say definitely the count is more than N/2.

Majority element count = N/2 + x;

Minority/Other elements = N/2 – x;

Where x is the number of times it occurs after reaching the minimum value N/2.

Now, we can say that count of minority elements and majority elements are equal up to a certain point of time in the array. So when we traverse through the array we try to keep track of the count of elements and which element we are tracking. Since the majority element appears more than N/2 times, we can say that at some point in array traversal we find the majority element. 

APPROACH: 

Initialize 2 variables: 
Count –  for tracking the count of element
Element – for which element we are counting
Traverse through nums array.
    If Count is 0 then initialize the current traversing integer of array as Element        if(count==0)  -->  element = ith element   
    If the traversing integer of array and Element are same increase Count by 1             if(ith element==element)   --> count++
    If they are different decrease Count by 1                                               if(ith element != element)  -->  count--
Return the element 

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {

    // MOOORE voting algo
    int ele = 0;
    int cnt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      if (cnt == 0)
        ele = nums[i];
      if (nums[i] == ele)
        cnt++;
      else
        cnt--;
    }

    return ele;
  }
};
