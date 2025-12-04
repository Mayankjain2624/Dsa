class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        int res = 0;

        string new_s;
        for(int i = 0; i < n; i++) {
            if(i != n - 1 && s[i] == 'R' && s[i + 1] == 'L') { new_s.push_back('S'); i++; res += 2; }
            else new_s.push_back(s[i]);
        }

        s = new_s;
        bool found = false;
        int r = 0, l = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'S') { 
                res += r;
                if(found) res += l;
                l = 0; r = 0; 
                found = true;
            }
            else if(s[i] == 'L') l++;
            else r++;
        }

        return res + (found ? l : 0);
    }
};