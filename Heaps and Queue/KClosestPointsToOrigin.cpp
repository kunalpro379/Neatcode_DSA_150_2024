
#include<iostream>
#include<vector>
using namespace std;
#include<queue>
#define INT_MAX 1222222222222222222;
class KthLargest {
public:
int k;
priority_queue<int,vector<int>, greater<int>>minHeap;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int num: nums){add(num);}
    }
    
    int add(int val) {
        if(minHeap.size()<k){
            minHeap.push(val);
        }
        else if(val>minHeap.size()){
minHeap.pop();
minHeap.push(val);
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */



void swap(int *x , int *y){
int temp=*x;
*x=*y;
*y=temp;
}


class MinHeap{
    public:
int* HArr;
int capacity;
int heap_size;

 MinHeap(int A[], int size){

heap_size=size;
HArr=A;
}
void BuildHeap();
void MinHeapify(int i);
int parent(int i){return (i-1)/2;}
int left(int i){return 2*i+1;}
int right(int i){return 2*i+2;}
int extractMIn();
int getMIn(){return HArr[0];}
void ReplaceMin(int x){
    HArr[0]=x;
    MinHeapify(0);
}


};
void MinHeap::BuildHeap(){

int i=(heap_size-1)/2;
while (i>=0)
{
    MinHeapify(i);
    i--;
}

}

void MinHeap:: MinHeapify(int i){
int l=left(i);
int r=right(i);
int smallest=i;

if(l<heap_size&& HArr[l]<HArr[i]){
smallest=l;

}

if(r<heap_size&&HArr[r]<HArr[i]){
smallest=r;
}

if(smallest!=i){
swap(&HArr[i],&HArr[smallest]);
MinHeapify(smallest);

}


}
int MinHeap:: extractMIn(){
if(heap_size==0){
    return INT_MAX;
}

int root=HArr[0];
if(heap_size>1){
    HArr[0]=HArr[heap_size-1];
    MinHeapify(0);
}
heap_size--;
return root;


}
void KthLargest(int k, vector<int>&A){
    int count =0;
    int* arr=new int[k];
    MinHeap hip(arr,k);

    for(auto &x : A){
if(count<k-1){
    arr[count]=x;
    count++;
    cout<<"Kth Largest Element is -1 :"<<endl;

}else {
    if(count==k-1){
        arr[count]=x;
        hip.BuildHeap();
    
    }
    else{
        if(x>hip.getMIn())
        hip.ReplaceMin(x);
    }
    cout<<"Kth largest element is :"<<hip.getMIn()<<endl;
    count++;
}
    }
}










 class soln2{
public:

 };



int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    int K = 3;

    KthLargest(K, arr);

    return 0;
}




















/*
The problem is asking you to find and maintain the Kth largest element in an infinite stream of integers. You can only store K elements at any given time. As new elements come in the stream, you need to update the Kth largest element accordingly.

Here's a high-level approach to solve this problem:

Initialize a data structure to store K elements. This could be a min-heap, max-heap, or any other suitable data structure.

Process the stream one element at a time.

If the size of your data structure is less than K, simply insert the current element.
If the size is equal to K, compare the current element with the smallest (or largest, depending on your data structure) element in your data structure.
If the current element is larger (or smaller), replace the smallest (or largest) element with the current one.
The Kth largest element is the smallest element in your data structure.

This way, as you process the stream, your data structure will always contain the Kth largest element encountered so far.

Let's look at the examples you provided:

Example 1:

css
Copy code
Input: stream[] = {10, 20, 11, 70, 50, 40, 100, 5, ...}, K = 3
Output: {_, _, 10, 11, 20, 40, 50, 50, ...}
For the first three elements (10, 20, 11), just insert them into your data structure.
For the fourth element (70), it's larger than the smallest element (10) in your data structure, so replace 10 with 70.
For the fifth element (50), it's also larger than the smallest element (11) in your data structure, so replace 11 with 50.
And so on...
Example 2:

css
Copy code
Input: stream[] = {2, 5, 1, 7, 9, ...}, K = 2
Output: {_, 2, 2, 5, 7, ...}
For the first two elements (2, 5), just insert them into your data structure.
For the third element (1), it's smaller than the second smallest element (2) in your data structure, so no change.
For the fourth element (7), it's larger than the smallest element (2) in your data structure, so replace 2 with 7.
And so on...
This way, you always have the Kth largest element in your data structure.*/