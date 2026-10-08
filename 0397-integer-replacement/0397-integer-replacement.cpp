class Solution {
public:
    int integerReplacement(int n) {
        queue<long long> q;
        unordered_set<long long> visited;

        q.push(n);
        visited.insert(n);

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                long long curr = q.front();
                q.pop();

                if (curr == 1)
                    return steps;

                if (curr % 2 == 0) {
                    long long next = curr / 2;

                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                } else {
                    long long a = curr - 1;
                    long long b = curr + 1;

                    if (!visited.count(a)) {
                        visited.insert(a);
                        q.push(a);
                    }

                    if (!visited.count(b)) {
                        visited.insert(b);
                        q.push(b);
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};