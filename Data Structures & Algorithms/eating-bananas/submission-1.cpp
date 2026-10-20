class Solution {
private:
    int timeForGivenK(const std::vector<int>& piles, const int k) {
        int t = 0;
        for (const auto p : piles) {
            t += std::ceil(p / (double)k);
        }
        return t;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1;
        int r = std::ranges::max(piles);
        int res = r;

        while (l <= r) {
            int m = (l + r) / 2;
            int t = timeForGivenK(piles, m);
            if (t > h) {
                l = m + 1;
            }
            else {
                res = std::min(res, m);
                r = m - 1;
            }
        }

        return res;
    }
};
