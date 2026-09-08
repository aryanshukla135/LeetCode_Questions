class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size();
        int s = 0 ;
        int e = n-1;
        int ans = 0;
        while(s<=e){
            int mid = (s+e)/2;
            int val = n-mid ;
            if(nums[mid] >= val){
                ans = val ;
                e = mid -1 ;

            }else{
                s = mid+1;
            }
        }
        return ans ;
    }
};