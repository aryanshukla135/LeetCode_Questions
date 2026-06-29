class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int m = word.size();
        unordered_map<string,int> mp;
        int cnt =0;

        for(int i =0 ; i< m ; i++){
            string wor= "";
            for(int j = i ; j< m ; j++){
                   wor +=word[j];
                   mp[wor]++;
            }
        }
        for(string str : patterns){
            if(mp.count(str)){
                cnt++;
            }
        }
        return cnt ;
    }
};