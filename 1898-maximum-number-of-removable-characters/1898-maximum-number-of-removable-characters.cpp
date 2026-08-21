class Solution {
private:
    bool ispossible(string &s,string&p,vector<int>& removable ,int mid){
         int slen= s.length();
         int plen= p.length();
         string str = s;
         for(int i =0 ; i<mid ; i++){
            int idx = removable[i];
            str[idx] = '#';
         }
         int i =0 ;
         int j = 0 ;
         int strlen = str.length();
         while(i<strlen && j<plen){
             if(str[i] == p[j]){
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
        return ans ;
    }
};