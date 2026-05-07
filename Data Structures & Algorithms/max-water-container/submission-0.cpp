class Solution {
public:
    int maxArea(vector<int>& heights) {
        const auto n = heights.size();

        int result = 0;

        std::size_t l = 0;
        std::size_t r = n - 1;
        while (l != r) {
            const int area = (r - l) * std::min(heights[l], heights[r]);
            result = std::max(result, area);
            if (heights[l] < heights[r]) {
                ++l;
            } 
            else {
                --r;
            }
        }

        return result;
    }
};
