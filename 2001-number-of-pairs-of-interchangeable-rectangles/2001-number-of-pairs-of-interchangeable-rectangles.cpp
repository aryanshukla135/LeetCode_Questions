class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& nums) {
          int n = nums.size();

          unordered_map<double,int> mp ;
          for(int i =0 ; i<n ; i++){
             double val = (double)nums[i][0]/(double)nums[i][1];
             mp[val]++;

          }
          long long  ans = 0;
          for(int i =0 ; i<n ; i++){
             double val = (double)nums[i][0]/(double)nums[i][1];
              mp[val]--;
              if(mp[val]>0){
                ans+=mp[val];
              }
          }
          return ans;
    }
};