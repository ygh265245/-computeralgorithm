#include <bits/stdc++.h>
using namespace std; 

char P[6]={0, 'e','e','a','a','b'};
char A[17]={0, 'a', 'c','e','b','b','c','e','e','a','a','b', 'c', 'e', 'e', 'd', 'b'};
int m=5, n=16; // P의 길이=5, A의 길이=16 

void basicRabinKarp(char A[], char P[], int d){
	int p=0;
	int a=0;
	int h=1;
	for (int i=m;i>=1;i--){
		p=p+((P[i]-97)*h);   //ASCII 값에 97을 빼면 a=0, b=1... 
		a=a+((A[i]-97)*h);
		h=h*d;
	}	

	for (int i=1;i<=20;i++){
		if (i!=1)
		{
			a=d*(a-((A[i-1]-97)*pow(d, m-1)))+(A[i+m-1]-97);
		}
			
		if (p==a)
			{	cout << i;
		}
	}
	
}


int main(int argc, char** argv) {
	printf("매칭시작점 : "); 
	basicRabinKarp(A, P, 5);
	return 0;
}
