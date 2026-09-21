class Solution {
const int mod = 1e9 + 7 ;
private:
    int reverse(int n ){
        int rev =0 ;
        while(n!=0){
            int rem = n % 10 ;
            rev = rev * 10 + rem ;
            n = n/10 ;
        }
        return rev ;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp ;
    
        for(int i =0 ; i<n ; i++){
             int val = reverse(nums[i]);
             nums[i] = nums[i] - val ;
        }
        for(int i =0 ; i<n ; i++){
            mp[nums[i]]++;
        }
        int ans =0 ;
        for(int i =0 ; i<n ; i++){
            int val = nums[i];
            mp[val]--;
            if(mp[val] >0){
                ans = (ans + mp[val] ) % mod;
            }
        }
        return ans % mod  ;
    }
};