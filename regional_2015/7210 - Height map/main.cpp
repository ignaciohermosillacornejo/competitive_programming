// 7210 - Height Map
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=702&page=show_problem&problem=5222
#include <bits/stdc++.h>

int R; // number of rows in the matrix
int C; // number of columns in the matrix
int counter;
int matrix[100][100];
bool visited[100][100];

void NtoS(){
    // We go from north to south counting row by row the adjacent
    int p_low, p_height, c_height, c_low;
    for (int r = 1; r < R; r++){ // We skip the first row (we can just add one face) and the last row
        p_low = p_height = 0; // We must do this at the beginning of each row / col so that if the first row / col is
        // exposed, then it passes the second condition
        for (int c = 0; c < C; c++){
            c_height = matrix[r][c];
            c_low = matrix[r - 1][c];
            // If the face is exposed and it is not a continuation of the previous face, then we increase the counter
            if (c_height > c_low and not(p_height > p_low and std::min(c_height, p_height) > std::max(c_low, p_low))) counter++;
            p_height = c_height;
            p_low = c_low;
        }
    }
}

void StoN(){
    int p_low, p_height, c_height, c_low;
    for (int r = R - 2; r >= 0; r--){
        p_low = p_height = 0;
        for (int c = 0; c < C; c++){
            c_height = matrix[r][c];
            c_low = matrix[r + 1][c];
            if (c_height > c_low and not(p_height > p_low and std::min(c_height, p_height) > std::max(c_low, p_low))) counter++;
            p_height = c_height;
            p_low = c_low;
        }
    }
}

void WtoE(){
    int p_low, p_height, c_height, c_low;
    for (int c = 1; c < C; c++){
        p_low = p_height = 0;
        for (int r = 0; r < R; r++){
            c_height = matrix[r][c];
            c_low = matrix[r][c - 1];
            if (c_height > c_low and not(p_height > p_low and std::min(c_height, p_height) > std::max(c_low, p_low))) counter++;
            p_height = c_height;
            p_low = c_low;
        }
    }
}

void EtoW(){
    int p_low, p_height, c_height, c_low;
    for (int c = C -2; c >= 0; c--){
        p_low = p_height = 0;
        for (int r = 0; r < R; r++){
            c_height = matrix[r][c];
            c_low = matrix[r][c + 1];
            if (c_height > c_low and not(p_height > p_low and std::min(c_height, p_height) > std::max(c_low, p_low))) counter++;
            p_height = c_height;
            p_low = c_low;
        }
    }
}

void BFS(int r, int c){

    std::list< std::pair< int, int > > queue;

    auto c_node = std::make_pair(r, c);
    visited[c_node.first][c_node.second] = true;
    queue.push_back(c_node);

    std::pair< int, int> directions[4] = {std::make_pair(0, 1), std::make_pair(-1, 0),
                                          std::make_pair(0, -1), std::make_pair(1, 0)};

    while(not queue.empty()){

        c_node = queue.front();
        queue.pop_front();

        for (auto & direction: directions){
            auto p_node = std::make_pair(c_node.first + direction.first, c_node.second + direction.second);
            // We check to see if we are in the bounds of the matrix
            if (p_node.first < 0 or p_node.first > R - 1 or p_node.second < 0 or p_node.second > C - 1) continue;
            if (not visited[p_node.first][p_node.second]
                and matrix[p_node.first][p_node.second] == matrix[c_node.first][c_node.second]) {
                visited[p_node.first][p_node.second] = true;
                queue.push_back(p_node);
            }
        }
    }
}

int main() {

    std::ios::sync_with_stdio(false); // makes cin/cout as fast as fscan and printf

    while (std::cin >> R >> C){

        memset(visited, false, sizeof visited);

        counter = 5;

        for (int r = 0; r < R; r++){
            copy_n(std::istream_iterator< int >(std::cin), C, matrix[r]);
        }

        //std::cout << "starting: " << counter << "\n";

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++){
                if (not visited[r][c]) {
                    counter++;
                    BFS(r, c);
                }
            }
        }

        //std::cout << "Upper face: " << counter << "\n";

        NtoS();

        //std::cout << "NtoS: " << counter << "\n";

        StoN();

        //std::cout << "StoN: " << counter << "\n";

        WtoE();

        //std::cout << "WtoE: " << counter << "\n";

        EtoW();

        //std::cout << "EtoW: " << counter << "\n";

        std::cout << counter << "\n";

    }

    return 0;
}