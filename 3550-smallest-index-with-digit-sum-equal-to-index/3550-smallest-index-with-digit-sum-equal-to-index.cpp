class Solution {
private:
    int sumOfDigit(int num){
        int sum  =0 ;
        while(num >0){
            int rem = num % 10 ;
            sum += rem ;
            num /= 10;
        }
        return sum ;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for(int i =0 ; i<n ; i++){
            int sum = sumOfDigit(nums[i]);
            if(sum == i){
                ans = i ;
                break;
            }
        }
        return ans ;
    }
};