https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) {
        int mask=0;
        int m=num;//changes in m must not effect num  
        while(m!=0)
        {
            //edge case 
            if(m==0) return 1;

            mask=(mask<<1) | 1;
            m=m>>1;
        }
        int ans =(~num) & mask;
        return ans;
    }
};
