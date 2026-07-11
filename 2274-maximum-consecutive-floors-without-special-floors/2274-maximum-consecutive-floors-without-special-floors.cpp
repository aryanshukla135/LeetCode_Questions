class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
         int n = special.size();
         sort(special.begin(),special.end());

         int ans = INT_MIN ;
         int first = special[0];
         int last = special[n-1];

         ans = max(ans,first-bottom);
         ans = max(ans,top-last);

         for(int i = 0 ; i<n-1 ; i++){
             ans = max(ans,special[i+1] - special[i]-1);
         }
         return ans ;
    }
};