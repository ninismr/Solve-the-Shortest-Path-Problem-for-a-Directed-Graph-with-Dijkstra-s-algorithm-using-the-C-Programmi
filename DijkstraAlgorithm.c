#include<stdio.h>
#include<stdbool.h>
#define inf 9999

int n;
int table[100][100];

int dijkstra(int start, int end) {
    int dist[n];
    bool visited[n];
    int x, y, v;

    //initialization of dist[x] = infinite
    for(x=1; x<=n; x++) {
        dist[x] = inf;
    }

    //initialization of visited[x] = false
    for(x=1; x<=n; x++) {
        visited[x] = false;
    }

dist[start] = 0;
while(true) {
    //this loop will end with break
    int u = 0;
    int minDist = inf;
    //look for nodes that have not been visited and have the minimum distance
    for(x=1; x<=n; x++) {
        if((visited[x] == false) && (dist[x]<minDist)) {
            u = x;
            minDist = dist[x];
        }
    }
    
    //to end the while loop
    if((u == 0) || (dist[u] == inf)) {
        break;
    }

    visited[u] = true;
    //do relax for all u's neighbors
    for(v=1; v<=n; v++) {
        if(table[u][v] != 0) {
            if(dist[v] > dist[u] + table[u][v]) {
                dist[v] = dist[u] + table[u][v];
            }
        }
    }
}

//returns the shortest distance of the two nodes
return dist[end];
}

int main() {
    int start, end;
    int x, y;
    
    //based on the case study, number of nodes = 7
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the node distance in a matrix form:\n");

    //let's say the distance from 1 to 2 is 3
    //means table[1][2] = 3 or table[2][1] = 3
    //if there is no distance between the two nodes can be filled with 0
    for(x=1; x<=n; x++) {
        for(y=1; y<=n; y++) {
            scanf("%d", &table[x][y]);
        }
    }

int answer = 0, a;

//use looping so that it can be tested again
while(answer == 0) {
    printf("Enter the start node: ");
    scanf("%d", &start);
    printf("Enter the end node: ");
    scanf("%d", &end);

    //using Dijkstra function
    printf("The shortest distance from node %d to %d: %d\n", start, end, dijkstra(start, end));

    repeat:
    printf("\nDo you want to try again? (y/n): ");
    scanf(" %s", &a);
    if(a == 'y' || a == 'Y') {
        answer = 0;
    }
    else if(a == 'n' || a == 'N') {
        printf("Thank you and have a nice day!");
        answer = 1;
    }
    else {
        printf("Incorrect input! please enter y or n!");
        goto repeat;
    }
} 

return 0;
}
