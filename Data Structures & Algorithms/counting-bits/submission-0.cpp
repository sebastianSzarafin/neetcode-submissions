class Solution {
public:

    int numberOf1Bits(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }

    vector<int> countBits(int n) {
        std::vector<int> result(n + 1);
        for (int i = 0; i <= n; ++i) {
            result[i] = numberOf1Bits(i);
        }
        return result;
    }
};
