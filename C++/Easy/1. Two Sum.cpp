class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (auto i = nums.begin(); i != nums.end(); ++i) {
            int val = target - *i;
            auto check = find(i + 1, nums.end(), val);
            if (check != nums.end()) {
                return {int(distance(nums.begin(), i)), int(distance(nums.begin(), check))};
            }
        }
        return {};
    }
};
