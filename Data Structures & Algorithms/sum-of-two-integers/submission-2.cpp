class Solution {
public:
    int getSum(int a, int b) {
        
        while (b != 0) {
            // 1. Calculate the carry
            // We cast to unsigned to avoid runtime errors with 
            // signed integer overflow (especially for negative numbers).
            unsigned int carry = (unsigned int)(a & b) << 1;
            
            // 2. Calculate the sum without carry
            a = a ^ b;
            
            // 3. Move carry to b to process in the next iteration
            b = carry;
        }
        return a;
    }
};

// a = -1  1111
// b = 1   0001

// carry = 0010
// a = 1110
// b = 0010

// carry = 0100
// a = 1100
// b = 0100

// carry = 1000
// a = 1000
// b = 1000

// carry = 0000
// a = 0000
// b = 0000


