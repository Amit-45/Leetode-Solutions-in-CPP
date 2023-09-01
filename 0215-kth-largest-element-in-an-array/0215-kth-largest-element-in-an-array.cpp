class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     priority_queue<int,vector<int>,greater<int>> pq; 
     //Technique: for loop:  push -> if -> pop ->  top
     for(auto x: nums)
     {
         pq.push(x);
         if(pq.size()>k)
         {
             pq.pop();
         }
         
     }
     

    return pq.top();
    }
};
