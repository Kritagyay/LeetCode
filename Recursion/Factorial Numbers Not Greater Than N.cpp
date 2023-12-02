long long int fact(long long int n){

if(n==0){return 1;}

return n*fact(n-1);

}

 

void factnum(vector<long long> &ans,long long int n,long long int i){

  if(fact(i)>n) return;

  ans.push_back(fact(i));

factnum(ans,n,i+1);

 }

vector<long long> factorialNumbers(long long n) {

   long long int i=1;

   vector<long long> ans;

   factnum(ans,n,i);

   return ans;

}