class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int n = milestones.size();
        long long total = 0;
        long long mx = 0;

        for (int x : milestones) {
            total += x;
            mx = max(mx, (long long)x);
        }

        long long rest = total - mx;

        return min(total, 2 * rest + 1);

    }
};

