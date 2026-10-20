class Solution {
public:
    int findMin(vector<int> &nums) {

        int res = INT_MAX;

        int l = 0, r = nums.size() - 1;
        while (true) {
            int m = (l + r) / 2;

            res = std::min(res, nums[m]);

            if (nums[l] > nums[r]) {
                if (nums[m] > nums[r]) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            else {
                res = std::min(res, nums[l]);
                break;
            }
        }

        return res;
    }
};
