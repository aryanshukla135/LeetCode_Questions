class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        bool one = true ;

        for(int i =0 ; i<n ; i++){
            if(nums[i] == 1){
                if(!one){
                    cnt++;
                    one = !one;
                }
            }else{
                if(one){
                    cnt++;
                    one = !one;
                }
            }
        }
        return cnt ;
    }
};