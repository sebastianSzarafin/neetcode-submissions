class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        std::vector<int> d(n, 0);
        d[0] = nums[0];
        if (n == 1) { return d[0]; }
        d[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            d[i] = std::max(d[i - 2] + nums[i], d[i - 1]);
        }
        return std::max(d[n - 1], d[n - 2]);
    }
};
