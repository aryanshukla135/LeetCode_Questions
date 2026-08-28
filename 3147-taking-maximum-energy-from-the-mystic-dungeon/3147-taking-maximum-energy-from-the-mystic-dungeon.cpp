class Solution {
private:
    int solve(vector<int> & energy , int ind , int k,vector<int> & dp){
        int n = energy.size();

        if(ind >= n ) return 0;

        if(dp[ind] != INT_MIN) return dp[ind];

        int take = 0;

        if(ind  < n){
          take = energy[ind] + solve(energy,ind + k ,k,dp);
        }
         
        return dp[ind] =take ;
    }
public:
    int maximumEnergy(vector<int>& energy, int k) {
    
        int maxi = INT_MIN;
        int n = energy.size();
        vector<int> dp(n,INT_MIN);
        for(int i =0 ; i<energy.size() ; i++){
            int temp = solve(energy,i,k,dp) ;
            maxi = max(maxi,temp);
        }
        return maxi ;
    }
};
//5 7 -3 -8 -7
//-2 -5 -6