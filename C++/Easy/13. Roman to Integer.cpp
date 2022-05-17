class Solution {
private:
    map<char, int> Roman_table;
public:
    Solution() {
        // 建立table
        Roman_table['0'] = 0;
        Roman_table['I'] = 1;
        Roman_table['V'] = 5;
        Roman_table['X'] = 10;
        Roman_table['L'] = 50;
        Roman_table['C'] = 100;
        Roman_table['D'] = 500;
        Roman_table['M'] = 1000;
    }
    ~Solution() {
        Roman_table.clear();
    }
    int romanToInt(string s) {
        // result 紀錄最終結果, count 暫存計數, last_char 紀錄上個字母
        int result = 0;
        int count = 0;
        char last_char = '0';
        for(int i = 0; i < s.length(); i++) {
            // 前 > 後 => 將前者累計數值加入結果, 並將後者加入計數
            if(Roman_table[last_char] > Roman_table[s.at(i)]) {
                result += count;
                count = Roman_table[s.at(i)];
            }
            // 前 = 後 => 將後者加入計數
            else if(Roman_table[last_char] == Roman_table[s.at(i)]) {
                count += Roman_table[s.at(i)];
            }
            // 前 < 後 => 將後者扣除計數後加入結果
            else {
                result += Roman_table[s.at(i)] - count;
                count = 0;
            }
            last_char = s.at(i);
        }
        // 最後不用比對直接加入結果
        result += count;
        // 回傳結果
        return result;
    }
};