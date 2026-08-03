class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int i =0 ;
        int j =0 ;
        int cnt =0 ;
        

        while(i<n){
        
             if(i-j+1 >=3 && nums[j] == 0){
                cnt++;
                for(int k = j ; k<=i ; k++) nums[k] = !nums[k];
                j++;
             }
             if(i-j+1 >=3 && nums[j] == 1){
                j++;
             }
             
             i++;

        }
        if(nums[n-1] ==0 || nums[n-2] == 0 || nums[n-3] == 0) return -1; 
        return cnt ;

    }
};