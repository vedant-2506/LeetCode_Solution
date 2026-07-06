#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        //using 2 loop TC=O(n^2) SC=O(1)
        int maxAlt=0;
        for(int i=0; i<gain.size(); i++){
            int alt=0;
            for(int j=0; j<=i; j++){
                alt+=gain[j];
            }
            maxAlt = max(maxAlt , alt);
        }
        return maxAlt;
        
        
        // //Prifix sum TC=O(n) SC=O(1)
        // int maxAltitude =0;
        // int altitude=0;
        // for(int i=0; i<gain.size(); i++){
        //     altitude += gain[i];
        //     maxAltitude = max(maxAltitude , altitude);
        // }
        // return maxAltitude;


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