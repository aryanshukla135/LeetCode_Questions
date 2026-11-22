class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1 ;
        }
        int cnt =0 ;
        for(int i =0; i<n ; i++){
            double val1 =0 ;
            double val2 =0 ;
            int m = 0 ;

            if(i>0){
                val1 = nums[i-1];
                ++m;
            }
            if(i<n-1){
                val2 = nums[i+1];
                ++m;
            }

            double avg = (val1 + val2)/m ;
            cout<<avg<<" ";
            if(nums[i] >= avg){
                cnt++;
            }
        }
        return cnt ;
    }
};