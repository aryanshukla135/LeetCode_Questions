class Solution {
private:
    int lsearch(vector<int> & nums ,int val){
        int n = nums.size();
        for(int i = 0 ;i< n ; i++){
            if(nums[i] == val){
                return i ;
            }
        }
        return -1;
    }
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());

        int maxiPos = lsearch(nums, maxi);
        int miniPos = lsearch(nums, mini);

        int maxiidx = maxiPos + 1;
        int miniidx = miniPos + 1;

        int maxiidxback = n - maxiPos;
        int miniidxback = n - miniPos;

        int bothFront = max(maxiidx, miniidx);

        int bothBack = max(maxiidxback, miniidxback);

     
        int maxFrontMinBack = maxiidx + miniidxback;

      
        int minFrontMaxBack = miniidx + maxiidxback;

        return min({
            bothFront,
            bothBack,
            maxFrontMinBack,
            minFrontMaxBack
        });

    }
};