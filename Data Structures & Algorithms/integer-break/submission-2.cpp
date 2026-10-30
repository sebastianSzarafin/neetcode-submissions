class Solution {
public:
    int integerBreak(int n) {
        
        int prod = 0;
        
        int k = 2;
        while (k <= n) {
            int p = n / k;
            int r = n % k;
            std::cout << k << " " << p << " " << r << " " << (int)std::round(std::pow(p + 1, r) * std::pow(p, k - r)) << "\n";
            prod = std::max(prod, (int)std::round(std::pow(p + 1, r) * std::pow(p, k - r)));
            k++;
        }

        return prod;
    }
};