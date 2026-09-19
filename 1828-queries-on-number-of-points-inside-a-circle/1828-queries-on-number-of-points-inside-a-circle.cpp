class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans ;
        int n = queries.size();
        int m = points.size();
        for(int i =0 ; i< n ; i++){
            int x = queries[i][0];
            int y = queries[i][1];
            int r = queries[i][2];
            int cnt =0 ;
            for(int j = 0 ; j< m ; j++){
                int nx = points[j][0];
                int ny = points[j][1];

                double dx = x - nx ;
                double dy = y - ny ; 
                 
                double d = sqrt(dx * dx + dy * dy);

                if(d <= r){
                    cnt++;
                }  
            }
            ans.push_back(cnt);
        }
        return ans ;
    }
};