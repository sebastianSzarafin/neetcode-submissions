class Solution {
public:
    uint32_t reverseBits(uint32_t n) {        
        uint32_t res = 0;
        for (std::size_t i = 0; i <= 31; ++i)
        {
            if ((n >> i) & 1)
            {
                res |= (1 << (31 - i));
            }
        }
        return res;

        // Alternatywnie
        uint32_t result = 0;
        for (int i = 0; i <= 31; ++i) {
            result |= ((n >> i) & 1) << (31 - i);
        }
        return result;
    }
};
