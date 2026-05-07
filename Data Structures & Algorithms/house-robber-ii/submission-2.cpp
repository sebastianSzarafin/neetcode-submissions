class Solution {
public:
    int rob_range(const std::vector<int>& nums, int l, int r) {
        const int n = r - l + 1;
        std::vector<int> d(n, 0);
        d[0] = nums[l];
        if (n == 1) { return d[0]; }
        d[1] = std::max(nums[l], nums[l + 1]);
        for (int i = 2; i < n; ++i) {
            d[i] = std::max(d[i - 2] + nums[l + i], d[i - 1]);
        }
        return std::max(d[n - 1], d[n - 2]);
    }

    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) { return nums[0]; }
        return std::max(rob_range(nums, 0, n - 2), rob_range(nums, 1, n - 1));      
    }
};
