class Solution {
public:
    double gain(int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        priority_queue<pair<double, pair<int, int>>> pq;

        // Store {gain, {pass, total}}
        for (auto &c : classes) {
            int pass = c[0];
            int total = c[1];
            pq.push({gain(pass, total), {pass, total}});
        }
        while (extraStudents--) {
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first;
            int total = top.second.second;
            pass++;
            total++;
            pq.push({gain(pass, total), {pass, total}});
        }
        double sum = 0.0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first;
            int total = top.second.second;
            sum += (double)pass / total;
        }

        return sum / classes.size();
    }
};