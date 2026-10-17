class Solution {
private:
    int partition(std::vector<int>& nums, const int l, const int r) {
        int& v = nums[l];
        int i = l;
        int j = r + 1;
        
        do {
            do { i++; } while (i < r && nums[i] < v);
            do { j--; } while (j > l && nums[j] > v);
            if (i < j) {
                std::swap(nums[i], nums[j]);
            }
        } while (i < j);
        std::swap(v, nums[j]);

        return j;
    }

    void quick_sort(std::vector<int>& nums, const int l, const int r) {
        int j = partition(nums, l, r);
        if (l < j - 1) { quick_sort(nums, l, j - 1); }
        if (j + 1 < r) { quick_sort(nums, j + 1, r); }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};