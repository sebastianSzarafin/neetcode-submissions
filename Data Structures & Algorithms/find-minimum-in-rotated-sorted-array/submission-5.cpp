class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int res = INT_MAX;
        while (l <= r) {
            int m = (l + r) / 2;
            res = std::min(res, nums[m]);
            if (nums[l] > nums[r] || nums[l] > nums[m]) {
                l++;
            }
            else {
                r = m - 1;
            }
        }
        return res;
    }
};
