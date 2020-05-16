#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void mergeSort(int[], int, int);
void merge(int[], int, int, int);

static int n;

int main(int argc, char *argv[]) {
	int k;
	scanf("%d", &n);
	int list[n];
	for (k=0;k<n;k++){
		list[k]=rand()%1000;
		printf("%d ", list[k]);
	}
	printf("\n");
	
	mergeSort(list, 0, n-1);
	
	for (k=0;k<n;k++){
		printf("%d ", list[k]);
		}
		
	return 0;
}

void merge(int a[], int p, int q, int r){
	int tmp[n];
	int i, j, t;
	i = p;
	j = q+1;
	t = 1;
	while(i<=q && j<=r){
		if (a[i]<=a[j])
			tmp[t++] = a[i++];
		else
			tmp[t++]=a[j++];
	}
	
	while(i<=q)
		tmp[t++]=a[i++];
	while(j<=r)
		tmp[t++]=a[j++];
	i=p;
	t=1;
	while (i<=r)
		a[i++]=tmp[t++];
}

void mergeSort(int a[], int p, int r){
	if (p<r){
		int q=(p+r)/2;
		mergeSort(a, p, q);
		mergeSort(a, q+1, r);
		merge(a, p, q, r);
	
	}
}
