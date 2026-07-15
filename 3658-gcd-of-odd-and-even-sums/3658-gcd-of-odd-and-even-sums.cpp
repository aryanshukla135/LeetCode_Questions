class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumeven = n*(n+1);
        int sumodd = n*n ;

        return gcd(sumeven,sumodd);
    }
};