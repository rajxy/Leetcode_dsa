class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1);

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            // If the character was already seen inside
            // the current window, move left pointer
            if (lastSeen[s[right]] >= left) {
                left = lastSeen[s[right]] + 1;
            }

            // Update the last position of current character
            lastSeen[s[right]] = right;

            // Calculate current window length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};