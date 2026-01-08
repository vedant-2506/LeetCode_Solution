#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {

        int ans=0;
        int MAX= INT_MAX/10 , MIN= INT_MIN/10;
        while (x != 0){
            if(MAX < ans || MIN > ans ){
               return 0; // break;
            } 
            else{
                ans = (ans * 10) + (x % 10);
                x /=10;
            }
        }
        return ans;
        
    }
};

int main(){
    int x;

    cout<<"Enter an integer: ";
    cin>>x;

    Solution sol;
    int Fans = sol.reverse(x);
    cout<<"Reversed integer: "<<Fans<<endl;

    return 0;

}
