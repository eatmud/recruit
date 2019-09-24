#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
struct GRAPH {
    vector<int> vexs;
    vector<vector<int>> matrix;
    int vexNUm;
    int edgNum;
};
void Dijstra(GRAPH graph, int start)
{
    vector<int> pre(graph.edgNum, 0);
    vector<int> dist(graph.edgNum, 0);
    vector<bool> flag(graph.vexNUm, 0);
    int minDist;
    int i;
    int j;
    int k;
    for (i = 0; i < graph.vexNUm; ++i) {
        dist[i] = graph.matrix[start][i];
    }
    flag[start] = 1;
    dist[start] = 0;
    for (i = 1; i < graph.vexNUm; ++i) {
        minDist = INT_MAX;
        for (j = 0; j < graph.vexNUm; ++j) {
            if (flag[j] == 0 && dist[j] < minDist) {
                minDist = dist[j];
                k = j;
            }
        }
        flag[k] = 1;
        for (j = 0; j < graph.vexNUm; ++j) {
            int temp = (graph.matrix[k][j] == INT_MAX) ? INT_MAX : (minDist + graph.matrix[k][j]);
            if (flag[j] == 0 && (temp < dist[j])) {
                dist[j] = temp;
                pre[j] = k;
            }
        }
    }

}
