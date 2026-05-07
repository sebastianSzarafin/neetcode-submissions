class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();

        if (n == 1) { return 0; }

        int jumps = 1;

        int l = 0;
        int r = l + nums[l];
        while (r < n - 1) {
            int farthest = 0;
            for (int j = l; j <= r; ++j) {
                farthest = std::max(farthest, j + nums[j]);
            }
            l = r;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};


