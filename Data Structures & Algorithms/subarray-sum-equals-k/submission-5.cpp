class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();

        std::unordered_map<int, int> hash_map{};
        hash_map[0] = 1;

        int result = 0;

        int prefix_sum = 0;
        for (int i = 0; i < n; ++i) {
            prefix_sum += nums[i];
            if (hash_map.contains(prefix_sum - k)) {
                result += hash_map[prefix_sum - k];
            }
            hash_map[prefix_sum]++;
        }

        return result;
    }
};