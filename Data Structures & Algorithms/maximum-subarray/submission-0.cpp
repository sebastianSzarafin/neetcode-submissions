class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const auto n = nums.size();

        int max_sum = INT_MIN;
        int i = 0;
        while (i < n) {
            int sum = 0;
            int j = i;
            for (; j < n; ++j) {
                sum += nums[j];
                max_sum = std::max(max_sum, sum);
                if (sum <= 0) { j++; break; }    
            }
            i = j;
        }

        return max_sum;
    }
};
