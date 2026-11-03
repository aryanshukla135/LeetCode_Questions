class Solution {
void bfs(vector<vector<int>> & graph , int node , vector<int> & nums){
    int n = nums.size();
    vector<int> vis(n);
    queue<pair<int,int>> q ;
    q.push({0,node});
    nums[node] = 0 ;
    vis[node] = 1 ;

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int step = it.first ;
        int no = it.second ;
        nums[no] = step ;

        for(auto it : graph[no]){
            if(!vis[it]){
                vis[it] = 1 ;
                q.push({step + 1 , it});
            }
        }
    }
}
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> graph(n);

        for(int i =0 ; i<n ; i++){
           if(edges[i] != -1){
              graph[i].push_back(edges[i]);
           }
        }

        vector<int> nums1(n,INT_MAX);
        vector<int> nums2(n,INT_MAX);

        bfs(graph,node1,nums1);
        bfs(graph,node2,nums2);

        int ind = -1 ;
        int mini = INT_MAX;

        for(int i =0 ; i <n ; i++){
            if(nums1[i] != INT_MAX  && nums2[i] != INT_MAX){
                int val = max(nums1[i],nums2[i]);
                if(val < mini){
                    mini = val ;
                    ind = i ;
                }
            }
        }
        return ind ;
    }
};