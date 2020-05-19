#include <bits/stdc++.h>
using namespace std;

vector <int> graph[9];
bool visit[9]={false,};
pair<int, int> edge[8];
int j;


void dfs(int v){
	visit[v]=true;
	printf("%d ", v);
	for (int i=0;i<graph[v].size();i++){
		int next=graph[v][i];
		
		if (!visit[next])
		{
			j++;
			edge[j].first=v;
			edge[j].second=next; //방문 엣지 순서 생성 
		  dfs(next);
	}
	}
	}
	
int main(int argc, char** argv) {

	
		
		graph[1].push_back(2);
		graph[1].push_back(6);
		graph[1].push_back(8);
		graph[2].push_back(1);
		graph[2].push_back(3);
		graph[2].push_back(5);
		graph[2].push_back(6);
		graph[3].push_back(2);
		graph[3].push_back(4);
		graph[3].push_back(5);
		graph[4].push_back(3);
		graph[4].push_back(5);
		graph[5].push_back(2);
		graph[5].push_back(3);
		graph[5].push_back(4);
		graph[6].push_back(1);
		graph[6].push_back(2);
		graph[6].push_back(7);
		graph[6].push_back(8);
		graph[7].push_back(6);
		graph[8].push_back(1);
		graph[8].push_back(6); //인접리스트 생성  
		
		printf("방문 순서 : ");
		dfs(1);
		printf("\n");
		printf("방문한 간선 순서: ");
		for (int i=1;i<8;i++)
		 printf("%d-%d ", edge[i].first, edge[i].second); 
		
	return 0;
}
