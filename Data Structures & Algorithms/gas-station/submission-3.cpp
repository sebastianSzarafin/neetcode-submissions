class Solution {
private:
    int maxSubarraySumIdxCircular(std::vector<int>& nums) {
        const int n = nums.size();

        std::vector<std::pair<int, int>> rightMax(n, std::pair{0, 0});
        int suffixSum = nums[n - 1];
        rightMax[n - 1] = {suffixSum, n - 1};
        for (int i = n - 2; i >= 0; --i) {
            suffixSum += nums[i];
            if (suffixSum > rightMax[i + 1].first) {
                rightMax[i] = {suffixSum, i};
            }
            else {
                rightMax[i] = rightMax[i + 1];
            }
        }

        int maxSum = INT_MIN;
        int maxSumIdx = 0;

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
                    circSum += rightMax[j + 1].first;
                }

                maxSum = std::max({maxSum, sum, circSum});

                if (maxSum == sum) {
                    maxSumIdx = i;
                }
                else if (maxSum == circSum) {
                    maxSumIdx = rightMax[j + 1].second;
                }

                j++;
                if (sum <= 0) { break; }
            }
            i = j;
        }

        return maxSumIdx;
    }

public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();

        std::vector<int> dG(n);

        for (int i = 0; i < n; ++i) {
            dG[i] = gas[i] - cost[i];
        }

        int i = maxSubarraySumIdxCircular(dG);
        std::cout << i << "\n";
        int j = i;
        int gasLeft = 0;

        do {
            gasLeft += dG[j];
            j = (j + 1) % n;
            if (gasLeft < 0) { return -1; }
        } while (j != i);


        return i;
    }
};
