class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        bool findDigit = false;
        bool isNeg = false;
        const int POS_MAX_DIV_TEN = (1 << 30) / 10 * 2;
        const int NEG_MAX_DIV_TEN = (-1 << 30) / 10 * 2;
        const int POS_MAX_MOD_TEN = (((1 << 30) - 1) * 2 + 1) % 10;
        const int NEG_MAX_MOD_TEN = (-1 << 31) % 10;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] <= '9' && s[i] >= '0') {
                findDigit = true;
                if (ans >= 1e8) {
                    if (isNeg) {
                        if (ans * -1 < NEG_MAX_DIV_TEN) {
                            return NEG_MAX_DIV_TEN * 10 + NEG_MAX_MOD_TEN;
                        }
                        else if (ans * -1 == NEG_MAX_DIV_TEN) {
                            if (s[i] - '0' >= -1 * NEG_MAX_MOD_TEN) {
                                return NEG_MAX_DIV_TEN * 10 + NEG_MAX_MOD_TEN;
                            }
                        }
                    }
                    else {
                        if (ans > POS_MAX_DIV_TEN) {
                            return POS_MAX_DIV_TEN * 10 + POS_MAX_MOD_TEN;
                        }
                        else if (ans == POS_MAX_DIV_TEN) {
                            if (s[i] - '0' >= POS_MAX_MOD_TEN) {
                                return POS_MAX_DIV_TEN * 10 + POS_MAX_MOD_TEN;
                            }
                        }
                    }
                }
                ans *= 10;
                ans += s[i] - '0';
                continue;
            }
            if (findDigit) {
                break;
            }
            if (s[i] == '-' || s[i] == '+') {
                findDigit = true;
                isNeg = s[i] == '-';
            }
            else if (s[i] != ' ') {
                break;
            }
        }
        return (isNeg ? -1 : 1) * ans;
    }
};
