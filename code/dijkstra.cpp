#include <iostream>
#define INF 999
using namespace std;

int cost[20][20] ;
bool newVisited[20][20]={false};


int getNearest(int dist[], bool visited[]){
    int minvalue = INF ;
    int minnode = 0;
    for(int i = 0; i < 20; i++)
    {
        if(!visited[i] && dist[i]<minvalue)
        {
            minvalue = dist[i];
            minnode = i;
        }
    }
    return minnode;

}

void dijkstra(int src){

    int dist[20] = {0};
    int parent[20] = {0};
    bool visited[20] = {false};
    for(int i=0 ; i < 20; i++)
    {
        parent[i] = i;
        dist[i] = INF;

    }
    dist[src] = 0;


    for(int i=0; i < 20 ; i++)
    {
        int nearest = getNearest(dist,visited);
        visited[nearest] = true;
        for(int adj = 0; adj < 20; adj++)
        {
            if(cost[nearest][adj] != INF && dist[adj] > dist[nearest] + cost[nearest][adj]  )
            {
                dist[adj] = dist[nearest]+cost[nearest][adj];
                parent[adj] = nearest;

            }
        }
    }


    for(int i = 0; i < 20; i++)
    {

            if(newVisited[src][i] != true )
            {
                if (src != i )
                    {
                    cout <<src<<"-"<<i<<"\t\t\t"<< dist[i]<<"\t\t\t"<<" ";
                    cout << i << " ";
                    int parnode = parent[i];
                    newVisited[src][i] = true;
                    newVisited[i][src] = true;
                    while(parnode != src)
                    {
                        cout << " <- " << parnode << " ";
                        parnode = parent[parnode];
                    }
                    cout<<"<- "<<src<<endl;
                    cout<<endl;
                    }
                    else
                        newVisited[src][i] = true;
                        newVisited[i][src] = true;

                }
            }

}



int main()
{
    int komsuluk_matrisi[20][20] = {
        {
            0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0 // 0. dügüm
        },
        {
            1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0 // 1. dugum
        },
        {
            0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0 // 2. düðüm
        },
        {
            0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0 // 3. düðüm
        },
        {
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0 // 4. düðüm
        },
        {
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0 // 5. düðüm
        },
        {
            0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0 // 6. düðüm
        },
        {
            0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0 // 7. düðüm
        },
        {
            0,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,0,0,0,0 // 8. düðüm
        },
        {
            0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0 // 9. düðüm
        },
        {
            0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0 // 10. düðüm
        },
        {
            0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0 // 11. düðüm
        },
        {
            0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0 // 12. düðüm
        },
        {
            0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1 // 13. düðüm
        },
        {
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0 // 14. düðüm
        },
        {
            1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0 // 15. düðüm
        },
        {
            0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0 // 16. düðüm
        },
        {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0 // 17. düðüm
        },
        {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1 // 18. düðüm
        },
        {
            0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 // 19. düðüm
        }


        };

    cout<< "Kaynak-Hedef \t\tMesafe \t\t\t Rota\n"<<endl;
    for (int i = 0; i < 20; i++)
    {
        for(int j = 0; j<20; j++)
        {
            if(komsuluk_matrisi[i][j] == 0)
            {
                cost[i][j] = INF;
            }
            else
            {
                cost[i][j] = komsuluk_matrisi[i][j];
            }
        }
    }

    for(int i = 0; i < 20; i++)
    {
        dijkstra(i);
    }

    cout<< "Kaynak-Hedef \t\tMesafe \t\t\t Rota\n"<<endl;
    cout<<"Odevde butun dugum ciftleri arasinda en kisa yollar hesaplanmis olup ilgili 0-19 bulunduktan sonra \n 19-0 hesaba katilmamistir. Saygilarimla"<<endl;
    return 0;
}
