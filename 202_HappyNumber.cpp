
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {

        //TC=O(log n) SC=O()
        unordered_set<int>set;
        while(n!=1 && set.find(n) == set.end()){
            set.insert(n);
            n = SqFact(n);
        }

        return n==1;
    }

    int SqFact(int n){
        int ans=0;
        while(n>0){
            int a = n%10;
            ans += a*a;
            n= n/10;
        }
        return ans;
    }
};

int main() {
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 0;
    }

    Solution solution;
    if (solution.isHappy(n)) {
        cout << n << " is a Happy Number." << endl;
    } else {
        cout << n << " is not a Happy Number." << endl;
    }

    return 0;
}
