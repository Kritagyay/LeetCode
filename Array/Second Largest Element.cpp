vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    int first_max=INT_MIN,second_max=0;
    
    int first_min=INT_MAX,second_min=0;

    for(int i=0; i<=n-1; i++){
        if(a[i]>first_max){
            second_max=first_max;
            first_max=a[i];    
        }
        else if(second_max<a[i]){
            second_max=a[i];
        }

        if(a[i]<first_min){
            second_min=first_min;
            first_min=a[i];
        }
        else if(second_min>a[i]) {
            second_min=a[i];

        }
    }
    // cout<<second_min;

    return {second_max,second_min};
}
