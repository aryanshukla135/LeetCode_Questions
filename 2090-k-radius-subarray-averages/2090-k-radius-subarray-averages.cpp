class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        if(k>=n/2 +1){
            return ans ;
        }
        int totalelem = 2*k +1;
        int j =0 ;
        long long cursum = 0;
        for(int i =0 ; i<n ; i++){
            cursum += nums[i];
            if(i-j+1 == totalelem){
                int idx = (i+j)/2;
                long long avg = cursum/totalelem;
                ans[idx] = avg;
                cursum -= nums[j];
                j++;
            }
        }
        return ans ;

    }
};