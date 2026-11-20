class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
          int n = s.length();
          int count =0;
          for(int i =0 ; i< n-1 ; i++){
             int val1 = s[i];
             int val2 = s[i+1];

             int diff = abs(val1-val2);
             if(diff > 2){
                return false;
             }
          }
          return true;
    }
};