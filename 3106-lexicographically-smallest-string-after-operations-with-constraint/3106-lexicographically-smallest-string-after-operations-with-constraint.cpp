class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.length();
        int cnt =0 ;

        if(k == 0){
            return s ;
        }
         string str ="" ;
        for(int i =0 ; i<n ; i++){
             char ch = s[i];
             int x = 'z' - ch +1 ;
             int y = ch - 'a';

             int num = min(x,y);
             cnt += num;
             if(cnt <= k){
                str.push_back('a');
             }else{
                 break ;
             }
             
        }
        int rem = 0 ;
        for(int i =0 ; i< str.length() ; i++){
            char ch = s[i] ;
            int x = 'z' - ch +1 ;
            int y = ch - 'a' ;

            rem += min(x,y);
        }
         rem = k- rem ;
        int i = str.length();
        if(rem != 0){
           int left = s[i] - 'a' ;
           if(left > rem ){
              str.push_back(s[i] - rem);
           }else{
              str.push_back('a');
           }
           i++;

           while(i<n){
             str.push_back(s[i]);
             i++;
           }

        }else{
           while(i<n){
            str.push_back(s[i]);
            i++;
           }
        }
        if(str.length() > n ){
            str.pop_back();
        }
        return str ;
    }
};