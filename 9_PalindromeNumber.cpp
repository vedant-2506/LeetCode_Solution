#include<iostream>
#include<climits>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
    
    int  MAX = INT_MAX/10 ,MIN= INT_MIN/10;
    int ans =0 , dx=x;
    if(x<0){
        return false;
    }
    while(x >0){

        if(MAX <ans || MIN >ans){
            return 0;
        }
        else{
            ans =(ans*10 )+ (x % 10);
            x/=10;
        }
    }

    return ans == dx;
    }
};
int main(){
    int x;

    cout<<"Enter an Integer to check is it palindrome or not: ";
    cin>>x;

    Solution sol;
    bool isright = sol.isPalindrome(x);

    if(isright){
        cout<<"Given "<<x<<" is a palindrome number"<<endl;
    }
    else{
        cout<<"Given "<<x<<" is not a palindrome number"<<endl;
    }

    return 0;

}