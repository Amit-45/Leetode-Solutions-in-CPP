class Solution {
public:
    bool isCapital(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]>='A'&&s[i]<='Z'){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool isLowerCase(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z'){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool isIdeal(string s){
        string r=s.substr(1,s.size()-1);
        string p=s.substr(0,1);
        return isCapital(p)&&isLowerCase(r);
    }
    bool detectCapitalUse(string word) {
        return isCapital(word)||isLowerCase(word)||isIdeal(word);
    }
};