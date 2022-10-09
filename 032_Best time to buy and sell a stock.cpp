//Best time to buy and sell the stock (Leetcode)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int minimum =prices[0]; //if we are at 1st index 
      int profit = 0; 
      for(int i=0;i<prices.size();i++)
      {
        int diff= prices[i]-minimum;
        profit =max(profit,diff); 
        minimum =min(minimum,prices[i]);
      }  
      return profit;
    }
};
