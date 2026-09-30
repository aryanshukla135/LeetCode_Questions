class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans ;
        sort(intervals.begin(),intervals.end());
        int prevS = intervals[0][0];
        int prevE = intervals[0][1];

        for(int i = 1 ; i<n ; i++){
            int currS = intervals[i][0];
            int currE = intervals[i][1];

            if(prevE >= currS){
                prevE = max(prevE,currE);
            }else{
                ans.push_back({prevS,prevE});
                prevS = currS ;
                prevE = currE ; 
            }
        }
        ans.push_back({prevS,prevE});
        return ans ;
    }
};