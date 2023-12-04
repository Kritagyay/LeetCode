void func(int x, vector<int>&arr)
{
    if(x>0)
    {
        arr.emplace_back(x);
        func(x-1,arr);

    }
    
    
}


vector<int> printNos(int x) {
    // Write Your Code Here
    vector <int> arr;
    func(x,arr);
    return arr;
}