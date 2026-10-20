class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int n = nums.size();
        
        int l = 0;
        int sum = 0;
        int result = INT_MAX;

        for (int r = l; r < n; ++r) {
            sum += nums[r];
            while (l < r && sum - nums[l] >= target) {
                sum -= nums[l];
                l++;
            }
            if (sum >= target) {
                result = std::min(result, r - l + 1);
            }
        }

        return result != INT_MAX ? result : 0;
  }
};