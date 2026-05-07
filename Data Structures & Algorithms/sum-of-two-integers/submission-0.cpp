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
