class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
         int n = s.length();
         vector<int> ans(n,0);
         stack<int> st ;
         for(int i =0 ;i<n ; i++){
            if(s[i] == '('){
                st.push(i);
                if(st.size() % 2 == 0){
                    ans[i] = 1;
                }
            }else{
                st.pop();
                if(st.size() % 2 == 1){
                    ans[i] =1;
                }

            }

         }
         return ans ;
    }
};