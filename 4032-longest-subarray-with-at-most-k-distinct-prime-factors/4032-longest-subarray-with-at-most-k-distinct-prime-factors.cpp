class Solution {
private:
    vector<int> factor(int x){
        vector<int>v; 
        for(int i = 2 ; i*i <=x ; i++){
            if( x % i == 0){
                v.push_back(i);
                while(x % i == 0){
                    x /= i;
                }
            }
        }
        if(x > 1) v.push_back(x);
        return v ;
    }
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int j = 0 ;
        int ans = 0;
        unordered_map<int,int> cnt ;
        int dis = 0;
        for(int i = 0 ; i<n ; i++ ){
            vector<int> tilli = factor(nums[i]);
            for(int x : tilli){
                if(cnt[x] == 0){
                    dis++;
                }
                cnt[x]++;
            }
            while(dis > k ){
                vector<int> tillj = factor(nums[j]);
                for(int x : tillj){
                    cnt[x]--;
                    if(cnt[x] == 0){
                        dis--;
                    }
                }
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return ans ;
        
    }
};