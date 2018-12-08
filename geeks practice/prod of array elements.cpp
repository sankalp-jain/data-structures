//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//Position this line where user code will be pasted.

long long int product(int ar[], int n, long long int mod)
 {
     
     //code here
     long long int p = 1;
     for (int i = 0; i < n; i++){
     	 cout << p << endl;
         p *= ((p % mod) * (ar[i] % mod))% mod;
         cout << p << " ";
     }
     return p % mod;
     
 }

int main()
{
 int t;
 cin>>t;
 while(t--)
   {
    int n;
    cin>>n;
    int ar[100001]={0};
    for(int i=0;i<n;i++)
      cin>>ar[i];  
      
    long long int mod=1000000007;
   cout<<product(ar,n,mod)<<endl;
    
 }
return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
/*  
     ar[] is the array
     n = number of element in array
     mod = modulo value;
*/

