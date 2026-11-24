class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;

        for(int i =0 ; i<n ; i++){
                long long prod = 1 ;
                int l = nums[i];
                int g = nums[i];
            for(int j = i ; j<n ; j++){

                if(prod > LLONG_MAX / nums[j]) break;

                prod = 1LL * prod * nums[j];
                l = lcm(l,nums[j]);
                g = gcd(g,nums[j]);
               
                if(l <= LLONG_MAX / g && prod == 1LL * l * g){
                    maxlen = max(maxlen,j-i+1);
                }
            }
        }
        return maxlen;
    }
};