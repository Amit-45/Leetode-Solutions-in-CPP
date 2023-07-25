class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
        map<int,int>mp;
        int j=0,Max=0,cnt=0;
        
         for(int i=0;i<s.size();i++){
             
              if(mp.find(s[i])==mp.end()){
                  mp[s[i]]=i;
              }else{
                 
                   while(j<s.size() && cnt<=mp[s[i]]){
                       mp.erase(s[j]);
                       cnt++;
                       j++;
                       
                   }
                  mp[s[i]]=i;
              }
             int size=mp.size();
             Max=max(Max,size);
         }
        return Max;
    }
};