class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> s, p;
        for (int e : arr) {
            unordered_set<int> temp;
            temp.insert(e);
            for (int u : p) {
                temp.insert(u | e);
            }
            p = temp;
            s.insert(p.begin(), p.end());
        }
        return s.size();
    }
};