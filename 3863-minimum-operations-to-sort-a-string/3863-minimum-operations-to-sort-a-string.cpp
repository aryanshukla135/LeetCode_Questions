class Solution {
private:
    int solve(string & s){
        int n = s.length();
        string str =s;
        sort(str.begin(),str.end());
        int cnt = 0 ;
        if(str == s){
            return cnt ;
        }
        if(n == 2){
            return -1;
        }
        if (s[0] == str[0] || s[n - 1] == str[n - 1]) {
            return 1;
        }

        string s1 = s ;
        sort(s1.begin() +1 , s1.end());
        sort(s1.begin(),s1.end()-1);
        if(s1 == str){
            return 2 ;
        }

        string s2 = s ;
        sort(s2.begin() , s2.end() - 1 );
        sort(s2.begin() + 1 ,s2.end());
        if(s2 == str){
            return 2 ;
        }

        return 3 ;
        // int j =0 ;
        // for(int i =0 ; i<n -1 ;i++){
        //     if(str[j] != s[i]){
        //         string strt = s.substr(0,i);
        //         string s1 = s.substr(i);
        //         char ch = s[n-1];
        //         string s2 = "";
        //         string f = "";
        //         if(i ==0 ){
        //             s2 = s.substr(i,n-1);
        //             sort(s2.begin(),s2.end());
        //             f = strt + s2 + ch ;
        //         }else{
        //             s1 = s.substr(i);
        //             sort(s1.begin(),s1.end());
        //             f = strt + s1 ;
        //         }
        //        s = f ;
        //        cnt++;
        //        if(str == s){
        //           return cnt ;
        //        } 
        //     }
        //     j++;
        // }
        // return -1;
    }
public:
    int minOperations(string s) {
        // string str = s ;
        // reverse(str.begin(),str.end());
        int n = s.length();
        

        int cnt1 = solve(s);
        ///int cnt2 = solve(str);

        // cout<<cnt1<<" "<<cnt2;
        // if(cnt1 == -1){
        //     return cnt2;
        // }
        return cnt1 ;

    }
};
// bdec  n -  i  -1 
// bcde
// ecd
// ced
// cde 
// acdr -> acdr
// bcde -> bdec -> bcde
// abc -> acb -> abc 
// ggj ->gjg -> ggj 