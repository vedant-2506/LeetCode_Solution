#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {

        //  TC = O(n)  SC = O(n)
        int sz = n;

        if(sz == 1) return 1;
        if(sz == 2) return 2;

        vector<int>tab(sz+1 , 0);

        tab[0] = 0 , tab[1] = 1 , tab[2] = 2;

        for(int i=3; i<= n; i++){
            tab[i] = tab[i-1] +  tab[i-2];
        } 

        return tab[sz];
        
    }
};

int main(){

    Solution s;

    int n;

    cout<<"Enter the number of stairs : ";  
    cin>>n;

    cout<<s.climbStairs(n)<<endl;

    return 0;
}