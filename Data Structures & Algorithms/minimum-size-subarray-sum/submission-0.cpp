class Solution {
public:
    using ll = long long;

    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, min_len = 1e6;
        ll sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum >= target) {
                while (sum >= target) {
                    sum -= nums[left++];
                }
                min_len = min(min_len, i - left + 2);
            }
        }
        if (min_len == 1e6) {
            min_len = 0;
        }
        return min_len;
    }
};