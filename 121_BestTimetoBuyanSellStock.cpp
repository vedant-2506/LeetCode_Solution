#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // //Brute Force TC=(n^2) SC=O(1) time  Time Limit Exceeded
        // int maxProfit=0;
        // for(int i=0; i<prices.size(); i++){
        //     for(int j=i+1; j<prices.size(); j++){
        //         int profit = prices[j] - prices[i];
        //         maxProfit = max(maxProfit , profit);
        //     }
        // }
        // return maxProfit;
        
        //Greedy TC=O(n) SC=O(1)
        int sp=prices[0];
        int profit =0 , maxProfit=0;
        for(int k=1; k<prices.size(); k++){
            profit=prices[k]-sp;
            maxProfit = max(maxProfit ,profit);
            sp = min(sp , prices[k]);
        }      
        return maxProfit;
    }
};

int main() {

    int n;

    cout << "Enter the number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter the stock prices: ";
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    Solution s;

    int result = s.maxProfit(prices);

    cout << "Maximum Profit: " << result << endl;

    return 0;
}