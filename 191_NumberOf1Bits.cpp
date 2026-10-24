#include <iostream>
#include <bitset>

using namespace std;

int hammingWeight(int n) {
    // TC = O(k), worst case O(1) SC = O(1)
    int count = 0;
    while (n != 0) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main() {
    int n;

    cout << "Enter an integer: ";
    cin >> n;

    cout << "Binary representation: "
         << bitset<32>(static_cast<unsigned int>(n)) << endl;

    cout << "Number of set bits (1s): "
         << hammingWeight(n) << endl;

    return 0;
}
