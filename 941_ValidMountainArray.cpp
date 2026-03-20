#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int sz =arr.size();
        if( sz <  3) return false;

        if(arr[sz-1] > arr[sz-2] ) return false;
        int i=0;
        while(i+1<sz && arr[i]<arr[i+1] ){ i++;  }

        if(i == 0)return false;

        while( i+1<sz && arr[i]>arr[i+1] ){ i++;}

        if(i < sz-1)return false;
        else return true;        
    }
};


int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    bool isMountain = sol.validMountainArray(arr);

    if (isMountain) {
        cout << "Given array is a valid mountain array" << endl;
    } else {
        cout << "Given array is not a valid mountain array" << endl;
    }

    return 0;
}