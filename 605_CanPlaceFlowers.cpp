#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int sz=flowerbed.size();

        for(int i=0; i<sz; i++){

            if(flowerbed[i] == 0 ){
                
                bool left  = (i == 0    || flowerbed[i-1] == 0);  
                bool right = (i == sz-1 || flowerbed[i+1] == 0);  


                if(right && left ){
                 flowerbed[i] =1;
                 n--;
                }   
            }
        }
        
        return (n <= 0) ; 
    }
};


int main(){

    Solution s;

    vector<int> flowerbed = {1,0,0,0,1};
    int n = 1;

    int ans = s.canPlaceFlowers(flowerbed,n);
    
    if(ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;


    return 0;
}