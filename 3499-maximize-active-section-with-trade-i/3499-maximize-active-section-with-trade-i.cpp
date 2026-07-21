class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        vector<int> zerocnt ;
        int activecnt = count(s.begin() , s.end() , '1');

        int i =0 ;
        while(i<n){
            if(s[i] == '0'){
                int start = i ;
                while(i<n && s[i] == '0'){
                    i++;
                }
                zerocnt.push_back(i-start);
            }else{
               i++;
            }
        }
        int maxpair =0 ;
        for(int i =1 ; i<zerocnt.size() ; i++){
            maxpair = max(maxpair, zerocnt[i] + zerocnt[i-1]);
        }
        return activecnt + maxpair ;
    }
};