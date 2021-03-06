// Kod kismindaki gerekli ' /* */ ' seklindeki yorum satirlarini kaldirirsaniz grafin en kisa yollarini da gorebilirsiniz
#include <iostream>
#include <math.h>
#define INF 999
using namespace std;

int cost[20][20] ;
bool newVisited[20][20]={false};
int sayac = 0; // bu kod uzerinde sayacimiz kac kisa yol oldugunu tutmaktadir.
int kisayol[20] = {0}; // her dugum kac kisa yol uzerinde bulundugunu bir dizide tutuyoruz.
// baslangic icin butun dugumlerin betweenness degeri 0 olacaktir. Eger uc dugum degilse asagidaki kodda
// kac kisayol uzerinde oldugunu bu dizide tutuyoruz.

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

/*                    cout <<src<<"-"<<i<<"\t\t\t"<< dist[i]<<"\t\t\t"<<" ";
                    cout << i << " ";           */
                    int parnode = parent[i];
                    newVisited[src][i] = true;
                    newVisited[i][src] = true;
                    while(parnode != src)
                    {
                        if (src != parnode && i != parnode)//eger kisayol rotasi uzerindeki dugum, kaynak yada hedef degilse
                        {                               //bir betweenness degerine sahiptir.
                            kisayol[parnode] = kisayol[parnode] + 1;
                        }
/*                        cout << " <- " << parnode << " "; */
                        parnode = parent[parnode];

                    }
/*                    cout<<"<- "<<src<<endl;
                    cout<<endl;         */
                    sayac = sayac + 1;
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
            0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0 // 0. d??g??m
        },
        {
            1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0 // 1. dugum
        },
        {
            0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0 // 2. d??????m
        },
        {
            0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0 // 3. d??????m
        },
        {
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0 // 4. d??????m
        },
        {
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0 // 5. d??????m
        },
        {
            0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0 // 6. d??????m
        },
        {
            0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0 // 7. d??????m
        },
        {
            0,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,0,0,0,0 // 8. d??????m
        },
        {
            0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0 // 9. d??????m
        },
        {
            0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0 // 10. d??????m
        },
        {
            0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0 // 11. d??????m
        },
        {
            0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0 // 12. d??????m
        },
        {
            0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1 // 13. d??????m
        },
        {
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0 // 14. d??????m
        },
        {
            1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0 // 15. d??????m
        },
        {
            0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0 // 16. d??????m
        },
        {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0 // 17. d??????m
        },
        {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1 // 18. d??????m
        },
        {
            0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 // 19. d??????m
        }


        };

/*    cout<< "Kaynak-Hedef \t\tMesafe \t\t\t Rota\n"<<endl;     */
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

/*    for(int i = 0; i < 20; i++)
    {
        cout<<i<<". dugum ka?? kisa yol uzerindedir? = "<<kisayol[i]<<endl;
    }
*/


    cout<< " Dugum \t\t Aradalik Degeri\n "<<endl;
    for(int i = 0; i < 20; i++)
    {
        float btw = (float)kisayol[i]/(float)sayac;
        cout<<"   "<<i<<" \t\t "<<btw<<endl;
    }

    return 0;

}
