class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;

        for(int i =0 ; i<n ; i++){
            long long  l = 1 ;
            for(int j = i ; j<n ; j++){
                l = lcm(l, 1LL*nums[j]);
                
                if(l == k ){
                    cnt++;
                }
                if(l>k ){
                    break;
                }
            }
        }
        return cnt;
    }
};