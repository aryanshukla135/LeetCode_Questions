class Solution {
private:
    int findDigitForSum(int n ){
        int ans = 0;
        while(n>0){
            int rem = n %10;
            ans += rem ;
            n = n/10;
        }
        return ans ;
    }
    int findDigitForProd(int n){
        int ans = 1 ;
        while(n>0){
            int rem = n % 10;
            ans *= rem ;
            n = n/10;
        }
        return ans ;
    }
public:
    bool checkDivisibility(int n) {
         int sumofdig = findDigitForSum(n);
         int prodofdig = findDigitForProd(n);

         int total = sumofdig + prodofdig;
         return n % total == 0;
    }
};