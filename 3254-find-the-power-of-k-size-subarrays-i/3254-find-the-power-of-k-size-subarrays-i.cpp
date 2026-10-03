class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int j =0 ;
        vector<int> result;

        for(int i =0 ; i<n ; i++){
            if(i-j+1 == k){
                int l = j+1 ;
                int val = nums[j];
                bool temp = true;
                while(l<=i){
                    if(val > nums[l]){
                        temp = false;
                        break;
                    }
                    if(val + 1 != nums[l]){
                        temp = false;
                        break;
                    }
                    val = nums[l];
                    l++;
                }
                if(temp){
                    result.push_back(nums[i]);
                }else{
                    result.push_back(-1);
                }
               j++;
            }
        }
        return result;

    }
};