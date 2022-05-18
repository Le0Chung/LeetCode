class Solution {
public:
    Solution() {
    }
    ~Solution() {
    }
    int romanToInt(string s) {
        regex reg("(M)?(M)?(M)?(CM)?(CD)?(D)?(C)?(C)?(C)?(XC)?(XL)?(L)?(X)?(X)?(X)?(IX)?(IV)?(V)?(I)?(I)?(I)?");
        smatch sm;
        regex_match(s, sm, reg);
        // 回傳結果
        return (sm[1].length() ? 1000 : 0) + (sm[2].length() ? 1000 : 0) + (sm[3].length() ? 1000 : 0) + (sm[4].length() ? 900 : 0) + (sm[5].length() ? 400 : 0) + (sm[6].length() ? 500 : 0) + (sm[7].length() ? 100 : 0) + (sm[8].length() ? 100 : 0) + (sm[9].length() ? 100 : 0) + (sm[10].length() ? 90 : 0) + (sm[11].length() ? 40 : 0) + (sm[12].length() ? 50 : 0) + (sm[13].length() ? 10 : 0) + (sm[14].length() ? 10 : 0) + (sm[15].length() ? 10 : 0) + (sm[16].length() ? 9 : 0) + (sm[17].length() ? 4 : 0) + (sm[18].length() ? 5 : 0) + (sm[19].length() ? 1 : 0) + (sm[20].length() ? 1 : 0) + (sm[21].length() ? 1 : 0);
    }
};