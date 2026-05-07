class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const auto n = nums.size();

        int mask = 0x00000000;
        
        for (int i = 0; i <= n; ++i) {
            mask ^= i;
        }

        for (int i = 0; i < n; ++i) {
            mask ^= nums[i];
        }

        return mask;
    }
};
