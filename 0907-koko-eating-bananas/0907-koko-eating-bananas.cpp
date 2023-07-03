class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = getMaxPile(piles);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canEatWithinTime(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    int getMaxPile(vector<int>& piles) {
        int maxPile = INT_MIN;
        
        for (int pile : piles) {
            maxPile = max(maxPile, pile);
        }
        
        return maxPile;
    }
    
    bool canEatWithinTime(vector<int>& piles, int speed, int h) {
        long long totalHours = 0;
        
        for (int pile : piles) {
            totalHours += ceil((double)pile / (double)speed);
            
            if (totalHours > h) {
                return false;
            }
        }
        
        return true;
    }
};
