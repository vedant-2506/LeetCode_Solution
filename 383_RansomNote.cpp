#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        // TC = O(n + m)
        // SC = O(n + m)

        unordered_map<char, int> unR;

        for(auto i : ransomNote) {
            unR[i]++;
        }

        unordered_map<char, int> unM;

        for(auto k : magazine) {
            unM[k]++;
        }

        for(auto j : ransomNote) {
            if(unR[j] > unM[j]) {
                return false;
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    string ransomNote;
    string magazine;

    cout << "Ransom Note Checker\n";
   

    cout << "Enter ransom note: ";
    cin >> ransomNote;

    cout << "Enter magazine: ";
    cin >> magazine;

    bool result = obj.canConstruct(ransomNote, magazine);


    if(result) {
        cout << "Result: Ransom note CAN be constructed." << endl;
    }
    else {
        cout << "Result: Ransom note CANNOT be constructed." << endl;
    }

    return 0;
}