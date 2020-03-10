#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

#define MAX 100
#define INF 0x3f3f3f3f
struct MGraph
{
	int edges[MAX][MAX];
	int n, e;
}G;

int path[MAX][MAX];

void init() {
	memset(G.edges, INF, sizeof(G.edges));
	for (int i = 0; i < MAX; i++) {
		G.edges[i][i] = 0;
	}
}
void insert(int u, int v, int w) {
	G.edges[u][v] = w;//
}

void Floyd(MGraph G, int path[][MAX]) {
	int i, j, k;
	int A[MAX][MAX];
	for (i = 0; i < G.n; i++) {
		for (j = 0; j < G.n; j++) {
			A[i][j] = G.edges[i][j];
			path[i][j] = -1;
		}
	}
	for (k = 0; k < G.n; k++) { 
		for (i = 0; i < G.n; i++) {
			for (j = 0; j < G.n; j++) {
				if (A[i][j] > A[i][k] + A[k][j]) { 
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = k;
				}
			}
		}
	}
		for (i = 0; i < G.n; i++) { 
			for (j = 0; j < G.n; j++) {
				if(j!=G.n-1)
					cout << A[i][j]<<" ";
				else
					cout << A[i][j] << endl;
				}
			}
}


int main() {
	init();
	int n, m;//n¸öµã£¬mÌõ±ß
	int a, x, y, w;
	cin >> m >> n;
	G.e = m;
	G.n = n;

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		insert(x, y, w);
	}
	Floyd(G, path);
	return 0;
}