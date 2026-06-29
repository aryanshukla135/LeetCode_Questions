class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();
        unordered_set<string> st ;
        string target = "ACGT";
        for(string str: bank){
            st.insert(str);
        }
        queue<pair<int,string>> q ;
        q.push({0,startGene});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int mutation = it.first;
            string word = it.second;

            if(word == endGene){
                return mutation;
            }

            for(int i = 0 ; i<8 ; i++){
                char ch = word[i];
                for(int j =0 ; j<4 ; j++){
                    word[i] = target[j];
                    if(st.count(word)){
                        q.push({mutation+1,word});
                        st.erase(word);
                    }
                    word[i] = ch ;
                }
            }
        }
        return -1 ;
    }
};