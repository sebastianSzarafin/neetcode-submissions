// ############################# Brute force; O(n!) ####################################
// class Solution {
// private:
//     int dfs(std::vector<int>& currStones, const int destroyed) {
        
//         const int n = currStones.size();
//         if (n == destroyed) { return 0; }
//         if (n - 1 == destroyed) { 
//             for (int i = 0; i < n; ++i) {
//                 if (currStones[i] != -1) {
//                     return currStones[i];
//                 }
//             }
//          }

//         int result = INT_MAX;

//         for (int i = 0; i < n; ++i) {

//             if (currStones[i] == -1) { continue; }

//             for (int j = 0; j < n; ++j) {

//                 if (i == j) { continue; }
//                 if (currStones[j] == -1) { continue; }

//                 int si = currStones[i];
//                 int sj = currStones[j];
                
//                 int w = std::abs(si - sj);

//                 currStones[i] = -1;
//                 currStones[j] = -1;

//                 int d;

//                 if (w) {
//                     currStones[j] = w;
//                     d = 1;
//                 }
//                 else {
//                     d = 2;
//                 }

//                 result = std::min(result, dfs(currStones, destroyed + d));

//                 currStones[i] = si;
//                 currStones[j] = sj;
//             }
//         }

//         return result;
//     }

// public:
//     int lastStoneWeightII(vector<int>& stones) {
//         return dfs(stones, 0);
//     }
// };

// ############################# Brute force; O(2^n) ####################################
// class Solution {
// private:
//     int dfs(const std::vector<int>& stones, const int i, const int currSum, const int totalSum) {
//         if (i == stones.size()) {
//             return std::abs(currSum - (totalSum - currSum)); // sum(S1) - sum(S2)
//         }

//         return std::min(
//             dfs(stones, i + 1, currSum, totalSum),
//             dfs(stones, i + 1, currSum + stones[i], totalSum)
//         );
//     }

// public:
//     int lastStoneWeightII(vector<int>& stones) {
        
//         const int total = std::accumulate(stones.begin(), stones.end(), 0);

//         return dfs(stones, 0, 0, total);
//     }
// };

// ############################# DP; O(n^2) ####################################
class Solution {
private:
    vector<vector<int>> dp;

public:
    int lastStoneWeightII(vector<int>& stones) {
        int stoneSum = accumulate(stones.begin(), stones.end(), 0);
        int target = (stoneSum + 1) / 2;
        dp = vector<vector<int>>(stones.size(), vector<int>(target + 1, -1));
        return dfs(0, 0, stones, stoneSum, target);
    }

private:
    int dfs(int i, int total, const vector<int>& stones, int stoneSum, int target) {
        if (total >= target || i == stones.size()) {
            return abs(total - (stoneSum - total));
        }
        if (dp[i][total] != -1) {
            return dp[i][total];
        }

        dp[i][total] = min(
            dfs(i + 1, total, stones, stoneSum, target),
            dfs(i + 1, total + stones[i], stones, stoneSum, target)
        );
        return dp[i][total];
    }
};