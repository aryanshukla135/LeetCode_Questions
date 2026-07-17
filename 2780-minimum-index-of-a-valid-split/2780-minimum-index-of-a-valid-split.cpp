class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp ;

        for(int i =0 ; i< n ; i++){
            mp[nums[i]]++;
        }
        int maxelement = -1 ;
        int maxelementcount = -1 ;

        for(auto &it : mp){
            if(it.second > maxelementcount){
                maxelement = it.first ;
                maxelementcount = it.second ;
            }
        }

        int count =0 ;
        int idx = -1 ;
        for(int i =0 ; i< n ; i++){
            if(nums[i] == maxelement){
                count++;
            }
            int len = i+1 ;
            int limit = len /2 +1 ;

            if(count == limit){
                idx = i ;
                break ;
            }
        }
        
        maxelementcount -= count ;
        int remelement = n-idx-1 ;
        if(maxelementcount < remelement/2 +1){
            return -1 ;
        }
        

       return idx; 
    }
};