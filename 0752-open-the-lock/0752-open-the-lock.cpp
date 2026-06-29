class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
       
        unordered_set<string> st ;

        for(string &str: deadends){
            st.insert(str);
        }

        string str = "0123456789";
 
        if(st.count("0000")){
            return -1;
        }
        queue<pair<int,string>> q ;
        q.push({0,"0000"});
        st.insert("0000");

        while(!q.empty()){
            auto it  = q.front();
            q.pop();

            int turn = it.first ; 
            string word = it.second ;

            if(word == target){
                return turn ;
            }

            for(int i =0 ; i<4 ; i++){
               char ch = word[i];
                word[i] = (ch == '9') ? '0' : ch + 1;
                if (!st.count(word)) {
                    st.insert(word);
                    q.push({turn+1,word});
                }

                word[i] = (ch == '0') ? '9' : ch - 1;
                if (!st.count(word)) {
                    st.insert(word);
                    q.push({turn +1 , word});
                }

                word[i] = ch;
                
            }

        }
        return -1;
    }
};