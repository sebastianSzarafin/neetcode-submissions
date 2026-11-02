class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        const int n = nums.size();
        if (!n) { return false; }

        int end = n - 1;
        for (int i = end - 1; i >= 0; --i) {
            if (i + nums[i] >= end) {
                end = i;
            }
        }
        
        return end == 0;
    }
};