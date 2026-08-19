class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(),piles.end());
        int i =0 ;
        int j =n-1 ;

        int sum =0 ;
        while(i<j){
            sum += piles[j-1];
            j-=2;
            i++;

        }
        return sum ;
    }
};

// 1 2 2 4 7 8