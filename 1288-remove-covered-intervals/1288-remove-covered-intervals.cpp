class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
         int n = intervals.size();
         sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
                                        return a[1] < b[1];
                                    });
         int cnt =0;
         for(int i =0 ; i< n ; i++){
            int prev1 = intervals[i][0];
            int prev2 = intervals[i][1];
            for(int j = 0 ; j< n ; j++){
                if(j == i){
                    continue ;
                }
                int curr1 = intervals[j][0];
                int curr2 = intervals[j][1];
                if(curr1<=prev1 && curr2>=prev2){
                    cnt++;
                    break;
                }

            }
         }
         return n-cnt ;
    }
};




