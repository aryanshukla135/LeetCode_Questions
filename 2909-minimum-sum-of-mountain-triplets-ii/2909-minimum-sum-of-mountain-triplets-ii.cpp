class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> frontmin(n);
        vector<int> lastmin(n);

        frontmin[0] = nums[0];
        lastmin[n-1] = nums[n-1];

        for(int i =1 ; i<n ; i++){
            frontmin[i] = min(frontmin[i-1],nums[i]);
        }

        for(int i = n-2 ; i>=0 ; i--){
            lastmin[i] = min(lastmin[i+1],nums[i]);
        }

        int ans =INT_MAX ;
        for(int i =1 ;i<n-1 ; i++){
            if(lastmin[i] == nums[i] || frontmin[i] == nums[i]){
                continue ;
            }
            ans = min(ans,lastmin[i] + frontmin[i] + nums[i]);
        }
        if(ans == INT_MAX){
            return -1; 
        }
        return ans ;

    }
};
// 5 4 8 7 10 2 
// 5 4 4 4 4  2
// 2 2 2 2 2  2 