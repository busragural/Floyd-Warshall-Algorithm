#include<stdio.h>

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int floyds(int dist[10][10], int n){
	
	int i,j,k, count = 0;
	
	for(k=1; k<=n; k++){
		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++){
				
				count ++;
				
				if(i == j){
					dist[i][j] = 0;
				}
				else{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
	printf("\n\n****TIME COMPLEXITY: %d\n\n", count);
	return count;
}

int main(){
	
	int dist[10][10];
	int i,j,k;
	int node, path, start, end, distance;
	
	
		printf("\n****** FLOYD - WARSHALL ******");
		
		printf("\n\nEnter the number of nodes: ");
		scanf("%d", &node);
		
		printf("\nEnter the number of paths: ");
		scanf("%d", &path);
		
		
		for(i=1; i<=node; i++){
			for(j=1; j<=node; j++){
				
				if(i != j){
					dist[i][j] = 999;
				}
				else{
					dist[i][j] = 0;
				}
			}
		}
		
	
	printf("\nEnter the start and end node, then the distance between the nodes, respectively");
	
	for(i=1; i<=path; i++){
		
		printf("\n\n%d. distance\n", i);
		
		printf("Start: ");
		scanf("%d", &start);
		
		printf("End: ");
		scanf("%d", &end);
		
		printf("Distance: ");
		scanf("%d", &distance);
		
		dist[start][end] = distance;
		
		
	}
	printf("\n\nINPUT: \n");
	
	
	for(i=1; i<=node; i++){
		for(j=1; j<=node; j++){
			printf("%d\t", dist[i][j]);
		}
		printf("\n");
	}
	
	floyds(dist, node);
	
	printf("\nTHE SHORTEST PATH MATRIX \n");
	
	for(i=1; i<=node; i++){
		for(j=1; j<=node; j++){
			printf("%d\t", dist[i][j]);
		}
		printf("\n");
	}
	
	printf("\nTHE SHORTEST WAYS \n");
	
	for(i=1; i<=node; i++){
		for(j=1; j<=node; j++){
			
			if(i != j){
				printf("\n <%d, %d> ->>> %d", i,j,dist[i][j]);
			}
		}
	}
	
	
	return 0;	
}
