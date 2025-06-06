class Solution {
public:
    string robotWithString(string s) {
        vector<pair<char, int>> vp;
        int n = s.length();
        for (int i = 0; i < s.length(); i++) {
            vp.push_back({s[i], i});
        }
        sort(vp.begin(), vp.end(), greater<>());
        int tl = 0;
        int i = 0;
        string p = "", t = "";
        // for (auto& it : vp) {
        //     cout << it.first << " " << it.second << endl;
        // }
        while (tl < n) {
            // cout<<"check: "<<vp[vp.size()-1].second<<" and tl is "<<tl<<endl;
            int len = vp[vp.size() - 1].second - tl;
            if (vp[vp.size() - 1].second >= tl) {
                string temp = s.substr(tl, len);
                // reverse(temp.begin(),temp.end());
                // cout<<temp<<endl;
                t += temp;
                // cout<<t<<endl;
                p += vp[vp.size() - 1].first;
                tl = vp[vp.size() - 1].second + 1;
                // cout<<p<<endl;
                // cout<<tl<<endl;
            }
            // cout<<"i am exexuted"<<endl;
            if (!t.empty()) {
                char last = t.back();
                while (!t.empty() && last <= vp.back().first) {
                    p += last;
                    t.pop_back();
                    if (!t.empty())
                        last = t.back();
                    else
                        break;
                }
            }

            vp.pop_back();
        }
        reverse(t.begin(), t.end());
        p += t;
        return p;
    }
};