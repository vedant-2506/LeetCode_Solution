#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {


    //    //Generate All Repeated Strings TC=O( (m+n)^2) SC=O(m+n)
    //    //Time Limit Exceeded 57 / 63 testcases passed
    //    for(int count=1; count<=b.size(); count++){
    //     string temp="";
    //     for(int i=0; i<count; i++){
    //         temp+=a;
    //     }
    //     if(temp.find(b) != string::npos) return count;
    //    }
    //    return -1;

        
      //Incremental String Construction + Substring Search 
      //TC=O((n+m)*n) SC=O(n+m)
      string temp="";
      int count=0;

      while(temp.size() < b.size() ){
        temp+=a;
        count++;
      }

      if(temp.find(b) != string::npos) return count;

      temp+=a;
      count++;

      if(temp.find(b) != string::npos) return count;

      return -1;

        
    }
};

int main() {

    Solution sol;
    string a, b;

    cout << "Enter the first string (to be repeated): ";
    cin >> a;

    cout << "Enter the second string (to be matched): ";
    cin >> b;

    int result = sol.repeatedStringMatch(a, b);

    cout << "\nResult: ";

    if(result != -1) {
        cout << "\"" << b << "\" can be obtained by repeating \"" << a << "\" " << result << " times." << endl;
    }
    else {
        cout << "\"" << b << "\" cannot be obtained by repeating \"" << a << "\"." << endl;
    }

    return 0;
}