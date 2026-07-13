class Solution {
public:
    int largestPrime(int n) {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    prime[j] = false;
            }
        }

        vector<int> nums;

        for (int i = 2; i <= n; i++) {
            if (prime[i])
                nums.push_back(i);
        }
        unordered_map<int,int> mp ;
        for(int i =0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        int sum =0 ;
        int ans =0;

        for(int i =0 ;i<nums.size(); i++){
            sum +=nums[i];
            if(sum>n){
                break ;
            }else{
               if(mp.count(sum)){
                  ans = sum ;
               }
            }
        }
        return ans ;
    }
};

//2 3 5 7 11 13 17 19 