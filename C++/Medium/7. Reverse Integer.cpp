class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int tmp = x;
        const int POS_MAX_DIV_TEN = (1 << 30) / 10 * 2;
        const int NEG_MAX_DIV_TEN = (-1 << 30) / 10 * 2;
        const int POS_MAX_MOD_TEN = (((1 << 30) - 1) * 2 + 1) % 10;
        const int NEG_MAX_MOD_TEN = (-1 << 31) % 10;
        while(tmp / 10) {
            rev *= 10;
            rev += tmp % 10;
            tmp /= 10;
        }
        if (x > 1e9 || x < -1e9) {
            if (rev > POS_MAX_DIV_TEN || rev < NEG_MAX_DIV_TEN) {
                return 0;
            }
            else if (rev == POS_MAX_DIV_TEN || rev == NEG_MAX_DIV_TEN) {
                if (tmp > POS_MAX_MOD_TEN || tmp < NEG_MAX_MOD_TEN) {
                    return 0;
                }
            }
        }
        rev *= 10;
        rev += tmp;
        return rev;
    }
};
