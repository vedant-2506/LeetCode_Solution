#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        // //using 2 pointer TC=O(m*n) SC=O(1)
        // int i=0;
        // while(i<haystack.size() ){
        //     int j=0 , k=i;
        //     while(j<needle.size() && k<haystack.size() && haystack[k] == needle[j] ){
        //         j++;
        //         k++;
        //     }
        //     if(j == needle.size()) return i;

        //     i++;
        // }
        // return -1;

        //using substr funtion TC=O(m*n) SC=O(m)
        for(int i=0; i<haystack.size(); i++){
            string s1 = haystack.substr(i, needle.size());
            if(s1 == needle) return i;
        }
        return -1;
    }
};

int main() {

    Solution s;

    string haystack, needle;

    cout << "Enter the main string (haystack): ";
    cin >> haystack;

    cout << "Enter the substring to search (needle): ";
    cin >> needle;

    int index = s.strStr(haystack, needle);

    if(index == -1) {
        cout << "\nSubstring not found in the main string." << endl;
    }
    else {
        cout << "\nSubstring found at index: " << index << endl;
    }

    return 0;
}