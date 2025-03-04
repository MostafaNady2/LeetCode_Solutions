class Solution {
public:
bool checkPowersOfThree(int n)
{
    vector<int> v;
    for(int i = 0; i < 16; i++){
        v.push_back((int)pow(3, i));
    }
    for(int i = 0; i < (1 << 16); i++){
        int sum = 0;
        for(int j = 0; j < 16; j++){
            if(i & (1 << j)){
                sum += v[j];
            }
        }
        if(sum == n){
            return true;
        }
    }
    return false;
}
};