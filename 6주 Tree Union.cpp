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
	Make_Set2('m'); //°¢ ³ëµå ¸¸µé±â  
	
	Union2('a', 'b');
	Union2('h', 'c');
	Union2('b', 'c');//±×¸² 1Æ®¸® 
	
	cout<<"±×¸² Æ®¸®1 °á°ú:\n";
	cout << " aÀÇ ºÎ¸ð/·©Å©: "<<parent['a']<<"/"<<rank['a']<<'\n';
	cout <<" bÀÇ ºÎ¸ð/·©Å©: "<<parent['b']<<"/"<<rank['b']<<'\n';
	cout <<" cÀÇ ºÎ¸ð/·©Å©: "<<parent['c']<<"/"<<rank['c']<<'\n';
	cout<<" hÀÇ ºÎ¸ð/·©Å©: "<<parent['h']<<"/"<<rank['h']<<'\n';
	cout<<"\n\n";
	
	 
	Union2('d', 'e');
	Union2('k', 'f');
	Union2('m', 'f');
	Union2('f', 'e');//±×¸² 2 Æ®¸®

	cout<<"±×¸² Æ®¸®2 °á°ú:\n"; 
	cout<<" dÀÇ ºÎ¸ð/·©Å©: "<<parent['d']<<"/"<<rank['d']<<'\n';
	cout<<" eÀÇ ºÎ¸ð/·©Å©: "<<parent['e']<<"/"<<rank['e']<<'\n';
	cout<<" fÀÇ ºÎ¸ð/·©Å©: "<<parent['f']<<"/"<<rank['f']<<'\n';
	cout<<" kÀÇ ºÎ¸ð/·©Å©: "<<parent['k']<<"/"<<rank['k']<<'\n';
	cout<<" mÀÇ ºÎ¸ð/·©Å©: "<<parent['m']<<"/"<<rank['m']<<'\n';
	cout<<"\n\n";

	Union2('c', 'e'); //µÎ °³ ÇÕº´  
	cout<<"Union(c, e) °á°ú\n";
	cout << " aÀÇ ºÎ¸ð/·©Å©: "<<parent['a']<<"/"<<rank['a']<<'\n';
	cout <<" bÀÇ ºÎ¸ð/·©Å©: "<<parent['b']<<"/"<<rank['b']<<'\n';
	cout <<" cÀÇ ºÎ¸ð/·©Å©: "<<parent['c']<<"/"<<rank['c']<<'\n';
	cout<<" hÀÇ ºÎ¸ð/·©Å©: "<<parent['h']<<"/"<<rank['h']<<'\n'; 
	cout<<" dÀÇ ºÎ¸ð/·©Å©: "<<parent['d']<<"/"<<rank['d']<<'\n';
	cout<<" eÀÇ ºÎ¸ð/·©Å©: "<<parent['e']<<"/"<<rank['e']<<'\n';
	cout<<" fÀÇ ºÎ¸ð/·©Å©: "<<parent['f']<<"/"<<rank['f']<<'\n';
	cout<<" kÀÇ ºÎ¸ð/·©Å©: "<<parent['k']<<"/"<<rank['k']<<'\n';
	cout<<" mÀÇ ºÎ¸ð/·©Å©: "<<parent['m']<<"/"<<rank['m']<<'\n';

	return 0;
}
