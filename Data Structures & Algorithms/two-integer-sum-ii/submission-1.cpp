class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        const int n = numbers.size();

        int l = 0;
        int r = n - 1;

        int sum = numbers[l] + numbers[r];

        while (sum != target) {
            if (sum > target) {
                r--;
            }
            else {
                l++;
            }
            sum = numbers[l] + numbers[r];
        }

        return {l + 1, r + 1};
    }
};
