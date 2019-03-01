#include<bits/stdc++.h> 
using namespace std;

int main(){
	char txt[] = "THIS IS A TEXT";
	char pat[] = "TEST";
	int N = strlen(txt);
	int M = strlen(pat);
	int flag = 0;
	for (int i = 0; i < N - M; i++){
		int j, c = 0;
		for (j = 0; j < M; j++){
			if(txt[i + j] == pat[j])
				c++;
		}
		if (c == M)
		{
			cout << "Pattern found";
			flag = 1;
			break;
		}
	}
	if(flag == 0)
		cout << "Not found";
}
