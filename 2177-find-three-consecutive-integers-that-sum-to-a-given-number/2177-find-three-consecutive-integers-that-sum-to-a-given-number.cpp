class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num % 3 != 0){
            return {};
        }
        long long val2 = num /3 ;
        long long val1 = val2 -1 ;
        long long val3 = val2 +1 ;

        return {val1,val2,val3};
    }
};
// 1 2 3 = 6
// 2 3 4 = 9
// 3 4 5 = 12
// 4 5 6 = 15
// 5 6 7 = 18
// 6 7 8 = 21
// 7 8 9 = 24
// 8 9 10 =27
// 9 10 11 =30
// 10 11 12 = 33
// 11 12 13 = 36
