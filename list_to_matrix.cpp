#include <bits/stdc++.h>

std::vector<int> adjList[10000]; // Input list
int noOfEdges;
int noOfVertices;
int adjMatrix[10000][10000]; // Resultant weighted matrix

void getInput() {
    std::cout << "Enter number of vertices: ";
	std::cin >> noOfVertices;
	std::cout << "Enter number of edges: ";
	std::cin >> noOfEdges;
	std::cout << "Enter edge followed by weight: \n";
	int weight;
	int x;
	int y;
	for(int i = 0; i < noOfEdges; i++) {
		std::cin >> x >> y >> weight;
		adjList[i].push_back(x);
		adjList[i].push_back(y);
		adjList[i].push_back(weight);
	}
}

// Function to convert the given weighted adjacency list to a weighted adjacency matrix
// Useful for Floyd-Warshall algorithm
void listToMatrix() {
	sort(adjList, adjList + noOfEdges);	 // The adjacency list is sorted so that the matrix is filled correctly in order
	for(int i = 0; i < noOfVertices; i++) {
	    int k = 0;
		for(int j = 0; j < noOfVertices; j++) {
			if(i == j) {
				adjMatrix[i][j] = 0;		// Distance from a vertex to itself is 0
			}
			else if(k < noOfEdges and adjList[k][0] == i and adjList[k][1] == j) {
				adjMatrix[i][j] = adjList[k][2];
				k++;
			}
			else {
				adjMatrix[i][j] = INT_MAX;	// If no connection exists between two vertices, mark as INFINITY
			}
		}
	}
	std::cout << std::endl;
}

void printMatrix() {
	for(int i = 0; i < noOfVertices; i++) {
		for(int j = 0; j < noOfVertices; j++) {
		    if(adjMatrix[i][j] == INT_MAX)
			    std::cout << "INF" << "   ";
			else
			    std::cout << adjMatrix[i][j] << "     ";
		}
		std::cout << std::endl;
	}
}

int main() {
	getInput();
	listToMatrix();
	printMatrix();
}

//Test case
//5 7 0 1 1 0 2 7 1 2 5 1 3 4 3 4 2 1 4 3 2 4 6
