class Solution {
public:
    string frequencySort(string s) {
        int freq[256]={0};
        for(char c:s){
            freq[c]++;
        }
        vector<pair<int,int>>vp;
        for(int i=0;i<256;i++ ){
            if(freq[i]>0){
                vp.push_back({freq[i],(char)i});
            }
        }
        sort(vp.begin(),vp.end(),greater<>());
        string ans;
        for(auto &it:vp){
            int f=it.first;
            int c=it.second;
            while(f--)
            ans.push_back(c);
        }
        return ans;
    }
};