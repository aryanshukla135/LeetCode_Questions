class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
        vector<int> nums(n,1);
        for(int i =1 ; i<n ; i++){
            if(rating[i] > rating[i-1]){
                  nums[i] = nums[i-1]+1;
            }
        }
        for(int i = n-2 ; i>=0 ; i--){
            if(rating[i]>rating[i+1]){
                nums[i] = max(nums[i],nums[i+1] + 1) ;
            }
        }
        int sum =0 ;
        for(int i : nums) sum += i;
        
        return sum ;
    }
};
// 1 3 4 5 2 -> 11 
// 1 1 1 1 1
// 1 2 3 4 1
// 1 2 3  1
