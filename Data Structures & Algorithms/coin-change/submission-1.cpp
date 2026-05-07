class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 1. Create a DP table to store results for sub-problems.
        // Size is amount + 1 to handle index 0 to amount.
        // Initialize with 'amount + 1', which acts as "infinity" here.
        // (We use amount + 1 because the max coins needed is 'amount' using 1-unit coins,
        // so anything larger indicates it's unreachable).
        vector<int> dp(amount + 1, amount + 1);

        // 2. Base Case: 0 coins are needed to make amount 0.
        dp[0] = 0;

        // 3. Fill the DP table
        // Iterate through every total amount from 1 up to the target amount
        for (int i = 1; i <= amount; ++i) {
            // Check every coin denomination
            for (int coin : coins) {
                // If the current coin fits into the current amount 'i'
                if (i - coin >= 0) {
                    // The transition:
                    // dp[i] = min(current value, 1 + value of remainder)
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // 4. Check if the target amount is reachable
        // If the value is still our initial "infinity", return -1
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};
