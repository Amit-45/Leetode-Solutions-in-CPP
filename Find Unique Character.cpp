class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq_array(26,0);   // a vector of a to z 

        for(int i=0;i<s.length();i++)
        {
            freq_array[s[i]-'a']++; // s[i]-'a' is to treat letters as index 
        }

        for(int i=0;i<s.length();i++)
        {
            if(freq_array[s[i]-'a']==1) return i; // if it is first non repeating character 
        }
    return -1;
    }
};
