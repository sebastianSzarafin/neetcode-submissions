class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const auto n = nums.size();

        std::vector<int> left(n);
        std::vector<int> right(n);
        
        if (n >= 1) left[0] = nums[0];
        if (n - 2 >= 0) right[n - 1] = nums[n - 1];

        for (std::size_t i = 1; i < n; ++i) {
            left[i] = left[i - 1] * nums[i]; 
            right[n - 1 - i] = right[n - 1 - i + 1] * nums[n - 1 - i];
        }

        std::vector<int> result(n);

        result[0] = right[1];
        result[n - 1] = left[n - 2];
        for (std::size_t i = 1; i < n - 1; ++i) {
            result[i] = left[i - 1] * right[i + 1];
        }

        return result;
    }
};
