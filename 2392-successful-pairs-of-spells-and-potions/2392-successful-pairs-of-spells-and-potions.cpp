class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        long long int n=spells.size();
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            long long int threshold=ceil(success*1.0/spells[i]);
            long long int j=lower_bound(potions.begin(),potions.end(),threshold)-potions.begin();
            spells[i]=potions.size()-j;
        }
        return spells;
    }
};