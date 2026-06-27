class Solution {
public:
    int countElements(vector<int>& nums) {
        // 2 7 11 15
        //-3 3 3 90

        int n = nums.size();
        sort(nums.begin() , nums.end());
        int cnt =0;
        int mini = nums[0];
        int maxi = nums[n-1];

        for(int i =1 ; i< n-1 ; i++){
            if(nums[i]> mini && nums[i]<maxi){
                cnt++;
            }
        }
      return cnt ;
        
    }
};