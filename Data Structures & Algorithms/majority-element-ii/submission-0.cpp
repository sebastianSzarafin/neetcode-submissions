class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::pair<int, int> nc1 = {INT_MAX, 0}; // [num1, count1]
        std::pair<int, int> nc2 = {INT_MAX, 0}; // [num2, count2]

        for (const auto n : nums) {
            auto& [n1, c1] = nc1;
            auto& [n2, c2] = nc2;
            if (n == n1) {
                c1++;
            }
            else if (n == n2) {
                c2++;
            }
            else if (!c1) {
                n1 = n;
                c1 = 1;
            }
            else if (!c2) {
                n2 = n;
                c2 = 1;
            }
            else {
                c1--;
                c2--;
            }
        }

        const int n1 = nc1.first;
        const int n2 = nc2.first;
        int c1 = 0;
        int c2 = 0;

        for (const auto n : nums) {
            if (n == n1) {
                c1++;
            }
            else if(n == n2) {
                c2++;
            }
        }

        std::vector<int> result{};

        const int s = nums.size() / 3;
        if (c1 > s) { result.emplace_back(n1); }
        if (c2 > s) { result.emplace_back(n2); }

        return result;
    }
};