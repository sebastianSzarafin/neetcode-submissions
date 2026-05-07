class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) { return 1.0; }

        std::vector<double> pows;
        
        double y = n > 0 ? x : 1 / x;
        n = std::abs(n);

        pows.push_back(y);

        int i = 2;
        while (n > i) {
            y *= y;
            pows.push_back(y);
            i *= 2;
        }

        n -= i / 2;
        i = 0;
        while (n > 0) {
            if (n & 1) {
                y *= pows[i];
            }
            n = n >> 1;
            i++;
        }

        return y;
    }
};
