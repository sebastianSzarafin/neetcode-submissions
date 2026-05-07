class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        std::vector<int> tails;
        
        for (int num : nums) {
            // Find the first element in tails that is >= num
            auto it = std::lower_bound(tails.begin(), tails.end(), num);
            
            if (it == tails.end()) {
                // If no such element exists, num is larger than everything; extend the LIS
                tails.push_back(num);
            } else {
                // If found, replace it. This makes the tail of a subsequence of that length smaller,
                // which gives us a better chance to extend it later.
                *it = num;
            }
        }
        
        return tails.size();
    }
};
