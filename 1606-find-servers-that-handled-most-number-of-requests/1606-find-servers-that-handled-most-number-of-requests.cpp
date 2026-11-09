class Solution {
public:
    typedef pair<int,int> P;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available ;
        priority_queue<P,vector<P>,greater<P>> busy ;
        

        for(int i =0 ; i<k ; i++){
            available.insert(i);
        }

        vector<int> countRequest(k,0);
        for(int i = 0 ; i< arrival.size() ; i++){
            int time = arrival[i];

            while(!busy.empty() && busy.top().first <= time){
                int server = busy.top().second;
                busy.pop();
                available.insert(server);
            }

            int target = i % k ;
            auto it = available.lower_bound(target);

            if(it == available.end()) {
                it = available.begin();
            }
            if(available.empty()) {
                continue; 
            }
            int targetServer = *it;
            available.erase(it);
            busy.push({time + load[i], targetServer});
            countRequest[targetServer]++;
        }

        int maxNumberOfRequests = *max_element(begin(countRequest), end(countRequest)); 
        vector<int> result;
        for(int i = 0; i < k; i++) {
            if(countRequest[i] == maxNumberOfRequests) {
                result.push_back(i);
            }
        }

        return result;

    }
};