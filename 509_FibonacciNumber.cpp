#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        
        //TC=O(n) SC=O(1)
        if (n < 2) {
        return n;
        }
        
        int prev = 0, cur = 1;
        for (int i = 2; i <= n; i++) {
            int next = prev + cur;
            prev = cur;
            cur = next;
        }
    
        return cur;

    }
};

int main(){
    Solution solution;

    int n;
    cout<< "Enter a non-negative integer n: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid input. Please enter a non-negative integer." << endl;
        return 1;
    }

    int result = solution.fib(n);

    cout << "The " << n << "th Fibonacci number is: " << result <<endl;

    return 0;
}