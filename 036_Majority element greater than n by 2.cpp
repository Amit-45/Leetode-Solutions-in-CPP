https://leetcode.com/problems/majority-element/description/
===============================BRUTE FORCE============================================================================================== 
#include <bits/stdc++.h>
using namespace std;

int countEveryElements(int nums[], int n)
{
  int count;
  for (int i = 0; i < n; i++)
  {

    count = 0;
    for (int j = 0; j < n; j++)
      if (nums[j] == nums[i])
        count++;

    if (count > n / 2)
      return nums[i];
  }

  return -1;
}

int main()
{
  int nums[] = {3, 2, 3};                              ------ TAKE CARE OF INPUTS(The question clearly states that the nums array has a majority element)-------- 2,2,1,1,1,2,2  or 3,2,3 -----------------
  int n = sizeof(nums) / sizeof(nums[0]);
  countEveryElements(nums, n);
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
		
        sort(nums.begin(),nums.end());   //O(NLogN)
		
        return nums[n/2];
        
    }
};

========================================Using hashmap=============================================================================================
	Intuition: Use a better data structure to reduce the number of look-up operations and hence the time complexity. 
Moreover, we have been calculating the count of the same element again and again – so we have to reduce that also.

Approach:
- Use a hashmap and store as (key, value) pairs. (Can also use frequency array based on the size of nums)
- Here the key will be the element of the array and the value will be the number of times it occurs.
- Traverse the array and update the value of the key. Simultaneously check if the value is greater than the floor of N/2.
- If yes, return the key
- Else iterate forward.

Time Complexity: O(N)-> Frequency array or O(N log N) -> HashMap
Space Complexity: O(N)
*/
int usingHashMap(vector<int> nums, int n)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    int ans = -1;
    for (auto x : mp)
    {
        if (x.second > n / 2)
            ans = x.first;
    }
    return ans;
}

=========================================================================================================================================================
=============================================Using MOORE VOTING ALGO=====================================================================================
===========================================================================================================================================================
Moore’s Voting Algorithm INTUTION:-(BEST SOLUTIOM)
	
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
