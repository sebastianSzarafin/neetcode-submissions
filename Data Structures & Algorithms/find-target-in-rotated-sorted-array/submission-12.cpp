class Solution {
private:
    std::pair<int, int> findMin(const vector<int>& nums) {

        std::pair<int, int> res = {INT_MAX, -1};

        int l = 0, r = nums.size() - 1;
        while (true) {
            int m = (l + r) / 2;

            if (nums[m] < res.first) {
                res = {nums[m], m};
            }

            if (nums[l] > nums[r]) {
                if (nums[m] > nums[r]) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            else {
                if (nums[l] < res.first) {
                    res = {nums[l], l};
                }
                break;
            }
        }

        return res;
    }

    int binarySearch(const vector<int>& nums, const int target, int l, int r) {
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                return m;
            }
            else if (nums[m] > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        const auto[n, i] = findMin(nums);
        if (n <= target && target <= nums.back()) { 
            return binarySearch(nums, target, i, nums.size() - 1);
        }
        return binarySearch(nums, target, 0, std::max(0, i - 1));
    }
};
