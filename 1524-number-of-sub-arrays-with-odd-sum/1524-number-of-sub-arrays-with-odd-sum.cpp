class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        for(int i = 1 ; i<n ; i++){
            arr[i] += arr[i-1];
        }

        int ans = 0 ;
        int o =0 ;
        int e =0 ;
        const int mod = 1e9 + 7 ;

        for(int i = 0 ; i<n ; i++){
            if(arr[i]&1){
                ans = (ans + 1 + e) % mod;
                o++;
            }else{
                ans = (ans + o) % mod;
                e++;
            }
        }
        return ans;
    }
};
// odd + odd = even 
// even + odd = odd
// even + even = even