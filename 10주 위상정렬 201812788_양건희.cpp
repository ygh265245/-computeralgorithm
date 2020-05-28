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
	
	// ��������Ʈ ���� 
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
	graph[0].name="���� 1"; 
	graph[1].name="���α׷��� 1";
	graph[2].name="�̻� ����";
	graph[3].name="�ڷ� ����";
	graph[4].name="���� 2";
	graph[5].name="���� ���";
	graph[6].name="��ġ �ؼ�";
	graph[7].name="�˰��� �м�";
	graph[8].name="�������";
	graph[9].name="� ü��" ;
	graph[10].name="���α׷��� ����";
	graph[11].name="�����Ϸ� ����";
	graph[12].name="�ΰ� ����";
	graph[13].name="����̷�";
	graph[14].name="���� �˰���";
	
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
	n15.ver=14;    //��������Ʈ �����Ϸ�
	
	cout<<"�������ļ���\n";
	topSort1(graph, 15);
	
	return 0;
}
