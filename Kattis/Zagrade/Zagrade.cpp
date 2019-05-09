/*
Problem: https://open.kattis.com/problems/zagrade
Tags: DFS, Backtracking
Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> wgraph;

#ifndef declaraciones_h
#define declaraciones_h

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define umap unordered_map
#define uset unordered_set

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl
#define debugm(m)                                        \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m)                                                         \
    cerr << #m << endl;                                                    \
    rep(i, (int)m.size())                                                  \
    {                                                                      \
        cerr << i << ":";                                                  \
        rep(j, (int)m[i].size())                                           \
        {                                                                  \
            cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        }                                                                  \
        cerr << endl;                                                      \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

#endif

unordered_set<string> answers;
/* Idea general para resolver mediante recursión 
 * las unicas opciones que tenemos para operar sobre la expresión es quitar parejas de paréntesis válidos
 * por lo tanto primero, para una expresión dada, tenemos que elegir un par de parentesis, quitarlos y hacer una llamada recursiva
 */

void solver(string expression)
{
    //si ya tenemos un elemento en el set, podemos podar esta rama y retornar
    if (answers.find(expression) != answers.end())
        return;

    //si la expresion no existia, la anadimos. Esto nos anade la expresion que es el input por lo que
    // vamos a tener que quitarla mas tarde
    answers.insert(expression);

    // Lo primero a hacer es ver donde están los pares de paréntesis y guardarlos en una lista de pares
    stack<int> index;
    vector<ii> parentesis;
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '(')
            index.push(i);
        else if (expression[i] == ')')
        {
            parentesis.emplace_back(index.top(), i); // guardamos el indice de ( y de )
            index.pop();
        }
    }

    // para cada paréntesis, queremos sacarlo y hacer una llamada recursiva
    for (int i = 0; i < parentesis.size(); i++)
    {
        string temp = expression;
        temp.erase(temp.begin() + parentesis[i].first);
        temp.erase(temp.begin() + parentesis[i].second - 1); // restamos 1 pq ya eliminamos un caracter que venía antes
        solver(temp);
    }
}

int main()
{
    // leemos el input
    string expression;
    cin >> expression;

    // generamos todas las posibles soluciones
    solver(expression);

    // copiamos las soluciones a un vector que lo ordemanos en orden lexicografico y le quitamos el primer elemento
    // el primer elemento es el input y no tiene que ir en la solución
    vector<string> print_answers;
    print_answers.insert(print_answers.end(), answers.begin(), answers.end());
    sort(print_answers.begin(), print_answers.end());
    print_answers.erase(print_answers.begin());

    // imprimimos las solucion
    for (auto &i : print_answers)
    {
        cout << i << "\n";
    }

    return 0;
}