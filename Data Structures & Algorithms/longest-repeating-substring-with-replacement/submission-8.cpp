class Solution {
public:
    int characterReplacement(string s, int k) {
       vector<int> count(26, 0);
        
        int left = 0;
        int max_freq = 0; // Frequency of the most common char in the current window
        int max_len = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            // 1. Add the current character to the window
            // Subtract 'A' to map ASCII values to 0-25 index
            count[s[right] - 'A']++;
            
            // 2. Update the max frequency found so far in this window
            max_freq = max(max_freq, count[s[right] - 'A']);
            
            // 3. Check if the current window is valid.
            // Formula: (Window Length) - (Most Frequent Char Count) <= k
            // If the remaining characters are more than k, the window is invalid.
            if ((right - left + 1) - max_freq > k) {
                // Shrink the window from the left
                count[s[left] - 'A']--;
                left++;
            }
            
            // 4. Update the global maximum length
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};
