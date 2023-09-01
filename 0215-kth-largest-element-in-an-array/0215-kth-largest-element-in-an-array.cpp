class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     priority_queue<int,vector<int>,greater<int>> pq; 
     //Technique: for loop:  push into heap -> if condition -> pop->return top
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
