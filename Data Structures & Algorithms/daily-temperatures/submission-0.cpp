class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const auto n = temperatures.size();

        std::vector<int> result(n);

        std::stack<int> s;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                result[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }

        return result;
    }
};
