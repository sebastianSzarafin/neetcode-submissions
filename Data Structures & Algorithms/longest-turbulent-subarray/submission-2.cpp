
class Solution {
private:
    bool turbulence(int a, int b, bool useLess) {
        if (useLess) {
            return a < b;
        }
        return a > b;
    }

public:
    int maxTurbulenceSize(std::vector<int>& arr) {
        const int n = arr.size();

        int result = 1;

        int i = 0;
        while (i + 1 < n) {
            if (arr[i] == arr[i + 1]) {
                i++;
                continue;
            }
            int j = i;
            int op = arr[j] < arr[j + 1];
            while (j + 1 < n && turbulence(arr[j], arr[j + 1], op)) {
                op = !op;
                j++;
            }
            result = std::max(result, j - i + 1);
            i = j;
        }

        return result;
    }
};