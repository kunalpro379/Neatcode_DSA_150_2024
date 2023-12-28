#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include <vector>
#include <unordered_map>
#include <queue>


class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> Freq;
        for (int num : nums) {
            Freq[num]++;
        }

        // Use max heap
        std::priority_queue<std::pair<int, int>> maxHeap;
        for (const auto& It : Freq) {
            maxHeap.push({It.second, It.first});
        }

        // getting top k elements 
        std::vector<int> TopKElements;
        while (k > 0 && !maxHeap.empty()) {
            TopKElements.push_back(maxHeap.top().second);
            maxHeap.pop();
            k--;
        }

        return TopKElements;
    }
};

// class Solution {
// public:
//     std::vector<int> topKFrequent(vector<int>& nums, int k) {
//         std::unordered_map<int,int>Freq;
//         for(int num:nums){
//             Freq[num]++;
//         }

// std::priority_queue<std::pair<int, int >>minHeap;
// for(auto& It: Freq){
//     miHeap.push({It.second,It.first});
// //optimizing some space 
// if(maxHeap.size()>k)
// minHeap.pop();

// }


// //getting top k elements 
// std::vector<int>TopKElements;
// while(!minHeap.empty()){
//     TopKElements.push_back(minHeap.top().second);
//     minHeap.pop();

// }
// return TopKElements;

//         for(int i=0;i<nums.size();i++){
//             TopKFreqElements[i].first=i;
//             TopKFreqElements[i].second=nums[i];
//         }
//         std::sort(TopKFreqElements.begin(),TopKFreqElements.end());
// for(int i=1;i<TopKFreqElements.size();i++){
// // int j=i-1;
// // while(i<=TopKFreqElements.size()){
// //     if()
// // }
// if(TopKFreqElements[i].second==TopKFreqElements[i-1].second)
// return TopKFreqElements[i].first;
// else
// return TopKFreqElements[i-1].first;



// }

//     };