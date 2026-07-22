class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result ;
        vector<int> negative(51,0);
        int i =0 ;
        int j =0 ;
        while(i<n){
            
            if(nums[i] < 0){
                int idx = -1 * nums[i];
                negative[idx]++;
            }
            if(i-j+1 == k){
                int temp =0 ;
                int val = 0 ;
                for(int k =50 ; k>=1 ; k--){
                    temp+=negative[k];
                    if(temp >= x){
                        val = -1*k;
                        break ;
                    }
                }
                result.push_back(val);
                
                if (nums[j] < 0) {
                    negative[-nums[j]]--;
                }

                j++;
            }
                i++;
        }
        return result ;
    }
};