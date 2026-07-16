class Solution {
public:
    string decodeMessage(string key, string message) {
         int n = key.length();
         unordered_set<char> st ;
         vector<int> idx(26,0);
         unordered_map<char,char>mp;
         int j = 0 ;
         for(int i =0 ; i< n ; i++){
            if(key[i] == ' '){
                continue ;
            }
            if(st.count(key[i])){
                continue ;
            }
            int x = key[i]-'a';
          //  cout<<x<<endl;
            idx[j++] = x;
            st.insert(key[i]);
         }
         for(int i =0 ; i<26 ; i++){
            char ch = idx[i] + 'a';
            char org = 'a' + i;
            mp[ch] = org;

         }
         string ans ="";
         for(int i =0 ; i<message.size() ; i++){
             char ch = message[i];
             if(ch == ' '){
                ans.push_back(ch);
             }else{
                ans.push_back(mp[ch]);
             }
         }

         return ans;
    }
};