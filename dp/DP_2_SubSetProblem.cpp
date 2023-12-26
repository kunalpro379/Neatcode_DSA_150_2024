//SUbsetSumProblem.cpp

/*Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True
Explanation: There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
Explanation: There is no subset that add up to 30.*/



//using recurssion
//take - non take


#include <iostream>
#include <vector>
using namespace std;

// Recursive approach
bool IsSumRec(vector<int> a, int sum, int tempssum, int i) {
    if (sum == tempssum)
        return true;

    if (i >= a.size())
        return false;

    int incl = IsSumRec(a, sum, tempssum + a[i], i + 1);
    int excl = IsSumRec(a, sum, tempssum, i + 1);

    return incl || excl;
}

bool IsSubSetSumRec(vector<int> arr, int sum) {
    return IsSumRec(arr, sum, 0, 0);
}

// Tabulation Approach
bool IsSumTab(vector<int>& arr, int sum) {
    int n = arr.size();

    vector<vector<bool>> DP(n + 1, vector<bool>(sum + 1, false));

    // Initialization: if target sum is 0
    for (int i = 0; i <= n; i++)
        DP[i][0] = true;

    // Filling the table
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++)
            if (arr[i - 1] > j)
                DP[i][j] = DP[i - 1][j];
            else
                DP[i][j] = DP[i - 1][j] || DP[i - 1][j - arr[i - 1]];

    return DP[n][sum];
}

bool IsSubSetSumTab(vector<int> arr, int sum) {
    return IsSumTab(arr, sum);
}

// Memoization
bool IsSumMem(vector<int>& arr, int n, int sum, vector<vector<int>>& DP) {
    if (n == 0)
        return false;

    if (sum == 0)
        return true;

    if (DP[n][sum] != -1)
        return DP[n][sum];

    if (arr[n - 1] <= sum)
        return DP[n][sum] = IsSumMem(arr, n - 1, sum - arr[n - 1], DP) || IsSumMem(arr, n - 1, sum, DP);

    else
        return DP[n][sum] = IsSumMem(arr, n - 1, sum, DP);
}

bool IsSubSetSumMem(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> DP(n + 1, vector<int>(sum + 1, -1));
    return IsSumMem(arr, n, sum, DP);
}

int main() {
    std::vector<int> arr = {3, 34, 4, 12, 5, 2};
    int targetSum = 9;

    cout << "Recursive approach" << endl;
    if (IsSubSetSumRec(arr, targetSum)) {
        cout << "Subset with sum " << targetSum << " exists." << endl;
    } else {
        cout << "Subset with sum " << targetSum << " does not exist." << endl;
    }

    cout << "Tabulation approach" << endl;
    if (IsSubSetSumTab(arr, targetSum)) {
        cout << "Subset with sum " << targetSum << " exists." << endl;
    } else {
        cout << "Subset with sum " << targetSum << " does not exist." << endl;
    }

    cout << "Memoization approach" << endl;
    if (IsSubSetSumMem(arr, targetSum)) {
        cout << "Subset with sum " << targetSum << " exists." << endl;
    } else {
        cout << "Subset with sum " << targetSum << " does not exist." << endl;
    }

    return 0;
}
