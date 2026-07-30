class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
         int n = nums.size();
         int m = l.size();
         vector<bool> ans ;

         for(int i =0 ; i<m ; i++){
            vector<int> arr ;
            int strt = l[i];
            int end = r[i];

            for(int j = strt ; j <=end ; j++){
                 arr.push_back(nums[j]);
            }
            sort(arr.begin(),arr.end());

            int diff = arr[1]-arr[0];
            bool temp = true ;
            for(int k = 1 ; k<arr.size()-1; k++){
                    if(arr[k+1]-arr[k] != diff){
                        temp = false;
                        break;
                    }
            }
            ans.push_back(temp);
         }
         return ans ;
    }
};