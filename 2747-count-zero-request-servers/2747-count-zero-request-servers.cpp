class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();

        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
                return vec1[1] < vec2[1]; //sort on basis of time in ascending order
        };

        sort(begin(logs), end(logs), lambda) ; //{serverid, time} //O(mlogm)

        int q = queries.size();
        vector<int> result(q);

        vector<pair<int, int>> timeIndex(q); //{time, originalIdx} //O(q) space
        for(int i = 0; i < q; i++) {
            timeIndex[i] = {queries[i], i};
        }

        sort(begin(timeIndex), end(timeIndex)); //on the basis of time sort //O(qlogq)

        unordered_map<int, int> mp; //space : O(n)
        int i = 0;
        int j = 0;

        //We are touching each Log only two times : one by i and one by j
        //Q(q + m)
        for(auto [time, idx] : timeIndex) {
            //Range
            int start = time-x;
            int end   = time;

            //Expansion
            while(j < m && logs[j][1] <= end) {
                mp[logs[j][0]]++;
                j++;
            }

            //Shrinking
            while(i < m && logs[i][1] < start) {
                mp[logs[i][0]]--;
                if(mp[logs[i][0]] == 0) {
                    mp.erase(logs[i][0]);
                }
                i++;
            }

            result[idx] = n - mp.size(); //mp.size() = # of servers getting request in [start, end]
        }

        return result;
    }
};