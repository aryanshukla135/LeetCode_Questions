class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int j =0 ;
        unordered_map<int,int> mp ;
        int minlength = INT_MAX;

        for(int i =0 ; i<n ; i++){
            
            if(mp.count(cards[i])){
                j = mp[cards[i]];
                minlength = min(minlength,i-j+1);
                mp[cards[i]] = i ;
            }
            else{
                mp[cards[i]] = i ;
            }
        }
        if(minlength == INT_MAX) return -1 ;
        return minlength ;
    }
};