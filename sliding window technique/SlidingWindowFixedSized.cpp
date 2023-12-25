//Sliding Window Fixed Size

//Given an array of integers of size ‘n’, Our aim is to calculate the maximum sum of ‘k’ consecutive elements in the array.

#include<iostream>
#include<math.h>
using namespace std;

int max(int num1,int num2)
{
return (num1>num2) ? num1: num2;
}
//subarray size ->k
int maxSum(int arr[], int n, int k)
{
if(n<k){
cout<<"Invalid";
}
int max_sum=0;
for(int i=0;i<k;i++)
max_sum+=arr[i];
int windowsum=max_sum;

for(int i=k;i<n;i++){
windowsum+=arr[i]-arr[i-k];
max_sum=max(max_sum,windowsum);

}
return max_sum;







}


int main()
{
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n, k);
    return 0;
}
