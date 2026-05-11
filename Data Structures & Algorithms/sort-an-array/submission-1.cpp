class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(std::vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }

        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }

    void merge(std::vector<int>& nums, const int l, const int m, const int r) {
        std::vector<int> tmp;
        tmp.reserve(r - l + 1);
        int i = l, j = m + 1;

        while (i <= m && j <= r) {
            if (nums[i] > nums[j]) {
                tmp.emplace_back(nums[j]);
                ++j;
            }
            else {
                tmp.emplace_back(nums[i]);
                ++i;
            }
        }
        while (i <= m) {
            tmp.emplace_back(nums[i++]);
        }
        while (j <= r) {
            tmp.emplace_back(nums[j++]);
        }

        std::copy(tmp.begin(), tmp.end(), nums.begin() + l);
    }
};