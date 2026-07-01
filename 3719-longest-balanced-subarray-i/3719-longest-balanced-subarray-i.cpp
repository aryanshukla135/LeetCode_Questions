class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        
        int maxi =0; 

        for(int i =0 ; i< n ; i++){
             int even =0;
             int odd =0;
             unordered_map<int,int> mp;
            for(int j =i ; j<n ; j++){
                if(!mp.count(nums[j]) && nums[j] %2 ==0){
                    even++;
                }else{
                    if(!mp.count(nums[j])){
                        odd++;
                    }
                }
                mp[nums[j]]++;
                if(even == odd){
                    maxi = max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};