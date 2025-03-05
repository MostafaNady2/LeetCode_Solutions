class Solution {
public:
    long long coloredCells(int n) {
        long long ans=5;
        if(n==1){
            return 1;
        }else if(n==2){
            return 5;
        }else{
            // for(int i = 3 ; i <= n;i++){
            //     ans+=(2*i - 2)*2;
            // }

            long long term =(3+n);
            term*=(n-2);
            term*=2;
            ans+=term;
            ans-=((n-2)*4);
        }
        return ans;
    }
};