class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> hash_set;

        for (const auto n : nums) {
            if (!hash_set.contains(n)) {
                hash_set.insert(n);
            }
        }

        const auto n = nums.size();

        int max_seq = 0;
        for (std::size_t i = 0; i < n; ++i) {
            if (hash_set.contains(nums[i] - 1)) { continue; }
            int num = nums[i];
            while (hash_set.contains(num)) { ++num; }
            max_seq = std::max(max_seq, num - nums[i]);
        }
        
        return max_seq;
    }
};
