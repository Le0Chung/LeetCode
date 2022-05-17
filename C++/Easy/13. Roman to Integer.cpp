class Solution {
private:
    map<char, int> Roman_table;
public:
    Solution() {
        // 建立table
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
        // result 紀錄最終結果
        int result = 0;
        for(int i = 0; i < s.length() - 1; i++) {
            // 前 >= 後 => 將前者數值加入結果
            if(Roman_table[s[i]] >= Roman_table[s[i + 1]]) {
                result += Roman_table[s[i]];
            }
            // 前 < 後 => 將結果扣除前者數值
            else {
                result -= Roman_table[s[i]];
            }
        }
        // 最後不用比對直接加入結果
        result += Roman_table[s.back()];
        // 回傳結果
        return result;
    }
};