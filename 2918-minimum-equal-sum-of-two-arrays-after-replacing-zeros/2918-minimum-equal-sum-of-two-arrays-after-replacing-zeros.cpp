class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        long long  num1sum = 0;
        long long  num2sum = 0 ;
        long long  num1zero = 0 ;
        long long  num2zero = 0 ;

        for(int i =0 ;i<n ; i++){
            if(nums1[i] == 0){
                num1zero++;
            }
            num1sum +=nums1[i];
        }

        for(int i =0 ;i<m ; i++){
            if(nums2[i] == 0){
                num2zero++;
            }
            num2sum +=nums2[i];
        }
        

        long long min1 = num1sum + num1zero;
        long long min2 = num2sum + num2zero;

        if (min1 == min2)
            return min1;

        if (min1 > min2) {
            if (num2zero == 0)
                return -1;
            return min1;
        }

        if (num1zero == 0)
            return -1;

        return min2;
        
    }
};