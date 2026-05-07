class MinStack {
private:
    std::deque<int> s{};
    int min_val = INT_MAX;

public:
    MinStack() {
        
    }

    void push(int val) {
        if (val < min_val) {
            min_val = val;
        }
        s.push_front(val);
        s.push_front(min_val);
    }
    
    void pop() {
        s.pop_front();
        s.pop_front();
        min_val = getMin();
    }
    
    int top() {
        return s.empty() ? INT_MAX : s[1];
    }
    
    int getMin() {
        return s.empty() ? INT_MAX : s[0];
    }
};
