class Solution {
private:
    long long  reqcandies(vector<int> & candies , long long k ,long long mid ){
        int n = candies.size();
        long long totalcand = 0 ;

        for(int i =0 ; i<n ; i++){
            if(candies[i] >= mid){
                long long req = candies[i]/mid;
                totalcand += req;

                if(totalcand >= k){
                    return totalcand;
                } 
            }
        }
        return totalcand;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long l = 1 ;
        long long  h = *max_element(candies.begin(),candies.end());
        long long  ans = 0;
        while(l<=h){
            long long  mid = l+(h-l)/2;
            long long  maxcandie = reqcandies(candies,k,mid);

            if(maxcandie >= k){
                ans = mid ;
                l = mid+1;
            }else{
                h = mid -1 ;
            }
        }
        return ans ;
    }
};