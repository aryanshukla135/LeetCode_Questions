class Solution {
public:
    typedef pair<int,int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,vector<P>> timeMeetings;

        for(auto it : meetings){
            int u = it[0];
            int v = it[1];
            int time = it[2];

            timeMeetings[time].push_back({u,v});
        }

        vector<bool> knowsSceret(n,false);
        knowsSceret[0] = 1 ;
        knowsSceret[firstPerson] =1 ;

        for(auto & it : timeMeetings){
            int t = it.first;
            vector<P> meets = it.second;

            unordered_map<int,vector<int>> adj ;
            unordered_set<int> alreadyAdded;
            queue<int>q;

            for(auto i : meets){
                int u = i.first;
                int v = i.second;

                adj[u].push_back(v);
                adj[v].push_back(u);

                if(knowsSceret[u] == 1 && !alreadyAdded.count(u)){
                    alreadyAdded.insert(u);
                    q.push(u);
                }

                if(knowsSceret[v] == 1 && !alreadyAdded.count(v)){
                    alreadyAdded.insert(v);
                    q.push(v);
                }
            }

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto i : adj[node]){
                    if(knowsSceret[i] == 0){
                        knowsSceret[i] = 1;
                        q.push(i);
                    }
                }
            }
        }
        vector<int> res ;
        for(int i =0 ; i<n ; i++){
            if(knowsSceret[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};