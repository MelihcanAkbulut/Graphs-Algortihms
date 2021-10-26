#include <iostream>
#include<set>
using namespace std;
int edgeCount = 0;
int count1Degree = 0;
int komsuluk_matrisi[20][20];
int visitedN[20][20]={false};

// Grafi kontrol icin sirasiyla kolaydan zor olan isleme dogru sirasiyla islem yapilmistir.
// 1 - Kenar sayisi dugum sayisinin 1 eksigi kadardir.
// 2 - Bir agac icin en az 2 uc dugum olmasi gerekir.
// 3 - Döngü barindirmamasi gerekmektedir.
// bütün algoritma ve kodlari calisiyordur.

void countEdges(int src,int matrix[20][20]) // grafimizin kenar sayisi icin yazdigimiz fonksiyon
{
    for(int i = 0; i < 20; i++)
    {
        if(visitedN[src][i] != false )
            {
                if(src != i)
                {
                    if(matrix[src][i] != 0)
                    {
                        visitedN[src][i] = true;
                        visitedN[i][src] = true;
                        edgeCount = edgeCount + 1;
                    }
                }
            }
        else
        {
            visitedN[src][i] = true;
            visitedN[i][src] = true;
        }
    }
}

bool dfs(int vertex, set<int>&visited, int parent)
{
   visited.insert(vertex);
   for(int v = 0; v < 20; v++)
    {
      if(komsuluk_matrisi[vertex][v])
      {
         if(v == parent)
            continue;
         if(visited.find(v) != visited.end())
            return true;
         if(dfs(v, visited, vertex))
            return true;
      }
   }
   return false;
}

bool detectCycle()     // cycle tespiti icin yazilan fonksiyon
{
   set<int> visited;
   for(int v = 0; v < 20; v++)
    {
      if(visited.find(v) != visited.end())
         continue;
      if(dfs(v, visited, -1))
      {
         return true;
      }
    }
   return false;
}

int degree(int vertex, int A[20][20]) // dugumun derecesini bulmaya yarayan fonksiyonumuz
{
    int deg = 0;
    for(int i = 0; i < 20; i++)
    {
        if( A[vertex][i] == 1 )
            deg = deg + 1;
    }
    return deg;
}


int main()
{
    int dugumSayisi = 20;
    int degrees[20];
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


    for(int i = 0; i < 4; i++)      // verilen grafin agac olma durumu icin 3 özellik kontrol ettirdim 4 olma durumu agac olma durumudur.
    {                               // bu yüzden for döngüsü icine switch case yapisi kurdum
        switch(i)                   // eger bir tane olmama durumu tespit edilirse döngü son bulur
        {

        case 1:             // Bir agac icin ; kenar sayisinin bir fazlasi kadar dügüm vardir.
            {
                for(int i = 0; i < 20; i++)
                    {
                        countEdges(i,komsuluk_matrisi);
                    }

                    if (edgeCount + 1 != dugumSayisi )
                    {
                        cout<<"Verilen graf bir agac degildir. ||G|| + 1 = |G| sarti saglanmamaktadir. Kenar sayisi cok fazladir."<<endl;
                    }
                break;

            }

        case 2:     // Bir agac icin en az 2 uc dugum vardir.
            {
                for(int i = 0; i < 20; i++ )
                {
                    degrees[i] = degree(i,komsuluk_matrisi);
                    if(degrees[i]==1)
                    {
                        count1Degree = count1Degree + 1;
                    }
                }

                if(count1Degree < 2)
                {
                    cout<<"Verilen graf bir agac degildir. Cünkü en az 2 uc dugum yoktur."<<endl;
                }
                break;
            }

        case 3:     // Bir grafin agac olmasi icin döngü barindirmamasi lazım
            {
                bool result;
                result = detectCycle();
                if(result)
                {
                    cout <<"Verilen graf bir agac degildir. Cünkü döngü tespit edildi." << endl;
                }

                break;
            }
        case 4:     // Grafin agac olma durumu
            cout<<"Verilen graf bir agactir";
                break;
        }
    }

    return 0;
}




