class Solution {
private: 
    int f(vector<int> & arr, int d , int idx,vector<int> & dp){

        if(dp[idx] != -1) return dp[idx];
        int maxi = 1;
        // aage 
        for(int i = 1 ; i<=d ; i++){
            int next = idx + i ;
            if(next >= arr.size()){
                break;
            }
            if(arr[next] >= arr[idx]){
                break;
            }
            maxi = max(maxi,1+f(arr,d,next,dp));
        }
        // piche 
        for(int i =1 ; i<=d ; i++){
            int next = idx -i ;
            if(next <0){
                break;
            }
            if(arr[next] >= arr[idx]){
                break;
            }
            maxi = max(maxi,1+f(arr,d,next,dp));
        }
        return dp[idx] = maxi;
    
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int ans = 0;
        for(int i =0 ; i< n ; i++){
            vector<int> dp(n,-1);
            ans = max(ans,f(arr,d,i,dp));
        }
        return ans;
    }
};