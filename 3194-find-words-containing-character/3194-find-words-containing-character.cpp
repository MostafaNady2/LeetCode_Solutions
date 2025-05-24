class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> idx;
        int i = 0;
        for (string word : words) {
            for (char c : word) {
                if (c == x) {
                    idx.push_back(i);
                    break;
                }
            }
            i++;
        }
        return idx;
    }
};