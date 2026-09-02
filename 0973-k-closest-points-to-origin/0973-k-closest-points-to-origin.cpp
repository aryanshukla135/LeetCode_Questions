class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n  = points.size();
    priority_queue<
                pair<int, pair<int, int>>,
                vector<pair<int, pair<int, int>>>,
                greater<pair<int, pair<int, int>>>> pq;

        for(int i =0 ; i<n ; i++){
            int x = points[i][0];
            int y = points[i][1];
            int num = (x*x) + (y*y);
           
            pq.push({num,{x,y}});
        }
        vector<vector<int>> ans ;
        int cnt = 0;
        while(cnt != k){
            auto it = pq.top();
            pq.pop();
            ans.push_back({it.second.first,it.second.second});
            cnt++; 
        }
         return ans;
    }
};