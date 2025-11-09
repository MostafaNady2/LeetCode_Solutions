class Solution {
public:
    int countOperations(int num1, int num2) {
        long long ans=0;
        while(num1 && num2){
            while(num1 >= num2 && num1 && num2){
                num1-=num2;
                ans++;
            }
            while(num2 >= num1 && num1 && num2){
                num2-=num1;
                ans++;
            }
        }
        return ans;
    }
};