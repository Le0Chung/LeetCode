class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        bool arr[256] = {};
        queue<char> q;
        for (int i = 0; i < s.length(); ++i) {
            if (arr[s[i]]) {
                if (q.size() > ans) {
                    ans = q.size();
                }
                while (q.front() != s[i]) {
                    arr[q.front()] = false;
                    q.pop();
                }
                q.pop();
                q.push(s[i]);
            }
            else {
                arr[s[i]] = true;
                q.push(s[i]);
            }
        }
        if (q.size() > ans) {
            return q.size();
        }
        return ans;
    }
};
