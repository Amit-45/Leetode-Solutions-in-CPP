class Solution {
#define ll long long int
public:
    bool isPalindrome(int x) {
        
        if(x<0) return false;
        ll n=x;
        ll rev=0;
        while (n!=0)
        {
            ll last = n % 10;    
            rev = rev * 10 + last; 
            n = n / 10;            
        }
        if(x==rev) return true;
        return false;
    }
};