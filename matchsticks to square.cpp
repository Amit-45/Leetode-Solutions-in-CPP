class Solution {
public:
    
    // declare a sides array of length 4
    
    vector<int> sides = {0, 0, 0, 0};
    
    bool helper(vector<int>& matchsticks, int i, int n, int target)
    {
        // base case
        
        if(i == n)
        {
            return true;
        }
        
        // fill the sides array, with every possible combination
        
        for(int k = 0; k < 4; k++)
        {
            if(sides[k] + matchsticks[i] <= target)
            {
                // add the matchsticks's length to sides
                
                sides[k] += matchsticks[i];
                
                // recusivilly call the helper
                
                if(helper(matchsticks, i + 1, n, target))
                    return true;
                
                // if added length doesn't lead to result then backtrack
                
                sides[k] -= matchsticks[i];
            }
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        
        int n = matchsticks.size();
        
        int sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum += matchsticks[i];
        }

        
        if(sum % 4)
            return false;
        
        
        int target = sum / 4;
        
      
        
        sort(matchsticks.begin(), matchsticks.end(), greater<int> ());

        
        return helper(matchsticks, 0, n, target);
    }
};
