#include <ranges>

class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();

        if (n <= 1) { return 0; }
        
        auto comp = [&height](const auto& l, const auto& r) { return height[l] < height[r]; };
        std::priority_queue<int, std::vector<int>, decltype(comp)> Q(comp);

        for (const int i : std::views::iota(0, n)) {
            Q.push(i);
        }

        int piv_l = Q.top();
        Q.pop();
        int piv_r = Q.top();
        Q.pop();
        if (piv_l > piv_r) { std::swap(piv_l, piv_r); }

        int area = (piv_r - piv_l - 1) * std::min(height[piv_l], height[piv_r]);

        while (!Q.empty()) {
            int piv = Q.top();
            Q.pop();

            if (piv < piv_l) {
                area += (piv_l - piv - 1) * std::min(height[piv_l], height[piv]);
                piv_l = piv;
            }
            else if (piv > piv_r) {
                area += (piv - piv_r - 1) * std::min(height[piv_r], height[piv]);
                piv_r = piv;
            }
            else {
                area -= height[piv];
            }
        }

        return area;
    }
};
