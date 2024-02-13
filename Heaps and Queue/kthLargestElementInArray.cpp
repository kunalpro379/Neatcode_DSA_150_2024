#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          priority_queue<pair<int, vector<int>>> minHeap;
//maxheapp
 for (const auto& point : points) {
            int distance = point[0] * point[0] + point[1] * point[1];// constant time
            //iterating took O(n)
           minHeap.push({distance,point}); //pushing in pq takes O(logk)  time
           if(minHeap.size()>k){//maintaining size of queue not more than k 
            minHeap.pop();
           }}
           vector<vector<int>>result;
           while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
           }
           //from farthest point to closest 
           reverse(result.begin(), result.end());
           return result;
}
};
//**********************************Approach 2****** binary search**********
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

}
};

int main() {
    // Sample points
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, -1}, {0, 0}, {3, 4}};
    int k = 3; // Number of closest points to find

    // Create an instance of the Solution class
    Solution solution;

    // Call the kClosest method to find the k closest points
    vector<vector<int>> closestPoints = solution.kClosest(points, k);

    // Output the k closest points
    cout << "The " << k << " closest points are:\n";
    for (const auto& point : closestPoints) {
        cout << "(" << point[0] << ", " << point[1] << ")\n";
    }

    return 0;

}