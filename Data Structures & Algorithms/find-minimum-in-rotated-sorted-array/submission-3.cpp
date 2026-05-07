class Solution {
public:
    int findMin(vector<int> &nums) {
    const auto n = nums.size();

    std::size_t l = 0;
    std::size_t r = n - 1;
    while (nums[r] < nums[l]) {
        std::size_t s = std::ceil((l + r) / 2.0f);
        if (s == r || nums[s] > nums[r]) {
            l = s;
        }
        else {
            r = s;
        }
    }
    return nums[l];
    }
};
