class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }

        if (n == 0) {
            return 1;
        }

        long sqr = abs((long)n);
        double ret = 1;

        while (sqr) {
            if (sqr & 1) {
                ret *= x;
            }
            x *= x;
            sqr >>= 1; 
        }

        return n > 0 ? ret : (1 / ret);
    }
};
