class Solution {
public:
    int minFlips(string target) {
        int ans =0; 
        bool zero = true ;
        int n = target.size();
        for(int i =0 ; i<n ; i++){
            if(target[i] == '0'){
                if(!zero){
                    ans++;
                    zero = !zero ;
                }
            }else{
                if(zero){
                    ans++;
                    zero  = !zero ;
                }
            }
        }
        return ans ;
    }
};