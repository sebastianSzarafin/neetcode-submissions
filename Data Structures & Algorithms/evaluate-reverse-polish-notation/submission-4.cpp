class Solution {
private: 
    std::function<int(int, int)> getOp(char token) {
        switch (token) {
            case '+': return std::plus<int>();
            case '-': return std::minus<int>();
            case '*': return std::multiplies<int>();
            case '/': return std::divides<int>();
            default: throw;
        }
    }

public:
    int evalRPN(vector<string>& tokens) {

        std::stack<int> s{};

        for (int i = 0; i < tokens.size(); ++i) {
            const auto t = tokens[i];
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                const int b = s.top();
                s.pop();
                const int a = s.top();
                s.pop();
                auto op = getOp(t[0]);
                s.push(op(a, b));
            }
            else {
                s.push(std::stoi(t));
            }
        }

        return s.top();
    }
};
