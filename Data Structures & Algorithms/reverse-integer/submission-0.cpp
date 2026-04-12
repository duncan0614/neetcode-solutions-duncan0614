class Solution {
public:
    int reverse(int x) {
        const int MIN = -2147483648;
        const int MAX = 2147483647;

        int ret = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (ret > MAX / 10 || (ret == MAX / 10 && digit > MAX % 10)) {
                return 0;
            }

            if (ret < MIN / 10 || (ret == MIN / 10 && digit < MIN % 10)) {
                return 0;
            }

            ret = (ret * 10) + digit;
        }

        return ret;
    }
};
