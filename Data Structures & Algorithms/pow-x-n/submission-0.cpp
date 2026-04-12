class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }

        if (n == 0) {
            return 1;
        }

        int sqr = abs(n) / 2;
        double ret = 1;
        while (sqr > 0) {
            ret *= x;
            sqr--; 
        }

        ret *= ret;

        if (abs(n) % 2 == 1) {
            ret *= x;
        }

        return n > 0 ? ret : (1 / ret);
    }
};
