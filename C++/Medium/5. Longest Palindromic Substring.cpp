class Solution {
public:
    string longestPalindrome(string s) {
        string ans("");
        // 從字串開頭搜尋，若未搜尋的字串長度已小於找到的字串長度就直接跳出迴圈
        for (int i = 0; i < s.length() - ans.length(); ++i) {
            // 從後面尋找與當前字母相同的位置並切成子字串
            size_t last_search = s.find_last_of(s[i]);
            string tmp = s.substr(i, last_search - i + 1);
            while(tmp.length() > ans.length()) {
                // 若該字串為palindrome，則記錄下來
                if (checkPalindrome(tmp)) {
                    ans = tmp;
                    break;
                }
                // 若不是再從該位置前面繼續尋找
                last_search = s.find_last_of(s[i], last_search - 1);
                tmp = s.substr(i, last_search - i + 1);
            }
        }
        return ans;
    }
    // 判斷該字串是否為palindrome
    bool checkPalindrome(string s) {
        int slen = s.length();
        for (int i = 0; i < slen / 2; ++i) {
            if (s[i] != s[slen - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
