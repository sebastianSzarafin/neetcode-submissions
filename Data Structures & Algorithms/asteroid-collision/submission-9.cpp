class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::stack<int> s{};
        
        for (const int right : asteroids) {
            if (s.empty()) {
                s.push(right);
                continue;
            }
            bool push_right = true;
            while (!s.empty()) {
                const int left = s.top();

                if (left > 0 && right < 0) {
                    const int v_left = std::abs(left);
                    const int v_right = std::abs(right);

                    if (v_left == v_right) {
                        s.pop();
                        push_right = false;
                        break;
                    }
                    if (v_left < v_right) {
                        s.pop();
                    }
                    else {
                        push_right = false;
                        break;
                    }
                }
                else {
                    break;
                }
            }
            if (push_right) {
                s.push(right);
            }

            // if (const int b = s.top(); b * a > 0 || (a > 0 && b < 0)) {
            //     s.push(a);
            // }
            // else {
            //     bool push_a = true;
            //     while (!s.empty()) {
            //         const int b = s.top();
            //
            //         const int vel_a = std::abs(a);
            //         const int vel_b = std::abs(b);
            //
            //         if (vel_b == vel_a) {
            //             push_a = false;
            //             s.pop();
            //             break;
            //         }
            //         if (vel_b < vel_a) {
            //             s.pop();
            //         }
            //         if (vel_b > vel_a) {
            //             push_a = false;
            //             break;
            //         }
            //     }
            //     if (push_a) {
            //         s.push(a);
            //     }
            //     // while (!s.empty() && std::abs(b) < std::abs(a)) {
            //     //     s.pop();
            //     //     b = s.top();
            //     // }
            //     // s.push(a);
            // }
        }

        std::vector<int> result{};
        
        while(!s.empty()) {
            result.emplace_back(s.top());
            s.pop();
        }
        std::ranges::reverse(result);

        return result;
    }
};