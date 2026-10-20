class Solution {
public:
    int nextBeautifulNumber(int n) {
        int i = n +1 ;
        while(1){
            vector<int> mp(10,0);
            int x = i ;
            while(x > 0){
                int rem = x % 10 ;
                mp[rem]++;
                x = x / 10;
            }

            bool temp = true;
            for(int j =0 ; j<10;j++){
                if(mp[j] != 0 && mp[j] != j){
                    temp = false;
                    break;
                }
            }
            if(temp){
                return i;
            }
            i++;
        }
        return -1 ;
    }
};