class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
            int currsum = 0;
            int maxsum =INT_MIN;
            int n = nums.size();
            int total=0;
            int minsum=INT_MAX;
            for(int i= 0; i< n ; i++){
                currsum=currsum+nums[i];
                maxsum=max(maxsum,currsum);
                if(currsum<0){
                    currsum=0;
                }
                total+=nums[i];
            }
            currsum=0;
             for(int i= 0; i< n ; i++){
                currsum=currsum+nums[i];
                minsum=min(minsum,currsum);
                if(currsum>0){
                    currsum=0;
                }
            }
            if(maxsum<0) return maxsum;
            return max(maxsum,total-minsum);
    }
};