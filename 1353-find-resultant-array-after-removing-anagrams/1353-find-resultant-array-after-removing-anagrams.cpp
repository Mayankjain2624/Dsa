class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string prev;
        vector<string> ans;
        for(auto &word:words){
            string sorted_word = word;
            sort(sorted_word.begin(),sorted_word.end());
            if(sorted_word != prev){
                ans.push_back(word);
                prev = sorted_word;
            }
        }
        return ans;
    }
};