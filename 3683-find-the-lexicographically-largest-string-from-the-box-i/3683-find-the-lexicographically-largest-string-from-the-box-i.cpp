class Solution {
public:
    string answerString(string word, int numFriends) {
        string ans="";
        if(numFriends==1)
        return word;
        int rl=word.size()-numFriends+1;
        for(int i=0;i<word.size();i++){
            string ss=word.substr(i,rl);
            ans=max(ans,ss);
        }
        return ans;
    }
};