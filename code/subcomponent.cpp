#include <iostream>

using namespace std;
int a = 1;                      // hangi bileşende olduğumu belirlemek için global bir değişken tanımladım.
void DFS(int komsuluk_matrisi[][20], bool ziyaret_edilen[20], int baslangic_dugum)
    {
        cout<<baslangic_dugum<<"  ";
        ziyaret_edilen[baslangic_dugum]=true;

        for(int i=0 ; i<20 ; i++)
        {
            if(i == baslangic_dugum)                // düğümlerin kendine yolları olmadığından 0 olacaktır bu yüzden continue
            {
                continue;
            }
            if(komsuluk_matrisi[baslangic_dugum][i] == 1)
            {
                if(ziyaret_edilen[i])               // düğümler ziyaret edildiyse tekrar ziyaret edilmeyecektir.
                {
                    continue;
                }

                DFS(komsuluk_matrisi,ziyaret_edilen,i); // DFS algoritması ile başladığımız düğümlerin bütün komşularını yani
                                                            // alt bileşenlerimizi buluyoruz.
            }
        }
    }

int main()
{
    bool ziyaret_edilen[20] = {false};              // gidilen düğümler için bir dizi oluşturdum
    int komsuluk_matrisi[20][20] = {                // kendi çizdiğim matrisin komşuluk matrisini oluşturdum
        {
            0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0 // 0. düğüm
        },
        {
            0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0 // 1. düğüm
        },
        {
            1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0 // 2. düğüm
        },
        {
            0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 // 3. düğüm
        },
        {
            0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 // 4. düğüm
        },
        {
            0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0 // 5. düğüm
        },
        {
            0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0 // 6. düğüm
        },
        {
            0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0 // 7. düğüm
        },
        {
            0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0 // 8. düğüm
        },
        {
            0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0 // 9. düğüm
        },
        {
            0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0 // 10. düğüm
        },
        {
            1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0 // 11. düğüm
        },
        {
            1,0,1,1,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,1 // 12. düğüm
        },
        {
            0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0 // 13. düğüm
        },
        {
            0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0 // 14. düğüm
        },
        {
            0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0 // 15. düğüm
        },
        {
            0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0 // 16. düğüm
        },
        {
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0 // 17. düğüm
        },
        {
            0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 // 18. düğüm
        },
        {
            0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0 // 19. düğüm
        }


        };

    cout<<"Alt Bilesen \t\t Dugumler\n\n";          // başlık kısmımız
    for(int i=0 ; i<20 ; i++)                       // void fonksiyonunda recursive fonksiyon kullandığım için alt bileşenleri
    {                                                    // buradan kontrol etmek için döngü oluşturdum
       if(ziyaret_edilen[i]==false)
       {
           cout<<a<<". bilesen \t\t ";              //global değişkenimi hangi bileşende olduğumu yazdırmak için kullandım.
           DFS(komsuluk_matrisi,ziyaret_edilen,i);  // alt bileşenleri ve komşularını belirlemek için DFS fonksiyonu kullandım.
           cout<<"\n";
           a++;                                     // sonraki bileşen için değişkenimi bir arttırdım

       }
    }
    return 0;
}
