#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    int x=arr[0];
    for(int i=1; i<=n-1; i++){
        if(x<arr[i]){
            x=arr[i];
        }
    }
    return x;

}
