#include <bits/stdc++.h>
using namespace std; 

char parent[15];
int rank[15];

void Make_Set2(char x){
	parent[x]=x;
	rank[x]=0;
}

char Find_Set(char x){
	if (x==parent[x]) return x;
	else{
		return parent[x]=Find_Set(parent[x]);
	}
}

void Union2(char x, char y){
	char xparent=Find_Set(x);
	char yparent=Find_Set(y);
	

	
	if (rank[xparent] > rank[yparent])  
			parent[yparent]=xparent;
			
	else{
		parent[xparent]=yparent;
		if (rank[xparent]==rank[yparent])
			rank[yparent]++;
	}
	

	
}


int main(int argc, char** argv[]) {
	
	 
	Make_Set2('a');
	Make_Set2('b');
	Make_Set2('c');
	Make_Set2('d');
	Make_Set2('e');
	Make_Set2('f');
	Make_Set2('g');
	Make_Set2('h');
	Make_Set2('k');
	Make_Set2('m'); //�� ��� �����  
	
	Union2('a', 'b');
	Union2('h', 'c');
	Union2('b', 'c');//�׸� 1Ʈ�� 
	
	cout<<"�׸� Ʈ��1 ���:\n";
	cout << " a�� �θ�/��ũ: "<<parent['a']<<"/"<<rank['a']<<'\n';
	cout <<" b�� �θ�/��ũ: "<<parent['b']<<"/"<<rank['b']<<'\n';
	cout <<" c�� �θ�/��ũ: "<<parent['c']<<"/"<<rank['c']<<'\n';
	cout<<" h�� �θ�/��ũ: "<<parent['h']<<"/"<<rank['h']<<'\n';
	cout<<"\n\n";
	
	 
	Union2('d', 'e');
	Union2('k', 'f');
	Union2('m', 'f');
	Union2('f', 'e');//�׸� 2 Ʈ��

	cout<<"�׸� Ʈ��2 ���:\n"; 
	cout<<" d�� �θ�/��ũ: "<<parent['d']<<"/"<<rank['d']<<'\n';
	cout<<" e�� �θ�/��ũ: "<<parent['e']<<"/"<<rank['e']<<'\n';
	cout<<" f�� �θ�/��ũ: "<<parent['f']<<"/"<<rank['f']<<'\n';
	cout<<" k�� �θ�/��ũ: "<<parent['k']<<"/"<<rank['k']<<'\n';
	cout<<" m�� �θ�/��ũ: "<<parent['m']<<"/"<<rank['m']<<'\n';
	cout<<"\n\n";

	Union2('c', 'e'); //�� �� �պ�  
	cout<<"Union(c, e) ���\n";
	cout << " a�� �θ�/��ũ: "<<parent['a']<<"/"<<rank['a']<<'\n';
	cout <<" b�� �θ�/��ũ: "<<parent['b']<<"/"<<rank['b']<<'\n';
	cout <<" c�� �θ�/��ũ: "<<parent['c']<<"/"<<rank['c']<<'\n';
	cout<<" h�� �θ�/��ũ: "<<parent['h']<<"/"<<rank['h']<<'\n'; 
	cout<<" d�� �θ�/��ũ: "<<parent['d']<<"/"<<rank['d']<<'\n';
	cout<<" e�� �θ�/��ũ: "<<parent['e']<<"/"<<rank['e']<<'\n';
	cout<<" f�� �θ�/��ũ: "<<parent['f']<<"/"<<rank['f']<<'\n';
	cout<<" k�� �θ�/��ũ: "<<parent['k']<<"/"<<rank['k']<<'\n';
	cout<<" m�� �θ�/��ũ: "<<parent['m']<<"/"<<rank['m']<<'\n';

	return 0;
}
