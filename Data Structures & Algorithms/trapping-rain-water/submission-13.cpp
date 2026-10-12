class Solution {
public:
    int trap(vector<int>& height) {
        const std::size_t n = height.size();

        if (n < 3) {
            return 0;
        }

        if (n == 3) {
            return std::max(std::min(height[0], height[2]) - height[1], 0);
        }

        std::vector<int> left_max(n, 0);
        std::vector<int> right_max(n, 0);

        for (std::size_t i = 1; i < n - 1; ++i) {
            left_max[i] = std::max(left_max[i - 1], height[i - 1]);
            right_max[n - i - 1] = std::max(right_max[n - i], height[n - i]);
        }
        
        // for (std::size_t i = 0; i < n; ++i) {
        //     std::cout << left_max[i] << "\t";
        // }
        // std::cout << "\n\n";

        for (std::size_t i = 0; i < n; ++i) {
            std::cout << right_max[i] << "\t";
        }
        // std::cout << "\n\n";

        int result = 0;

        for (std::size_t i = 0; i < n; ++i) {
            result += std::max(std::min(left_max[i], right_max[i]) - height[i], 0);
            // std::cout << std::min(left_max[i], right_max[i]) - height[i] << "\t";
        }

        return result;
    }
};
