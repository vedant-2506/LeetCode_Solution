#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
        
        bool isprime (int num){
            if(num <= 1) return false; 
            for(int i = 2; i*i <= num; i++)
            {
                if(num % i == 0) return false;
            }//for i end 
            return true;
        }//end function    
        

    int diagonalPrime(vector<vector<int>>& nums) {
        
        int n= nums.size();
        int m=nums[0].size();
        int ans=0;
 
        for(int i=0;i<n;i++){
            if(isprime(nums[i][i]))
                ans = max(ans , nums[i][i]);
    
            if(isprime(nums[i][n-i-1]))
                ans = max(ans , nums[i][n-i-1]);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> nums = {{1,2,3},{5,6,7},{9,10,11}};
    cout << s.diagonalPrime(nums) << endl; // Output: 11
    return 0;
}