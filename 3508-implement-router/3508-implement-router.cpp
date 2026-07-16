class Router {
public:
    queue<vector<int>>q ;
    set<vector<int>> st ;
    int limit = 0 ;

    unordered_map<int,vector<int>> mp ;
    unordered_map<int,int> strtidx ;

    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
         if(!st.count({source,destination,timestamp})){
            if(q.size() == limit){
               auto it = q.front();
               st.erase(q.front());
               q.pop();
               strtidx[it[1]]++;
            }
            st.insert({source,destination,timestamp});
            q.push({source,destination,timestamp});
            mp[destination].push_back(timestamp);
            return true;
         }
            return false;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()){
            return {} ;
        }
        vector<int> ans = q.front();
        q.pop();
        st.erase(ans);
        strtidx[ans[1]]++;
        return ans ;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(!mp.count(destination)){
            return 0;
        }

        vector<int>& v = mp[destination];
        int idx = strtidx[destination];

        auto l = lower_bound(v.begin() + idx, v.end(), startTime);
        auto r = upper_bound(v.begin() + idx, v.end(), endTime);

        return r-l;
       
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */