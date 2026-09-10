class Solution {
private:
    int solve(int n ){
        if(n<=1){
            return 1;
        }
        int cnt = 0;
         
        for(int i =0 ; i<n ;i++){
            cnt += solve(i) * solve(n-i-1);
        }
        return cnt ;
    }

public:
    int numTrees(int n) {
        return solve(n);
    }
};