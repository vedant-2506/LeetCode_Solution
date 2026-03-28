#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        
        //1st solution 
        // return sqrt(x);

        //2nd solution 
        // if(x == 0 ) return 0;
        // long guss = x;
        

        // while(true){
        //     long next = (guss + x/guss) /2;

        //     if(guss <= next) break;

        //     guss=next;
        // }
        
        // return guss;


        // //3rd solution 
        if(x == 0) return 0;
        if(x == 1) return 1;

        long low = 0, high = x;
        long ans = 0;

        while(low <= high){
            long mid = (low + high) / 2;

            if(mid * mid == x) return mid;       

            else if(mid * mid < x){
                ans = mid;                       
                low = mid + 1;                   
            }
            else{
                high = mid - 1;                  
            }
        }

        return ans; 
    }
};


int main(){
    Solution s;
    int x = 8;
    cout<<s.mySqrt(x)<<endl;
    return 0;
}