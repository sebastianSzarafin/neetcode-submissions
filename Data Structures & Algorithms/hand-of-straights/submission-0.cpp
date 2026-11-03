class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        const int n = hand.size();
        if (n % groupSize != 0) { return false; }

        std::map<int, int> hashMap{};
        for (const int v : hand) {
            hashMap[v]++;
        }

        while (!hashMap.empty()) {
            int card = hashMap.begin()->first;
            for (int i = 1; i <= groupSize; ++i) {
                if (!hashMap.contains(card)) {
                    return false;
                }
                hashMap[card]--;
                if (!hashMap[card]) {
                    hashMap.erase(card);
                }
                card++;
            }
        }

        return true;
    }
};
