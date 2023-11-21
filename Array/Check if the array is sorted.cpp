int isSorted(int n, vector<int> a) {
    // Write your code here.
    int max=a[0];
    for(int i=1; i<=n-1;i++){
        if(max<a[i]){
            max=a[i];
        }
        if(max>a[i]){
            return 0;
        }
    }
    return 1;
}
