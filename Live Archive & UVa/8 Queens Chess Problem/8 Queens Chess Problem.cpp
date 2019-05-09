/*
Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3359
Tags: Backtracking
Stauts: Solved
*/

#include <bits/stdc++.h>

using namespace std;

// donde vamos a guardar la solución actual. En C++ para declarar una lista tenemos que declarar entre los < > el tipo de datos que queremos guardar
vector<int> solution;

// lista de todas las soluciones, las iremos guardando acá para despues ordenarlas e imprimirlas para cada caso
// noten que el tipo de dato que guarda el vector es otro vector de ints.
// tenemos que acordarnos de vaciar esta lista despues de cada caso de prueba
vector<vector<int>> all_solutions;

// funcion que me dice si es seguro poner la reina en la fila row y columna col
// funciona de la siguiente forma: para la fila row y columna col, reviso en varias
// direcciones para asegurarme de que no haya ninguna otra reina ahí
bool is_safe(int pos, int value)
{
    // solo necesito revisar las siguientes direcciones:
    // arr izq, izq, abj izq, der, arr der y abj der. No necesito revisar arriba y abajo
    // ya que nunca voy a estar en la situación de poner dos reinas en la misma columna
    // ya que las pongo de izq a der y saltandome la columna donde la reina ya esta puesta

    // arriba a la izquierda
    for (int row = value, col = pos; row >= 0 && col >= 0; row--, col--)
    {
        if (solution[col] == row)
        {
            return false;
        }
    }
    // izquierda
    for (int col = pos; col >= 0; col--)
    {
        if (solution[col] == value)
        {
            return false;
        }
    }
    // abajo a la izquierda
    for (int row = value, col = pos; row < 8 && col >= 0; row++, col--)
    {
        if (solution[col] == row)
        {
            return false;
        }
    }
    // arriba a la derecha
    for (int row = value, col = pos; row >= 0 && col < 8; row--, col++)
    {
        if (solution[col] == row)
        {
            return false;
        }
    }
    // derecha
    for (int col = pos; col < 8; col++)
    {
        if (solution[col] == value)
        {
            return false;
        }
    }
    // abajo a la derecha
    for (int row = value, col = pos; row < 8 && col < 8; row++, col++)
    {
        if (solution[col] == row)
        {
            return false;
        }
    }
    return true;
}

// para esta ejercicio imprimir el output puede parecer un poco complicado, pero es asi por que hay muchos casos bordes
// que revisasr
void print_solutions(int t)
{
    // hay un salto de linea entre cada uno de los casos de ejemplo. Este if los imprime para todos excepto el primero (que no tiene un caso antes que el)
    if (t > 0)
    {
        cout << "\n";
    }
    cout << "SOLN       COLUMN\n";
    cout << " #      1 2 3 4 5 6 7 8\n\n";
    // para cada solucion dentro de todas las soluciones posibles para este caso de prueba...
    for (int n = 0; n < all_solutions.size(); n++)
    {
        // primero imprimimos el indice, noten que si es un digito tenemos que poner un espacio antes
        if (n < 9)
        {
            cout << " " << n + 1 << "      ";
        }
        // si es un numero con dos digitos, no tenemos que poner el espacio antes
        else
        {
            cout << n + 1 << "      ";
        }
        // para cada digito dentro de esta solucion...
        for (int i = 0; i < 8; i++)
        {
            // imprimirmos el digito + 1, ya que nuestros valores van de 0 a 7, pero la solucion nos las piden del 1 al 8
            cout << all_solutions[n][i] + 1;
            // hay un espacio entre cada digito, excepto el ultimo
            if (i < 7)
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

// metodo recursivo donde implementamos el backtrack, los metodos en c++ declaran el tipo que retorna
// row y col es la fila columna donde se encuentra la reina fija, que no podemos mover
void solver(int row, int col, int pos)
{
    // en caso que la posición del dominio sea donde tenemos a la reina fija, nos saltamos esa columna
    if (pos == col)
    {
        pos = pos + 1;
    }
    // en caso que hayamos encontrado una solución, la guardamos en la lista de las soluciones
    if (pos == 8)
    {
        all_solutions.push_back(solution);
        return;
    }

    // iteramos sobre todos los valores en que podemos asignar a esa posición
    for (int value = 0; value < 8; value++)
    {
        // revisamos que la asignación que pretendemos hacer es valida
        if (is_safe(pos, value))
        {
            // hacemos la asignacion
            solution[pos] = value;

            // hacemos la llamada recursiva a la siguiente posicion del dominio
            solver(row, col, pos + 1);

            // deshacemos la asignación
            solution[pos] = -1;
        }
    }
    return;
}

int main()
{
    int T;                      // declaramos un numero T que representa el numero de casos de prueba
    cin >> T;                   // leemos del input el numero T
    for (int i = 0; i < T; i++) // para cada caso, encontramos todas las soluciones
    {
        // declaro dos numeros, para guardar la fila/columna donde me dicen que esta la reina
        // noten que puedo declarar varias variables del mismo tipo en una linea usando la coma.
        // equivalente a:
        // int row;
        // int col;
        int row, col;
        // leemos del input el row y col:
        // equivalente a:
        // cin >> row;
        // cin >> col;
        cin >> row >> col;
        // le restamos 1 a la fila y columna, ya que nuestros indices parten desde 0 en las filas y columnas
        row--;
        col--;
        // llenamos nuestra solución con -1 para indicar que nada esta asignado
        solution.assign(8, -1);
        // pre-marcamos donde se encontrará la reina
        solution[col] = row;
        // llamamos a nuestro solver para que busque por backtracking las soluciones
        solver(row, col, 0);
        // imprimimos todas las soluciones en orden lexicográfico
        print_solutions(i);
        // borramos la lista donde guardamos todas las soluciones para este caso de prueba, cosa que sirva para el próximo caso de prueba
        all_solutions.clear();
    }
}