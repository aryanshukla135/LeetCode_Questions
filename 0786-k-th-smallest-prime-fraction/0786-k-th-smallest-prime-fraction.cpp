class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<vector<float>> nums ;

        int n = arr.size();
        for(int i =0 ; i< n ; i++){
            for(int j =i+1 ; j< n ; j++){
                float f = (float)arr[i]/arr[j];
                nums.push_back({f,(float)arr[i],(float)arr[j]});
            }
        }
        sort(nums.begin() , nums.end());
        // for(int i =0 ; i< nums.size(); i++){
        //     for(int j =0 ; j<3 ; j++){
        //         cout<<nums[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<float> ans ;
        ans = nums[k-1];
        return {(int)ans[1] , (int)ans[2]};
    }
};