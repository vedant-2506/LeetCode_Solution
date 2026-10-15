
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {

        // TC = O(n), SC = O(n)
        stack<int> stk;

        for(int i = 0; i < operations.size(); i++) {

            if(operations[i] == "D") {
                // Double the previous score
                int a = stk.top();
                stk.push(a * 2);
            }
            else if(operations[i] == "C") {
                // Remove the previous score
                stk.pop();
            }
            else if(operations[i] == "+") {
                // Sum the previous two scores
                int b = stk.top();
                stk.pop();

                int c = stk.top();

                // Restore the previous score
                stk.push(b);

                // Push the sum of the last two scores
                stk.push(b + c);
            }
            else {
                // Convert the numeric string to an integer
                stk.push(stoi(operations[i]));
            }
        }

        // Calculate the sum of all valid scores
        int sum = 0;

        while(!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }

        return sum;
    }
};

int main() {
    Solution obj;

    int n;

    // Input the number of operations
    cout << "Enter the number of operations: ";
    cin >> n;

    if(n < 1) {
        cout << "Invalid number of operations!\n";
        return 0;
    }

    vector<string> operations(n);

    // Input operations: integer, D, C, or +
    cout << "Enter the operations (e.g., 5 2 C D +):\n";

    for(int i = 0; i < n; i++) {
        cin >> operations[i];
    }

    // Calculate the total score
    int result = obj.calPoints(operations);


    cout << "Total score: " << result << endl;


    return 0;
}
