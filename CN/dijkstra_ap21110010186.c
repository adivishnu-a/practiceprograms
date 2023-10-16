//AP21110010186 - Adi Vishnu Avula

#include <stdio.h>
#define INFINITY 9999

void dijkstra(int graph[10][10], int n, int start) {
  int cost[10][10], distance[10], predecessor[10];
  int visited[10], count, min_distance, next_node, i, j;

  
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (graph[i][j] == 0) {
        cost[i][j] = INFINITY;
      } else {
        cost[i][j] = graph[i][j];
      }
    }
  }

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    predecessor[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    min_distance = INFINITY;

    for (i = 0; i < n; i++) {
      if (distance[i] < min_distance && !visited[i]) {
        min_distance = distance[i];
        next_node = i;
      }
    }

    visited[next_node] = 1;
    for (i = 0; i < n; i++) {
      if (!visited[i] && min_distance + cost[next_node][i] < distance[i]) {
        distance[i] = min_distance + cost[next_node][i];
        predecessor[i] = next_node;
      }
    }
    count++;
  }
  for (i = 0; i < n; i++) {
    if (i != start) {
      printf("\nDistance from source to %d: %d", i, distance[i]);
    }
  }
}

int main() {
  int graph[10][10] = {
    {0, 0, 1, 2, 0, 0, 0},
    {0, 0, 2, 0, 0, 3, 0},
    {1, 2, 0, 1, 3, 0, 0},
    {2, 0, 1, 0, 0, 0, 1},
    {0, 0, 3, 0, 0, 2, 0},
    {0, 3, 0, 0, 2, 0, 1},
    {0, 0, 0, 1, 0, 1, 0}
  };
  int n = 10;
  int u = 0;
  dijkstra(graph, n, u);
  return 0;
}
