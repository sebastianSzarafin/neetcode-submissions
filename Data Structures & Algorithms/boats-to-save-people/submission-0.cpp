class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        const int n = people.size();
        
        std::ranges::sort(people);

        int boats = 0;
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                l++;
            }
            r--;
            boats++;
        }

        return boats;
    }
};