class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int ans =0;
        int temp = n/8;
        if(temp == 0){
            ans = n ;
        }
        if(temp==1){
            int rem = n-8;
            ans=8+(2*rem);
        }
        if(temp == 2){
            int rem = n-16;
            ans=8+16+(3*rem);
        }
        if(temp == 3){
            int rem = n - 24;
            ans = 8+16+24+(4*rem);
        }
        return ans ;
    }
};