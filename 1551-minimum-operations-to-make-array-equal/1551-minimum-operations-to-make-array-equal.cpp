class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        int val = 1 ;
        int i = 1 ;
        while(val<=n){
            ans += (n-val);
            val = (2*i)+1;
            i++;
        }
        return ans ;
    }
};
// 1 