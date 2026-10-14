class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if(num * 9 < sum){
            return ans;
        }
        for(int i = 0 ; i<num ; i++){
            if(sum > 9){
                ans += '9';
                sum -= 9 ;
            }else if(sum > 0 ){
                ans += (sum + '0');
                sum = 0;
            }else{
                ans += '0';
            }
        }
        return ans;
    }
};