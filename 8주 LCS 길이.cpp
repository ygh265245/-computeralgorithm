#include <bits/stdc++.h>
using namespace std; 

string xm="abcbdabc";
string ym="bdcabac";

int c[9][8]; //������ �迭 c ����  

int LCS(int m, int n){ //lcs�˰���  
	for (int i=0;i<=m;i++){
		c[0][i]=0;
	}
	for (int j=1;j<=n;j++){
		c[j][0]=0;
	}   //�� ù��° ��, �� 0���� ����  
	
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			if (xm[i-1]==ym[j-1])	//string xm ym�� 0��°���ں��� ����  
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
	
	cout <<"c�迭 ���\n"; 
	for (int i=0;i<=8;i++){
		for (int j=0;j<=7;j++){
			printf("%d	", c[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	cout <<"���� LCS ����: "<< answer;
	

	return 0;
}
