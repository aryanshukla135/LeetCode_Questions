class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
         int n = arr.size();
         unordered_map<int,int> mp ;

         for(int num : arr){
            int val = (num % k + k) % k; 
            mp[val]++;
         }

         if(mp[0] %2 != 0 ){
            return false;
         }

         for(int i =1 ; i<=k/2 ; i++){
            int counter = k-i;
            if(mp[counter] != mp[i] ){
                return false;
            }
         }
         return true ;
    }
};