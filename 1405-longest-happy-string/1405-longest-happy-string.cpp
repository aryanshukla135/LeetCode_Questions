class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
          priority_queue<pair<int,char>> pq ;
          if(a > 0) pq.push({a,'a'});
          if(b > 0) pq.push({b,'b'});
          if(c > 0) pq.push({c,'c'});

          string ans = "";
          while(!pq.empty()){
              auto it = pq.top();
              pq.pop();
              int val = it.first ;
              int ch = it.second ;
              int n = ans.size();
              if(n>=2 && ans[n-1] == ch && ans[n-2] == ch){
                 if(pq.empty()){
                    break;
                 }
                 auto next = pq.top();
                 pq.pop();
                 int val1 = next.first;
                 int ch1 = next.second;
                 
                 ans += ch1;
                 val1--;
                 if(val1 > 0){
                    pq.push({val1,ch1});
                 }
                  pq.push({val,ch});
              }else{
                 val--;
                 ans += ch;
                 if(val > 0){
                    pq.push({val,ch});
                 }
              }    
          }
        
          return ans ;
    }
};