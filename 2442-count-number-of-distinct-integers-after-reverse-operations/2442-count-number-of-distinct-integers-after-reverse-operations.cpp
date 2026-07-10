class Solution {
private:
    int reverse(int digit){
        int x = digit;
        int rev =0;
        while(x>0){
            int rem = x % 10 ;
            rev = rev*10 + rem ;
            x =x/10;
        }
        return rev ;
    }
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st ;

        for(int i =0 ; i< n ; i++){
            st.insert(nums[i]);
            st.insert(reverse(nums[i]));
        }
        return st.size();
    }
};