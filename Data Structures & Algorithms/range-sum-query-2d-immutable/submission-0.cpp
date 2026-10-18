class NumMatrix {
private:
    std::vector<std::vector<int>> sum_matrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        int n = 0;
        if (m) {
            n = matrix[0].size();
        }

        sum_matrix = std::vector(m, std::vector(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i) {
                    sum_matrix[i][j] += sum_matrix[i - 1][j];
                }
                if (j) {
                    sum_matrix[i][j] += sum_matrix[i][j - 1];
                }
                if (i && j) {
                    sum_matrix[i][j] -= sum_matrix[i - 1][j - 1];
                }
                sum_matrix[i][j] += matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = sum_matrix[row2][col2];
        if (row1) { 
            result -= sum_matrix[row1 - 1][col2];
        }
        if (col1) {
            result -= sum_matrix[row2][col1 - 1];
        }
        if (row1 && col1) {
            result += sum_matrix[row1 - 1][col1 - 1];
        }
        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */