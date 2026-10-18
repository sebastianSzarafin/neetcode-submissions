class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int n = nums.size();

        std::ranges::sort(nums);

        std::vector<std::vector<int>> tuples{};

        for (int i = 0; i < n; ++i) {

            if (i && nums[i - 1] == nums[i]) { continue; }
            
            for (int j = i + 1; j < n - 2; ++j) {

                if (j > i + 1 && nums[j - 1] == nums[j]) { continue; }

                const long long  sum_ij = nums[i] + nums[j];
                int k = j + 1;
                int l = n - 1;

                while (k != l) {
                    const long long sum = sum_ij + nums[k] + nums[l];    
                    if (sum > target) { 
                        l--; 
                    }
                    else if (sum < target) { 
                        k++; 
                    }
                    else {
                        tuples.emplace_back(std::vector{nums[i], nums[j], nums[k], nums[l]});
                        do {
                            l--;
                        }
                        while (k != l && nums[l] == nums[l + 1]);
                    }
                }
            }
        }

        return tuples;
    }
};