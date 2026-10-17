class Solution {
private:
    struct PosVel {
        int pos;
        int vel;
    };

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int n = position.size();
        
        std::vector<PosVel> pos_vel(n);

        for (int i = 0; i < n; ++i) {
            pos_vel[i] = {position[i], speed[i]};
        }
        std::ranges::sort(pos_vel, std::greater{}, [](const auto& pv) { return pv.pos; });

        std::stack<double> s{};

        for (const auto& pv : pos_vel) {
            const double t = (target - pv.pos) / static_cast<double>(pv.vel);

            if (s.empty()) {
                s.push(t);
            }
            else {
                if (t > s.top()) {
                    s.push(t);
                }
            }
        }

        return s.size();
    }
};
