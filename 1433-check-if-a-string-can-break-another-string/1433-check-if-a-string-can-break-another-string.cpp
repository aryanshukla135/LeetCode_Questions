class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n = s1.length();
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool temp1 = true;
        bool temp2 = true;
        // for s1 >= s2
        for(int i =0 ; i<n ; i++){
            if(s1[i] < s2[i]){
                temp1 = false;
            }
        }
        //for s2 >=s1
        for(int i =0 ; i<n ; i++){
            if(s1[i] > s2[i]){
                temp2 = false;
            }
        }
        return temp1 || temp2;
    }
};