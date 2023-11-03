class Solution(object):
    def hammingDistance(self, x, y):
        count=0
        while(x or y):
            if((x&1)^(y&1)):
                count+=1
            x>>=1
            y>>=1
        return count
        