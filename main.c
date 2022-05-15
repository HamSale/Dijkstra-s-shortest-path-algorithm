#include <stdio.h>
#include <stdlib.h>

#define VERTICE 6   //노드의 수
#define INF 10000   //연결이 없는 경우를 위한 무한대
#define TRUE 1
#define FALSE 0

int distance[VERTICE];  //거리(weight)를 나타냄
int found[VERTICE];     //방문한 노드를 가리킴

int g[VERTICE][VERTICE] = {     //전체 그래프를 인접행렬 형식으로 초기화
    {0, 5, INF, 2, 4, INF}, 
    {5, 0, 3, 3, INF, INF}, 
    {INF, 3, 0, 3, 4, 2}, 
    {2, 3, 3, 0, 1, INF}, 
    {4, INF, 4, 1, 0, 2}, 
    {INF, INF, 2, INF, 2, 0}
};

int shortest(int distance[], int n, int found[])    //가장 최소 거리를 가지는 노드를 반환함
{
    int min;
    int index;

    min = INF;
    index = -1;

    for(int i=0; i<n; i++)
    {
        if(distance[i] < min && found[i] == FALSE)
        {
            min = distance[i];
            index = i;
        }
    }

    return index;
}

void dijkstra_shortest_path(int start, int n)   //다익스트라 최단경로 알고리즘
{
    for(int i=0; i<n; i++)      //시작 노드에서 다른 노드로 향하는 가중치를 기준으로 초기화
    {
        distance[i] = g[start][i];
        found[i] = FALSE;
    }
    found[start] = TRUE;

    for(int i=0; i<n-1; i++)
    {
        int shor = shortest(distance, n, found);    //시작 노드와의 최단 거리인 노드를 반환
        found[shor] = TRUE;     //해당 노드를 그래프에 포함
        printf("%d is added to Graph\n\n", shor);   //해당 노드가 그래프에 포함된 것을 출력

        for(int j=0; j<n; j++)
        {
            if(found[j] == FALSE)
            {
                if(distance[shor] + g[shor][j] < distance[j])   //시작 노드에서 j로 가는게 빠를지, shor을 거쳐서 가는게 빠를지 판단
                {
                    printf("Before distance [%d] to distance[%d] = %d\n", shor, j, distance[j]);
                    distance[j] = distance[shor] + g[shor][j];
                    printf("After distance [%d] to distance[%d] = %d\n\n", shor, j, distance[j]);
                }
            }
        }
    }
}

int main(void)
{
    printf("Vertices order is 0~%d\n\n", VERTICE - 1);  //노드가 [0~노드수-1] 까지로 나오는 것을 알림

    dijkstra_shortest_path(0, VERTICE);     //0번 노드부터 시작함

    return 0;
}
