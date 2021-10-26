#include <iostream>
#include<math.h>
using namespace std;
int C[20][20];
int det = 0;    // global olarak determinant degiskenimizi olusturduk

int determinant( int matrix[20][20], int n) // determinantı hesaplamak icin fonksiyon olusturduk
{
   int submatrix[20][20];
   if (n == 2)
   return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else {
      for (int x = 0; x < n; x++) {
         int subi = 0;
         for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
               if (j == x)
               continue;
               submatrix[subi][subj] = matrix[i][j];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));// determinant hesaplamak icin recursive fonksiyon kullandik
      }
   }
   return det;
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

void newMatrix(int A[20][20])        // matrix tree icin yeni matrisimizi burada olusturacagiz
{
    for(int i = 0; i < 20; i++ )
        {
            for(int j = 0; j < 20; j++ )
            {
                if(i == j)
                {
                    C[i][j] = degree(i,A);  // eger matrisin i ve j seklinde matris boyutu esit ise o dugumun derecesine esit olacaktir
                }
                else
                {
                    C[i][j] = (-1) * A[i][j];   // eger i ve j birbirine esit degilse -1 kati kadar olacaktir yeni matris degerimiz
                }
            }
        }
    for(int i = 0; i < 20; i++ )
        {
            for(int j = 0; j < 20; j++ )
            {
                cout<<C[i][j]<<"  ";
            }
            cout<<endl;
        }


   cout <<" Yayilim Agaci Sayisi: "<< determinant(C,20);

}


int main()
{

    int komsuluk_matrisi[20][20] = {        //komsuluk matrisimizi tanimladik
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

    newMatrix(komsuluk_matrisi);    //matrix tree teoreminde yeni matris olusturmak icin fonksiyonumuzu cagirdik


    return 0 ;
}
