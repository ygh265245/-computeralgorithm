#include <bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int ip[4][9];
int w[5][9];
int peb[5][9];
int n=8; //3*8 테이블 

int pebble(int n){
	
	for (int p=1; p<=4;p++)
		peb[p][1]=w[p][1];  //peb 첫 열 지정  
	
		
	for(int i=2;i<=n;i++){
		
		for (int p=1;p<=4;p++){
			
			if (p==1)
				peb[p][i]=max(peb[2][i-1]+w[p][i], peb[3][i-1]+w[p][i]);// 패턴p 1일떄 이전 열 패턴  2, 3 비교    
				
			else if (p==3)
				
				peb[p][i]=max(peb[1][i-1]+w[p][i], peb[2][i-1]+w[p][i]);//패턴 p 3일때 이전 열 패턴 1, 2 비교   
			
			else if (p==4) 
					peb[p][i]=peb[2][i-1]+w[p][i]; //패턴 p 4일 때 이전 열 패턴 2  비교   
		
			else if (p==2)
				{	int maxnum=0;
					if (peb[1][i-1]>maxnum)
					maxnum=peb[1][i-1];
					if (peb[3][i-1]>maxnum)
					maxnum=peb[3][i-1];
					if (peb[4][i-1]>maxnum)
					maxnum=peb[4][i-1];
					peb[p][i]=maxnum+w[p][i]; // 패턴 p 2 일 때 이전 열 패턴 1, 3, 4 비교  
					
					}	
			
		}
	}
	
	int num=0;
	
	for (int i=1;i<=4;i++){
		if (num<peb[i][8])
		num=peb[i][8];    //peb 끝 열에서 가장 큰 수를 찾는다  
	}
	return num;
} 

int main(int argc, char** argv) {
	
	ip[1][1]=-6; //Input table  
	ip[1][2]=7;
	ip[1][3]=12;
	ip[1][4]=-5;
	ip[1][5]=5;
	ip[1][6]=3;
	ip[1][7]=11;
	ip[1][8]=3;
	ip[2][1]=8;
	ip[2][2]=10;
	ip[2][3]=14;
	ip[2][4]=9;
	ip[2][5]=7;
	ip[2][6]=13;
	ip[2][7]=8;
	ip[2][8]=5;
	ip[3][1]=15;
	ip[3][2]=12;
	ip[3][3]=7;
	ip[3][4]=4;
	ip[3][5]=8;
	ip[3][6]=-2;
	ip[3][7]=9;
	ip[3][8]=4;

	for (int i=1; i<=4;i++)
		for (int a=1; a<=8; a++)
			w[i][a]=ip[i][a];	  	
	for (int i=1;i<9;i++)
		w[4][i]=ip[1][i]+ip[3][i];  //배열 w를 만든다.
		 
	
	cout <<"최대값: "<< pebble(n)<<"\n\n"; //pebble 함수 시행
	
	cout <<"w 결과table\n"; // w 출력  
	for (int i=1; i<=4;i++){
	
		for (int a=1; a<=8; a++)
			cout << w[i][a]<<"	";
		
		cout<<'\n';}
	cout<<"\n\n";  
	
	cout<<"peb 결과table\n"; //peb 출력  
	for (int i=1; i<=4;i++){
	
		for (int a=1; a<=8; a++)
			cout << peb[i][a]<<"	";
		
		cout<<'\n';}
	
	
	
	return 0;
}
