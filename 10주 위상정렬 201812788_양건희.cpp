#include <bits/stdc++.h>
using namespace std; 



struct node {
	int ver;
	node* link; 
};

struct g{
	int count;
	string name;
	node* link;
};

struct g graph[15];
struct node n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16;


void topSort1(struct g graph[], int n){
	int top=-1;
	struct node *ptr;
	for (int i=0;i<n;i++){
		
		if (!graph[i].count){
			graph[i].count=top;
			top=i;
		}
		
		for (int k=0;k<n;k++){
			
			if (top==-1) {			
				break;
			}
		
			else{
				
				int j=top;
				top=graph[top].count;
				
				printf("C%d	", j);
				cout<<graph[j].name;
				printf("\n");
				
				for (ptr=graph[j].link;ptr; ptr=ptr->link){
					
					int k=ptr->ver;
					graph[k].count--;
					if (!graph[k].count)
						{
							graph[k].count=top;
							top=k;
						}
				
				}
				
			}
		}

	
	}
	
}

int main(int argc, char** argv) {
	
	// 인접리스트 생성 
	graph[0].count=0;
	graph[1].count=0;
	graph[2].count=0;
	graph[3].count=2;
	graph[4].count=1;
	graph[5].count=1;
	graph[6].count=1;
	graph[7].count=2;
	graph[8].count=1;
	graph[9].count=2;
	graph[10].count=1;
	graph[11].count=1;
	graph[12].count=1;
	graph[13].count=1;
	graph[14].count=1;   
	graph[0].name="수학 1"; 
	graph[1].name="프로그래밍 1";
	graph[2].name="이산 수학";
	graph[3].name="자료 구조";
	graph[4].name="수학 2";
	graph[5].name="선형 대수";
	graph[6].name="수치 해석";
	graph[7].name="알고리즘 분석";
	graph[8].name="어셈블리어";
	graph[9].name="운영 체제" ;
	graph[10].name="프로그래밍 언어론";
	graph[11].name="컴파일러 설계";
	graph[12].name="인공 지능";
	graph[13].name="계산이론";
	graph[14].name="병렬 알고리즘";
	
	graph[0].link=&n1;
	n1.ver=4;
	graph[1].link=&n2;
	n2.ver=3;
	graph[2].link=&n3;
	n3.ver=3;
	graph[3].link=&n4;
	n4.ver=7;
	n4.link=&n5;
	n5.ver=8;
	graph[4].link=&n6;
	n6.ver=5;
	graph[5].link=&n7;
	n7.ver=6;
	n7.link=&n8;
	n8.ver=7;
	graph[7].link=&n9;
	n9.ver=9;
	n9.link=&n10;
	n10.ver=10;
	n10.link=&n11;
	n11.ver=12;
	n11.link=&n12;
	n12.ver=13;
	graph[8].link=&n13;
	n13.ver=9;
	graph[10].link=&n14;
	n14.ver=11;
	graph[13].link=&n15;
	n15.ver=14;    //인접리스트 생성완료
	
	cout<<"위상정렬순서\n";
	topSort1(graph, 15);
	
	return 0;
}
