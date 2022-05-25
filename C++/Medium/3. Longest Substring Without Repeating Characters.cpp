class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int head = 0;
        for (int i = 1; i < s.length(); ++i) {
            // find the position of identical character from head
            int search = s.find_first_of(s[i], head);
            // if identical character find before now position
            if (search < i) {
                // record longest length of substr
                if (i - head > ans) {
                    ans = i - head;
                }
                // update head
                head = search + 1;
            }
        }
        // return if the length from head is longer than answer
        int lastlen = s.length() - head;
        if (lastlen > ans) {
            return lastlen;
        }
        return ans;
    }
};
