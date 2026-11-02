class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        const int n = nums.size();

        std::vector<int> rightMax(n, 0);
        int suffixSum = nums[n - 1];
        rightMax[n - 1] = suffixSum;
        for (int i = n - 2; i >= 0; --i) {
            suffixSum += nums[i];
            rightMax[i] = std::max(suffixSum, rightMax[i + 1]);
        }

        int result = INT_MIN;

        int i = 0;
        int prefixSum = 0;
        while (i < n) {
            int j = i;
            int sum = 0;
            while (j < n) {
                sum += nums[j];
                prefixSum += nums[j];

                int circSum = prefixSum;
                if (j + 1 < n) {
                    circSum += rightMax[j + 1];
                }
                result = std::max({result, sum, circSum});

                j++;
                if (sum <= 0) { break; }
            }
            i = j;
        }

        return result;
    }
};
