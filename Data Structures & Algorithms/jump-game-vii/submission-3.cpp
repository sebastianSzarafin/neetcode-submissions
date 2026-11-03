class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        const int n = s.size();
        
        std::vector<bool> dp(n, false);
        dp[0] = true;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (!dp[i]) { continue; }
            j = std::max(j, i + minJump);
            int d = std::min(i + maxJump, n - 1);
            while (j <= d) {
                if (s[j] == '0') {
                    dp[j] = true;
                }
                j++;
            }
        }

        return dp[n - 1];
    }
};