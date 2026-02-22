class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        while (!q.empty()) {
            string s = q.front().first;
            int cost = q.front().second;
            q.pop();
            if(s==endWord)
            return cost;
            int ss = s.size();
            for (int i = 0; i < ss; i++) {
                int oc=s[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    s[i] = c;
                    if(st.find(s)!=st.end()){
                        st.erase(s);
                        q.push({s,cost+1});
                    }
                }
                s[i]=oc;
            }
        }
        return 0;
    }
};