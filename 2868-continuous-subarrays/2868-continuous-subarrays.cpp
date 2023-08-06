class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        wcin.tie(0);
        int n=nums.size();long long ans=0;int i,j=0;map<int,int> mp;
        for(i=0;i<n;i++){
            while(j<n){
                if(mp.size()!=0 && ((mp.rbegin()->first-mp.begin()->first))>2) break;
                mp[nums[j]]++; j++;
            }
            if((mp.rbegin()->first-mp.begin()->first)>2) ans+=j-i-1;
            else ans+=(j-i);
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
        }
        return ans; 
    }
};