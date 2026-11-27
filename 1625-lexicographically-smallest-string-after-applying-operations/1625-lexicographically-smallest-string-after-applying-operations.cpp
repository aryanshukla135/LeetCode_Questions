class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.length();
        string ans = s;

        queue<string> q ;
        unordered_set<string> st;

        st.insert(s);
        q.push(s);

        while(!q.empty()){
            auto str = q.front();
            q.pop();
           
            ans = min(ans,str);

            string s1 = str ;
            rotate(s1.begin(), s1.end() - b, s1.end());
            if(!st.count(s1)){
               q.push(s1);
               st.insert(s1);
            }
            string s2 = str ;
            for(int i = 0 ; i < n ; i++){
                if(i % 2 != 0){
                    char ch = s2[i];
                    int val = ch - '0';
                    int temp = (val + a) % 10 ;
                    s2[i] = (temp + '0') ;
                }
            }
            if(!st.count(s2)){
                q.push(s2);
                st.insert(s2);
            }
        }
        return ans ;
    }
};