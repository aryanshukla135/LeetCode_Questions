class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int cnt =0 ;
        for(int i =0 ; i<n ; i++){
            int mini = INT_MAX ;
            int a = INT_MAX ;
            for(int j = i ; j<n ; j++){
                mini = min(nums[j],mini);
                a = a & nums[j];
                if(a==mini){
                    cnt++;
                }
            }
        }
        return cnt ;
    }
};