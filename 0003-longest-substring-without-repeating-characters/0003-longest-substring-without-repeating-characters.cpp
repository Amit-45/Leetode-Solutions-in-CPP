class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int c[128] = {0};
        
        int left = 0;
        int maxLength = 0;
        
        
        for (int right = 0; right < s.size(); right++) {
            char currChar = s[right];
            int lastFoundIndex = c[currChar];
            
            if (lastFoundIndex >= left ) {
                left = lastFoundIndex ;
            }
            
            c[currChar] = right+1; 
            
             maxLength = max(maxLength, right - left + 1);
            
        }
        
        return maxLength; 
    }
};
