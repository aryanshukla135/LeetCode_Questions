class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n,0);
        maxi[n-1] = nums[n-1];
        for(int i = n-2 ; i>=0; i--){
            maxi[i] = max(maxi[i+1] , nums[i]);
        }
        int ansmax = INT_MIN;
        
        for(int i =0 ; i< n ; i++){
            if(i+k < n ){
               ansmax = max(ansmax,nums[i]+maxi[i+k]); 
            }
        }
        return ansmax ;
    }
};