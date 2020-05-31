#include <bits/stdc++.h>
using namespace std;

#define INF 9999 //무한을 표현하기 위해 간선 중 가장 큰 간선인 25보다 큰 수를 INF로 정의하였다. 


int cost[8][8]={
	
		{0, 18, 7, 1, INF, INF, INF, INF},
		{INF, 0, INF, INF, INF, INF, 10, INF},
		{INF, 9, 0, 3, INF, INF, 21, INF},
		{INF, INF, INF, 0, 2, 25, INF, INF},
		{INF, INF, 3, INF, 0, INF, INF, 15},
		{INF, INF, INF, INF, 7, 0, INF, INF},
		{INF, INF, INF, INF, INF, INF, 0, 2},
		{INF, INF, INF, INF, INF, 4, INF, 0}
	
};  //그래프의 cost 자료구조 정의  

int dist[8];
bool found[8];


int extractMin(int dist[], int n, bool found[]){
	
	int min=INF, minpos=0;
	
	for (int i=0;i<n;i++){
		if (!found[i] && dist[i]<min){
			min=dist[i];
			minpos=i;
		}
	}

	return minpos;
}

void Dijkstra(int v, int dist[], int n, bool found[]){
	for (int i=0;i<n;i++){
		dist[i]=cost[v][i];
	}
	found[v]=true;
	
	for (int i=0;i<n-2;i++){
		int u=extractMin(dist, n, found);	
		found[u]=true;
		for (int w=0;w<n;w++){
			if (!found[w]){
			
				if (dist[w]> dist[u]+cost[u][w])
						dist[w]=dist[u]+cost[u][w];
					}
		}
	}
	
}

int main(int argc, char** argv) {
	

	Dijkstra(0, dist, 8, found);
	
	for (int i=0;i<8;i++)
		printf("0부터 %d까지의 최단경로 : %d\n", i, dist[i]);
		
	return 0;
}
