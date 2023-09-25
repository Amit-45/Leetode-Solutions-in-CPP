class Solution {
public:
    int kthFactor(int n, int k) {
        int factor;
        for (factor = 1; factor * factor < n; ++factor) {
            if (n % factor == 0 && --k == 0) {
                return factor;
            }
        }
        for (factor = static_cast<int>(sqrt(n)); factor > 0; --factor) {
            if (n % (n / factor) == 0 && --k == 0) {
                return n / factor;
            }
        }

        return -1;
    }
};
