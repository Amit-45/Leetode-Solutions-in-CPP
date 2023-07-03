class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1; // Starting range for eating speed
        int right = getMaxPile(piles); // Maximum pile size
        int answer = -1; // Variable to store the result
        
        while (left <= right) { // Use <= instead of < in the loop condition
            int mid = left + (right - left) / 2; // Calculate the middle speed
            
            if (canEatWithinTime(piles, mid, h)) {
                // If eating within time is possible, adjust the right boundary and update the answer
                right = mid - 1;
                answer = mid;
            } else {
                // If eating within time is not possible, adjust the left boundary
                left = mid + 1;
            }
        }
        
        return answer; // Return the minimum eating speed
    }
    
private:
    int getMaxPile(vector<int>& piles) {
        int maxPile = INT_MIN;
        
        // Find the maximum pile size
        for (int pile : piles) {
            maxPile = max(maxPile, pile);
        }
        
        return maxPile;
    }
    
    bool canEatWithinTime(vector<int>& piles, int speed, int h) {
        long long totalHours = 0; // Total hours taken to eat all piles
        
        for (int pile : piles) {
            totalHours += ceil((double)pile / (double)speed);
            
            if (totalHours > h) {
                // If total hours exceed the given limit, eating is not possible within time
                return false;
            }
        }
        
        return true; // Eating is possible within time
    }
};
