#include<iostream>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {

        //TC=O(n) SC=O(1)
        if(n == 0) return 0;
        if(n <= 2) return 1;

        int a=0 , b=1 , c=1;
        for(int i=3; i<=n; i++){
            int ans = a+b+c;

            a=b;
            b=c;
            c=ans;
        }

        return c;
        
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    int result = solution.tribonacci(n);

    cout << "The " << n << "-th Tribonacci number is: " << result << endl;

    return 0;
}