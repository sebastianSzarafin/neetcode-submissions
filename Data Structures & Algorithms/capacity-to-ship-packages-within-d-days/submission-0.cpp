class Solution {
private:
    int daysForGivenCap(std::vector<int>& weights, int max_cap) {
        const int n = weights.size();

        int t = 0;
        
        int i = 0;
        while (i < n) {
            int cap = 0;
            while (i < n && cap + weights[i] <= max_cap) {
                cap += weights[i];
                i++;
            }
            t++;
        }

        return t;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = std::ranges::max(weights);
        int r = std::accumulate(weights.begin(), weights.end(), 0);
        int res = r;

        while (l <= r) {
            int m = (l + r) / 2;
            int t = daysForGivenCap(weights, m);
            if (t > days) {
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