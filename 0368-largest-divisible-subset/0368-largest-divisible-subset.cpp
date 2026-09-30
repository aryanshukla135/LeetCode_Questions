class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
         int n = nums.size();
         vector<int> dp(n,1) , hash(n);
         sort(nums.begin(),nums.end());
         for(int i =0 ; i<n ; i++){
            hash[i] = i ;
         }
         int maxi = 0;

         for(int i =0 ; i<n ; i++){
            for(int prev = 0 ; prev < i ; prev++){
                if(nums[i] % nums[prev] == 0 && dp[i] < 1 + dp[prev]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev ;
                }
            }
            if(dp[i] > dp[maxi]){
                maxi = i ;
            }
         }
         vector<int> temp ;
         temp.push_back(nums[maxi]);
         
         while(hash[maxi] != maxi){
            maxi = hash[maxi];
            temp.push_back(nums[maxi]);
         }
         return temp ;

    }
};