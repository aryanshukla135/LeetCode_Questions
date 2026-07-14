class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumofeven = n * (n +1) ;
        int sumofodd = n * n ;

        return gcd(sumofeven, sumofodd);
    }
};