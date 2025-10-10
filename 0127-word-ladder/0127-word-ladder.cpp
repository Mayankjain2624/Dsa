class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string,int>> q;
       unordered_set<string> st(wordList.begin(), wordList.end());
            q.push({beginWord, 1});
        while (!q.empty())
        {
            string currentWord = q.front().first;
            int cost = q.front().second;
            if (currentWord == endWord)
                return cost;
            int x = currentWord.length();
            q.pop();
                for (int i = 0; i < x; i++)
                {
                    char removed=currentWord[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                    currentWord[i] = c;
                    if (st.find(currentWord) != st.end())
                    {
                        q.push({currentWord, cost + 1});
                        st.erase(currentWord);
                    }
                }
                    currentWord[i]=removed;
            }
        }
        return 0;
    }
};