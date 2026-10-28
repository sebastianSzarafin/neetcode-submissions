class Solution {
public:
    int numDecodings(string s) {
        const int n = s.size();

        std::vector<int> dp(n + 1, 0);
        dp[n] = 1; // empty string case
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                dp[i] = 0;
            }
            else {
                dp[i] = dp[i + 1];
                if (i + 1 < n) {
                    const int code = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (code <= 26) {
                        dp[i] += dp[i + 2];
                    }
                }
            }
        }

        return dp[0];
    }
};
