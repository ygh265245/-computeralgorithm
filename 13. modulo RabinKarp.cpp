#include <bits/stdc++.h>
using namespace std; 

char P[6]={0, 'e','e','a','a','b'};
char A[17]={0, 'a', 'c','e','b','b','c','e','e','a','a','e', 'e', 'a', 'a', 'b', 'd'};
int m=5, n=16; // P의 길이=5, A의 길이=16 

int modulo(int a, int b){ //mod 연산 함수  
	
	if (a<0)
	{
	a=a*-1;
	int i=1;
	int temp=b;
	while(1){
		b=temp*i;
		if (b>a)
			break;
		i++;	}
	
	return b-a;
	
	}
	
	else{
		
		return a%b;
	}
}

void RabinKarp(char A[], char P[], int d, int q){
	int p=0;
	int b=0;
	int k=1;
	for (int i=m;i>=1;i--){
		p=p+modulo((P[i]-97)*k, q);   //ASCII 값에 97을 빼면 a=0, b=1...로 대응된다. 
		b=b+modulo((A[i]-97)*k, q);
		k=k*d;
	}
	
	int h=modulo(pow(d, m-1), q);
	
	
	for (int i=1;i<=n-m+1;i++){
		if (i!=1)
		{
			b=modulo(d*(b-((A[i-1]-97)*h))+(A[i+m-1]-97), q);
					}
			
		if (p==b)
			{	cout << i;
		}
	}
	
}


int main(int argc, char** argv) {
	
	
	printf("매칭시작점 : "); 
	int q=113; 
	RabinKarp(A, P, 5, q);
	return 0;
}
