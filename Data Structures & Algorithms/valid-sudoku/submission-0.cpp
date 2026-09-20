#include <bitset>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        using bitset = std::bitset<10>;
        
        const std::size_t n = board.size();

        std::vector<bitset> rows(n);
        std::vector<bitset> cols(n);
        std::vector<std::vector<bitset>> squares(n / 3, std::vector<bitset>(n / 3));

        for (std::size_t r = 0; r < board.size(); ++r) {
            for (std::size_t c = 0; c < board[0].size(); ++c) {

                const int x = board[r][c] - '0'; 

                if (x < 0 || x > 9) {
                    continue;
                }
                
                bitset mask;
                mask.set(x);

                if ((rows[r] & mask).any() 
                    || (cols[c] & mask).any()
                    || (squares[r / 3][c / 3] & mask).any()) {
                    return false;
                }

                rows[r] |= mask;
                cols[c] |= mask;
                squares[r / 3][c / 3] |= mask;
            }
        }

        return true;
    }
};
