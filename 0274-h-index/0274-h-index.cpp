class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cnt = 1 ;

        for(int i = n-1 ; i>=0 ; i--){
            if(nums[i] >=cnt){
                cnt++;
            } 
        }
        return cnt-1 ;
    }
};