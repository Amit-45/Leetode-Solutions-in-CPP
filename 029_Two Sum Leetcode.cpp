=====================Brute force approach ======================================================================================================================
//traverse throught the array 
// for every element x try to find another element y(target-x)
//if we find both then store the indexes and return those values
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    //traversing array 
    for (int i = 0; i < nums.size(); ++i) {
    //traversing the remaining indexes(index 1+1 to last) ]
   	 for (int j = i + 1; j < nums.size(); ++j) {
       //finding the element y so that it sums up with x and we store and return the indices
   		 if (nums[i] + nums[j] == target) {
         
   			 res.emplace_back(i);
   			 res.emplace_back(j);  https://www.codingninjas.com/codestudio/library/vector-push_back-vs-emplace_back (adds element to the last)
   			 break;
   		 }
   	 }
   	 if (res.size() == 2) //if vector size becomes 2 ,stop
   		 break;
    }
    return res;
} 
