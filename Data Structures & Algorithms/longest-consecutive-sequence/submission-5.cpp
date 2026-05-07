class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        const auto n = nums.size();

        std::set<int> nums_set;

        for (const auto i : nums) {
            nums_set.insert(i);
        }

        int longest_seq = 0;

        for (auto i : nums) {
            if (nums_set.contains(i - 1)) { continue; }
            int seq = 1;
            while (nums_set.contains(i + 1)) {
                seq++;
                i++;
                // nums_set.erase(i);
            }
            longest_seq = std::max(longest_seq, seq);
        }

        return longest_seq;
    }
};
