class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int n = matrix.size();
        const int m = matrix[0].size();

        int row = 0;

        while (row < n && matrix[row][m - 1] < target) {
            row++;
        }

        if (row == n) {
            return false;
        }

        int l = 0, r = m - 1;

        while (l <= r) {
            int m = (l + r) / 2;

            if (matrix[row][m] > target) {
                r = m - 1;
            }
            else if (matrix[row][m] < target) {
                l = m + 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};
