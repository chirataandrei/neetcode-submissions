class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> char_set;
        int left = 0, max_len = 0;
        for (int right = 0; right < s.size(); right++) {
            while (char_set.find(s[right]) != char_set.end()) {
                char_set.erase(s[left]);
                left++;
            }
            char_set.insert(s[right]);
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};