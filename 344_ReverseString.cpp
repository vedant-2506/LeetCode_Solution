#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {

        //using extra spec TC=O(n) SC=O(n)
        vector<char>temp;
        for(int i=s.size()-1; i>=0; i--){
            temp.push_back( s[i] );
        }
        s=temp;

        // //inpace + swap() TC=O(n) SC=(1)
        // int i=0, j=s.size()-1;
        // while(i<j){
        //     swap(s[i] , s[j]);
        //     i++;
        //     j--;
        // }

    }
}; 

int main() {

    int n;

    cout << "Enter the number of characters: ";
    cin >> n;

    vector<char> s(n);

    cout << "Enter the characters:\n";
    for(int i = 0; i < n; i++) {
        cout << "Character " << i + 1 << ": ";
        cin >> s[i];
    }

    Solution sol;
    sol.reverseString(s);

    cout << "\nReversed characters: ";
    for(char ch : s) {
        cout << ch << " ";
    }

    cout << endl;

    return 0;
}

