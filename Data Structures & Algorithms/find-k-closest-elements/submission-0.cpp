class Solution {
private:
    bool closer(const int a, const int b, const int x) {
        const int d1 = std::abs(a - x);
        const int d2 = std::abs(b - x);
        if (d1 == d2) {
            return a < b;
        }
        return d1 < d2;
    }

public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int n = arr.size();
        
        if (!k) {
            return {};
        }

        int closest = 0;

        for (int i = 0; i < n; ++i) {
            if (closer(arr[i], arr[closest], x)) {
                closest = i;
            }
        }

        std::vector<int> result{};

        int l = closest;
        int r = closest;

        while (--k) {
            if (l > 0 && r + 1 < n) {
                if (closer(arr[l - 1], arr[r + 1], x)) {
                    l--;
                }
                else {
                    r++;
                }
            }
            else if (l > 0) {
                l--;
            }
            else {
                r++;
            }
        }

        for (int i = l; i <= r; ++i) {
            result.emplace_back(arr[i]);
        }

        return result;
    }
};