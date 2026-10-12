
#include <iostream>
using namespace std;

// Simulate the LeetCode guess API for local testing
int pickedNumber;

// Returns:
// -1 if the guess is higher than the picked number
//  1 if the guess is lower than the picked number
//  0 if the guess is correct
int guess(int num) {
    if(num > pickedNumber) return -1;
    if(num < pickedNumber) return 1;
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {

        // Binary Search TC = O(log n), SC = O(1)

        int lo = 1, hi = n;

        while(lo <= hi) {
            // Calculate the middle value safely
            int pick = lo + (hi - lo) / 2;

            // Check the guess
            int res = guess(pick);

            // The correct number is found
            if(res == 0) {
                return pick;
            }

            // Guess is higher than the picked number
            if(res == -1) {
                hi = pick - 1;
            }
            // Guess is lower than the picked number
            else if(res == 1) {
                lo = pick + 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    int n;

    // Input the upper limit
    cout << "Enter the value of n: ";
    cin >> n;

    if(n < 1) {
        cout << "Invalid input! n must be at least 1.\n";
        return 0;
    }

    // Input the number to be guessed
    cout << "Enter the picked number (1 to " << n << "): ";
    cin >> pickedNumber;

    if(pickedNumber < 1 || pickedNumber > n) {
        cout << "Invalid picked number!\n";
        return 0;
    }

    // Find the picked number using binary search
    int result = obj.guessNumber(n);

    cout << "Guessed number: " << result << endl;
   

    return 0;
}
