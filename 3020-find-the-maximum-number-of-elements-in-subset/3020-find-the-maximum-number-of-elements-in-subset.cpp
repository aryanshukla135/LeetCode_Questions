class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long ,int> mp ;

        for(int num : nums){
            mp[num]++;
        }
        int result =0;

        if(mp[1]%2==0){
            result = mp[1]-1;
        }else{
            result = mp[1];
        }

        for(auto i: mp ){
            long long num = i.first;

            if(num == 1){
                continue ;
            }
            long long curr = num ;
            int len =0;
            while(mp.count(curr) && mp[curr]>1){
                len +=2;
                curr = curr*curr;
            }
            if(mp.count(curr) == 1){
                len+=1;
            }else{
                len-=1;
            }

            result = max(len,result);

        }
        return result;
    }
};