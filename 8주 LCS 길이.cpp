#include <bits/stdc++.h>
using namespace std; 

string xm="abcbdabc";
string ym="bdcabac";

int c[9][8]; //이차원 배열 c 생성  

int LCS(int m, int n){ //lcs알고리즘  
	for (int i=0;i<=m;i++){
		c[0][i]=0;
	}
	for (int j=1;j<=n;j++){
		c[j][0]=0;
	}   //각 첫번째 행, 열 0으로 지정  
	
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			if (xm[i-1]==ym[j-1])	//string xm ym의 0번째문자부터 시작  
				c[i][j]=c[i-1][j-1]+1;
			
			else
				c[i][j]=max(c[i-1][j], c[i][j-1]);
		
		}
	}
	
		return c[m][n];
	
}


int main(int argc, char** argv) {
	int answer;
	answer=LCS(8, 7);
	
	cout <<"c배열 출력\n"; 
	for (int i=0;i<=8;i++){
		for (int j=0;j<=7;j++){
			printf("%d	", c[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	cout <<"최종 LCS 길이: "<< answer;
	

	return 0;
}
