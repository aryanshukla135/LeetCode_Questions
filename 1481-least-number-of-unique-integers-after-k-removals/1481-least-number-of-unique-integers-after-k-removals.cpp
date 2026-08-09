class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp ;
        for(int i : arr){
            mp[i]++;
        }
        //{cnt,val}
        vector<pair<int,int>> nums;
        for(auto i : mp ){
            nums.push_back({i.second,i.first});
        }
        sort(nums.begin(),nums.end());
        for(int i =0 ; i<nums.size(); i++){
            int removal = nums[i].first;
            int val = removal - k;
            if(val>0){
                k =0 ;
                nums[i].first -= k ;
            }else if(val == 0){
                nums[i].first = 0 ;
                k =0 ;
            }
            else{
                nums[i].first = 0 ;
                k = k-removal;
            }
            if(k == 0) break;

        }
        int cnt =0 ;
        for(int i =0 ; i<nums.size() ; i++){
            if(nums[i].first >0){
                cnt++;
            }
        }
        return cnt ;
    }
};