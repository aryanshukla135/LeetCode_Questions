class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
          int n = series1.size();
          int m = series2.size();
         unordered_map<int,int> s1 ;
         unordered_map<int,int> s2 ;
    

        for(int i =0 ; i<n ; i++){
            s1[series1[i][0]]= series1[i][1];
            
        }
       for(int i =0 ; i<m ; i++){
            s2[series2[i][0]] = series2[i][1];
         
        }
    
        vector<vector<int>> result ;

        int j =0 ;
        for(int i =0 ; i<n ; i++){
            int val = series1[i][0];
            if(s2.count(val)){
                result.push_back({val,series1[i][1] + s2[val]});
            }else{
                while(j<m && series2[j][0] <= val ){
                    j++;
                }
                if(j<m){
                    result.push_back({val,series1[i][1] + series2[j][1]});
                }else{
                    result.push_back({val,series1[i][1] + 0}); 
                }
            }
        }
        j =0;
        for(int i =0 ; i<m ; i++){
            int val = series2[i][0];
            if(s1.count(val)){
                continue;
            }else{
                while(j<n && series1[j][0] <= val ){
                    j++;
                }
                if(j<n){
                    result.push_back({val,series2[i][1] + series1[j][1]});
                }else{
                    result.push_back({val,series2[i][1] + 0}); 
                }
            }
        }
      sort(result.begin(),result.end());
       return result ;
       

    }
};