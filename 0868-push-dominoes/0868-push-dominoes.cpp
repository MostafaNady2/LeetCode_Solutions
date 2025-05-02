class Solution {
public:
string pushDominoes(string dominoes)
{
    string ans = dominoes;
    int n = dominoes.size();
    int i = 0;
    while (i < n && dominoes[i] == '.'){
        i++;
    }
    int j = n - 1;
    while (j >= 0 && dominoes[j] == '.'){
        j--;
    }
    for (int k = i; k < j; k=k){
        char start=dominoes[k];
        while(k < j && dominoes[k] !='.'){
            start=dominoes[k];
            k++;
        }
        int count=0;
        while(k < j && dominoes[k] == '.'){
            count++;
            k++;
        }
        char end=dominoes[k]; 
        if(start == end){
            int cnt=count;
            while(count--){
                ans[k-cnt] = start;
                cnt--;
            }
        }else if(start == 'R' && end == 'L'){
            if(count&1){
                int mid = k-count/2;
                int temp = mid - 1 - count/2;
                count/=2;
                while(mid  < k){
                    ans[mid++]=end;
                }
                while(count--){
                    ans[temp++] = start;
                }
            }else{
                int mid = k-count/2;
                int temp = mid - count/2;
                count/=2;
                while(mid  < k){
                    ans[mid++]=end;
                }
                while(count--){
                    ans[temp++] = start;
                }
            }
        }
    }
    if (i < n && dominoes[i] == 'L'){
        while (i--)
        {
            ans[i] = 'L';
        }
    }
    if (j >= 0 && dominoes[j] == 'R'){
        while (j < n)
        {
            ans[j] = 'R';
            j++;
        }
    }

    return ans;
}
};