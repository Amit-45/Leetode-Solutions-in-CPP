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
=============================================Using MOORE VOTING ALGO=====================================================================================
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        // Moore Voting Algorithm
        // find each pair of different values and delete them, 
        // then the remaining element is the majrity element
        // if the majority one may not exist, you should rescan the array to check its correctness
        
        int ele = nums[0];
        int cnt = 0;
        
        for(int i=0; i < nums.size(); i++)
        {
            if(nums[i] == ele)
                cnt++;
            else if(cnt)
                cnt--;
            else // cnt == 0
                ele = nums[i];
        }
        
        return ele;
    }
};
