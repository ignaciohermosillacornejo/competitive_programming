#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, n) for(int i = a; i < n; i++)
#define eb emplace_back


int main()
{
    ll d,m,d1,n,d2;
    cin >> d >> m >> d1 >> n >> d2;
    
    ll friend_counter = 0;

    while(true)
    {
        // si es que recibio el libro
        if (d <= 0)
        {
            cout << friend_counter << "\n";
            break;
        }
        // si es que no quedan amigos para buscar el libro
        if (m == 0 && n == 0)
        {
            cout << "-1\n";
            break;
        }
        // si es que ninguno de los amigos que quedan me puede llegar al libro
        if ( (m > 0 && d1 <= d) || (m == 0 and d2 <= d) )
        {
            cout << "-1\n";
            break;
        }
        // acercamos el libro 
        if (m > 0)
        {
            d -= (d1 - d);
            m--;
            friend_counter++;
        }
        else
        {
            d -= (d2 - d);
            n--;
            friend_counter++;
        }
    }
}