#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int sz= gain.size();
        int ans=0,sum=0;

        for(int i =0; i<sz;i++){
            
            sum +=gain[i];
            ans= max(sum ,ans);
        }

        return ans;
    }
};

int main(){

    int n;
    cout<<"Enter number of gains :";
    cin>>n;

    vector<int>gain(n);
    cout<<"Enter the gains :";
    for(int i=0; i<n; i++){
        cin>>gain[i];
    }

    Solution sol;

    int result = sol.largestAltitude(gain);

    cout<<"The highest altitude is  "<<result<<endl;

    return 0;
}