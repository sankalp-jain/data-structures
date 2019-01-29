#include <string>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a[] = {1, 34, 3, 98, 9, 76, 45, 4};
    int n = sizeof(a) / sizeof(a[0]);
    string aa[n];
    for (int i = 0; i < n; i++){
    	aa[i] = patch::to_string(a[i]);
	}
	for (int i = 0; i < n; i++)
		cout << aa[i] << " "; 
	cout << endl;
	sort(aa, aa + n);
	for (int i = 0; i < n; i++)
		cout << aa[i] << " ";
	
}
