class Solution {
public:
    long long countVowels(string word) {
        int n = word.length();
        long long ans =0;

        unordered_set<char> st = {'a','e','i','o','u'};

        long long sum =0;
        long long temp =0;
        for(int i =0 ; i< n ; i++){
            if(st.count(word[i])){
                sum++;
            }
            temp+=sum;
        }
        ans = temp ;
        if(st.count(word[0])){
            temp -=n;
        }
        for(int i = 1 ; i<n ; i++){
            ans += temp ;
            if(st.count(word[i])){
                temp -= n-i;
            }
        }
        
        return ans;
    }
};
//1 1 2
//4+1+1
//aaa
//a aa aaa a aa a
//1 2 3 
//0 1 2
//0 0 1
// 1 3 6

// 6+3+1
// phle total sum of vowels nikal lo 
// fir index ke hisab se subreact krte jaao 
// subract index ke aage jitne element hoge sb me se hoga for vowels
