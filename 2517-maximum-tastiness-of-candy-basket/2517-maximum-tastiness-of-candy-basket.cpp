class Solution {
private:
   int countcandi(vector<int>& price ,int mid ){
       int n = price.size();
       int cnt = 1 ;
       int prev = price[0];
       for(int i =1 ; i<n ; i++){
          int val = price[i] - prev ;
          if(val >= mid){
             cnt++;
             prev = price[i];
          }
       }
       return cnt ;
   }
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n = price.size();
        int l = 0 ;
        int h = price[n-1] - price[0];
        int ans = 0;
        while(l<=h){
            int mid = l + (h-l)/2 ;

            int candiescnt = countcandi(price,mid);

            if(candiescnt >= k){
                ans = mid ;
                l = mid +1;
            }else{
                h = mid -1 ;
            }
        }

        return ans ;

    }
};