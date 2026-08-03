class Solution {
private:
    bool ispossible(vector<int> & nums , int threshold , int mid ){
        int n = nums.size();
        long long sum = 0;

        for(int i = 0 ; i<n ; i++){
            int val =(nums[i] + mid -1)/mid;
            sum += val;
        }
        return sum <= threshold ;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // binary search on answers 
        int n = nums.size();
        int ans = -1 ;

        int s = 1 ;
        int e = *max_element(nums.begin(),nums.end());

        while(s<=e){
            int mid = s+ (e-s)/2 ;

            if(ispossible(nums,threshold,mid)){
                ans = mid ;
                e = mid -1 ;

            }else{
                s = mid +1 ;
            }
        }
        return ans ;

    }
};