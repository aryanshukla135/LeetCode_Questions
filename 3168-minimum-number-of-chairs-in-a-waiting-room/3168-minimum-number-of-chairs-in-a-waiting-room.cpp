class Solution {
public:
    int minimumChairs(string s) {
        int n = s.length();
        int chair =1 ;
        int occ =0;
        for(int i =0 ; i<n ; i++){
            if(s[i] == 'E'){
                occ++;
                if(occ>chair){
                    chair++;
                }
            }else{
                occ--;
            }
        }
        return chair;
    }
};