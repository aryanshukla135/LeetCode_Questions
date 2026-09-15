class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> ans ;
        vector<int> cntForvow(n) ;
        unordered_set<char> vowels = {'a','e','i','o','u'};

        int cnt =0;
        for(int i =0 ; i<n ; i++){
            string str = words[i];
            char f = str[0];
            char l = str[str.size()-1];
            if(vowels.count(f) && vowels.count(l)){
                ++cnt;
            }
            cntForvow[i] = cnt;
        }
        for(int i =0 ; i<queries.size() ; i++){
            int s = queries[i][0];
            int e = queries[i][1];
            
            int f = -1;
            if(s != 0){
                f = s-1;
            }
            if(f != -1)
            ans.push_back(cntForvow[e] - cntForvow[f]);
            else  ans.push_back(cntForvow[e]);
        }
         return ans ;
    }
};