void func(int n, vector<string>&arr)
{
	if (n>0)
	{
		func(n-1,arr);
		arr.emplace_back("Coding Ninjas");
	}
}


vector<string> printNTimes(int n) {
	// Write your code here.
	vector<string>arr;
	func(n,arr);
	return arr;
}