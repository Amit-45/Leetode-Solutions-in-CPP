class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    string sortVowels(string s) {
        vector<int> store;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                char ch= s[i];
                int a= (int)ch;
                store.push_back(a);
            }
        }
        int j=0;
        sort(store.begin(),store.end());
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                int num= store[j];
                char ch= (char)num;
                s[i]=ch;
                j++;
            }
        }
        return s;
    }
};
