class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        long long maxfactorscore = INT_MIN;
        

       sort(nums.begin(),nums.end());
        
        for(int i =0 ; i< n ; i++){
            long long l = 1 ;
            long long g = 0;
            for(int j = 0; j<n ; j++){
                if(j!=i){
                l = lcm(l,nums[j]);
                g = gcd(g,nums[j]);
                }
            }
        maxfactorscore = max(maxfactorscore,l*g);
        
        }
        long long l = 1 ;
        long long g = 0;
            for(int i =0 ; i< n ; i++){
                l = lcm(l,nums[i]);
                g = gcd(g,nums[i]);
                
            }

        maxfactorscore = max(maxfactorscore,l*g);
        
        return maxfactorscore;
    }
};

