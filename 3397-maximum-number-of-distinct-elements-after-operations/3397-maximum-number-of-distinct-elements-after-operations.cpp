class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int prev = INT_MIN ;
        int count =0 ;

        for(int i =0 ; i<n ; i++){
            int l = nums[i] -k;
            int h = nums[i] +k;

            int assign = max(l,prev+1);
            if(assign <= h){
                prev=assign ;
                count++;
            }
        }
        return count ;
        
        
        
    }
};
// -1 0 1 0 1 2 2 3 4 5
// -1 0 1 2 3 4 5 6 4 4 
