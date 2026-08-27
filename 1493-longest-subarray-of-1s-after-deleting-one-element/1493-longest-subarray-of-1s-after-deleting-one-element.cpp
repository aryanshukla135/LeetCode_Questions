class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zerocnt = 0;
        int onecnt = 0 ;

        int j =0 ;
        int maxlen = 0;
        for(int i =0 ; i<n ; i++){
            if(nums[i] == 0){
                zerocnt++;
            }
            while(zerocnt > 1){
                if(nums[j] == 0){
                    zerocnt--;
                }
                j++;
            }
            maxlen = max(maxlen,i-j);
        }
        return maxlen;
    }
};