class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
    set<char>m;
    int max = 0 ;
    int start = 0 ; 
    int end = 0 ; 
    while(start != s.size()){
        
        auto it = m.find(s[start]);
        if(it == m.end()){
            if(start-end+1 > max)
                 max = start-end+1;
            m.insert(s[start]);
            start++;
        }
        else {
           m.erase(s[end]);
            end++;
        }
    }
    return max;
}
};
