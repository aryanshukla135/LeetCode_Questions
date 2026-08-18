class Solution {
private:
    int opreq(vector<int> & nums , int mid , int maxOperations){
        int n = nums.size();
        long long  op =0 ;
        for(int i =0 ; i<n ; i++){
            if(nums[i] > mid){
                long long  div = nums[i]/mid;
                div--;
                if(nums[i]%mid != 0){
                    div++;
                }
                op += div ;
                if (op > maxOperations)
                return op;
            }
        }
        return op;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int ans =0 ;
        int l =1 ;
        int h = *max_element(nums.begin(),nums.end());

        while(l<=h){
            int mid = l+(h-l)/2 ;

            int totalop = opreq(nums,mid,maxOperations);
            if(totalop <= maxOperations){
                ans = mid ;
                h = mid -1 ;

            }else{
                l = mid +1;
            }
        }
        return ans ;
    }
};