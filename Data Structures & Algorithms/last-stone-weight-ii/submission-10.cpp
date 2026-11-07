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
    int dfs(const std::vector<int>& stones, const int i, const int currSum) {
        if (currSum >= m_targetSum || i == stones.size()) {
            return std::abs(currSum - (m_totalSum - currSum)); // sum(S1) - sum(S2)
        }

        if (m_dp[i][currSum].has_value()) {
            return *m_dp[i][currSum];
        }

        m_dp[i][currSum] = std::min(
            dfs(stones, i + 1, currSum),
            dfs(stones, i + 1, currSum + stones[i])
        );

        return *m_dp[i][currSum];
    }

    std::vector<std::vector<std::optional<int>>> m_dp;
    int m_totalSum;
    int m_targetSum;

public:
    int lastStoneWeightII(vector<int>& stones) {
        
        m_totalSum = std::accumulate(stones.begin(), stones.end(), 0);
        m_targetSum = std::ceil(m_totalSum / 2.0);

        m_dp = std::vector(stones.size(), std::vector(m_targetSum, std::optional<int>{}));

        return dfs(stones, 0, 0);
    }
};