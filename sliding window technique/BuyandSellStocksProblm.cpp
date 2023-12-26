
#include<iostream>
#include<vector>
using namespace std;
/*Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell
 on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on 
day 1 is not allowed because you must buy 
before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions
 are done and the max profit = 0.*/
class Solution {
public:
    void maxproffitFn(vector<int>& prices, int i, int& minprice, int& maxprofit) {
        // base case
        if (i == prices.size()) return;

        if (prices[i] < minprice) minprice = prices[i];
        int todaysprofit = prices[i] - minprice;
        if (todaysprofit > maxprofit) maxprofit = todaysprofit;

        maxproffitFn(prices, i + 1, minprice, maxprofit);
    }

    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int minprice = prices[0];  
        int maxprofit = 0;         

        maxproffitFn(prices, 0, minprice, maxprofit);
        return maxprofit;
    }
};
