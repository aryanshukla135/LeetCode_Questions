class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
         int n = s.length();
         vector<string> ans ;
         int i =0 ;
         int j =0 ;
         unordered_set<string> st ;
         unordered_map<string,int> mp ;

         while(i<n){
             while(i-j+1 >= 10){
                 
                if(mp.count(s.substr(j , 10))){
                    st.insert((s.substr(j , 10)));
                }else{
                    mp[(s.substr(j , 10))]++;
                }
                j++;
             } 
             i++;
             
         }
         for(string it : st){
             ans.push_back(it);
         }
         return ans ;
    }
};