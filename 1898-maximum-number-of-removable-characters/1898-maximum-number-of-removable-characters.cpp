class Solution {
private:
    bool ispossible(string &s,string&p,vector<int>& removable ,int mid){
         int slen= s.length();
         int plen= p.length();
         vector<bool>vis(slen,0);
       
         for(int i =0 ; i<mid ; i++){
            int idx = removable[i];
            vis[idx] = 1;
         }
         int i =0 ;
         int j = 0 ;
       
         while(i<slen && j<plen){
             if(s[i] == p[j] && vis[i] == 0){
                j++;
             }
             i++;
         }
         return j == plen;

    }
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = removable.size();
        int l = 0;
        int h = n;
        int ans = -1;

        while(l<=h){
            int mid = (l+h)/2;
            if(ispossible(s,p,removable,mid)){
                ans = mid ;
                l = mid + 1;
            }else{
                h = mid -1;
            }
        }
        if(ans == -1) return 0 ;
        return ans ;
    }
};