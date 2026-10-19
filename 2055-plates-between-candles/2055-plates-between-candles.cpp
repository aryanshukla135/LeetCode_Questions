class Solution {
private:
    int first(vector<int> & pre , int s , int e ){
        while(s <= e){
            int sind = s ;
            int sval = pre[s];
            int mid = ( s + e) / 2;

            if(mid - sind == pre[mid] - pre[sind]){
                e = mid - 1 ;
            }else{
                s = mid + 1 ;
            } 
        }
        return s ;
    }

     int last(vector<int> & pre , int s , int e ){
        while(s <= e){
            int eind = s ;
            int eval = pre[s];
            int mid = ( s + e) / 2;

            if(eind - mid == pre[eind] - pre[mid]){
                e = mid - 1 ;
            }else{
                s = mid + 1 ;
            } 
        }
        return e ;
    }
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> pre(n);
        pre[0] = s[0] == '*' ? 1 : 0;

        for(int i = 1 ; i < n ; i++){
            if(s[i] == '*'){
                pre[i] = pre[i-1] + 1;
            }else{
                pre[i] = pre[i-1];
            }
        }
        vector<int> left(n,-1);
        vector<int> right(n,-1);

        for(int i =0 ; i<n ; i++){
            if(s[i] == '|'){
                left[i] = i ;
            }else{
                if(i > 0) left[i] = left[i-1];
            }
        }

        for(int i =n-1 ; i>=0 ; i--){
            if(s[i] == '|'){
                right[i] = i ;
            }else{
                if(i < n - 1) right[i] = right[i+1];
            }
        }
        // for(int i : left) cout<<i<<" ";
        // cout<<endl;
        // for(int i : right) cout<<i<<" ";
    
        int m = queries.size();
        vector<int> ans;

        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            int f = right[l];  // First candle at or after l
            int last = left[r]; // Last candle at or before r

            if (f == -1 || last == -1 || f >= last) {
                ans.push_back(0);
            } else {
                ans.push_back(pre[last] - pre[f]);
            }
        }

      return ans;
    
    }
};