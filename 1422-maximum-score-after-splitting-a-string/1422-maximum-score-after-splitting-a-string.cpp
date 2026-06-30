class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> zero(n);
        vector<int> one(n);
        zero[0] = 0;
        one[n-1] =0;
        int temp =0;
        if(s[0]=='0'){
            temp = 1 ;
        }
        for(int i =1 ;i<n ; i++){
             
             if(s[i] == '0'){
                temp++;
             }
             zero[i] = temp;
             
        }
        temp = 0;
        if(s[n-1] == '1'){
            temp =1;
        }
        for(int i =n-2 ; i>=0 ; i--){
            
            if(s[i]=='1'){
                temp++;
            }
            one[i]= temp ;
        }
        int i =1 ;
        int maxi = 0;
        
        while(i<n-1){
          int val = one[i]+zero[i];
          i++;
          maxi = max(maxi,val);
        }
        int a =0;
        int b =0;

        if(s[0]=='0') a++;
        if(s[1]== '1') b++;
        maxi = max(maxi,a+b);
        return maxi ;

    }
};