class Solution {
private:
    int water_above_h(const int l, const int r, const int h) {
        return std::max(std::min(l, r) - h, 0);
    }
public:
    int trap(vector<int>& height) {
        const std::size_t n = height.size();

        if (n < 3) {
            return 0;
        }

        if (n == 3) {
            return water_above_h(height[0], height[2], height[1]);
        }

        std::vector<int> left_max(n, 0);
        std::vector<int> right_max(n, 0);

        for (std::size_t i = 1; i < n - 1; ++i) {
            left_max[i] = std::max(left_max[i - 1], height[i - 1]);
            right_max[n - i - 1] = std::max(right_max[n - i], height[n - i]);
        }
        
        int result = 0;

        for (std::size_t i = 0; i < n; ++i) {
            result += water_above_h(left_max[i], right_max[i], height[i]);
        }

        return result;
    }
};
