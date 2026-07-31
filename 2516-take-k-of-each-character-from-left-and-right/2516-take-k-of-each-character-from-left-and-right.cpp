class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        vector<int> total(3,0);
        if(k ==0 ){
            return 0;
        }
        for(char ch : s){
            total[ch-'a']++;
        }
        if(total[0]<k || total[1] < k || total[2] < k){
            return -1;
        }

        int i =0 ;
        int j =0;
        int maxlen = INT_MIN;
        vector<int> freq(3,0);

        while(i<n){
            freq[s[i]-'a']++;
            while(freq[0] > total[0] - k ||
                  freq[1] > total[1] - k ||
                  freq[2] > total[2] - k){
                    freq[s[j]-'a']--;
                    j++;
                  }

            maxlen = max(maxlen , i-j+1);
            i++;

        }

         return n - maxlen ;

    }
};