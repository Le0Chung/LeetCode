class Solution {
public:
    string intToRoman(int num) {
        string str("");
        int now_digits = 1;
        int val = 0;
        char one_symbol, five_symbol, ten_symbol;
        while(num) {
            val = num % 10;
            switch(now_digits) {
                // 個位數
                case 1: {
                    one_symbol = 'I';
                    five_symbol = 'V';
                    ten_symbol = 'X';
                }
                break;
                // 十位數
                case 2: {
                    one_symbol = 'X';
                    five_symbol = 'L';
                    ten_symbol = 'C';
                }
                break;
                // 百位數
                case 3: {
                    one_symbol = 'C';
                    five_symbol = 'D';
                    ten_symbol = 'M';
                }
                break;
                // 千位數
                case 4: {
                    one_symbol = 'M';
                    five_symbol = '\0';
                    ten_symbol = '\0';
                }
                break;
                default: {
                    one_symbol = '\0';
                    five_symbol = '\0';
                    ten_symbol = '\0';
                }
                break;
            }
            if (val >= 5) {
                if (val == 9) {
                    str.insert(0, 1, ten_symbol);
                    str.insert(0, 1, one_symbol);
                }
                else {
                    str.insert(0, val % 5, one_symbol);
                    str.insert(0, 1, five_symbol);
                }
            }
            else {
                if (val == 4) {
                    str.insert(0, 1, five_symbol);
                    str.insert(0, 1, one_symbol);
                }
                else {
                    str.insert(0, val, one_symbol);
                }
            }
            num /= 10;
            now_digits += 1;
        }
        return str;
    }
};
