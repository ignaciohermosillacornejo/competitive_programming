// Domino Art
// tags: BFS, Bicoloration, Max flow (dinic flow)
// https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=2012
#include <bits/stdc++.h>

const int MAX_SIZE = 2;
const int MAX_GRAPH_SIZE = 6; // MAX_SIZE^2 + 2


char board[MAX_SIZE][MAX_SIZE]; // = {{'E','E','E','E','E','E','E','E','E'}};
int graph[MAX_GRAPH_SIZE][MAX_GRAPH_SIZE];
int rGraph[MAX_GRAPH_SIZE][MAX_GRAPH_SIZE];
int parent[MAX_GRAPH_SIZE];
int row_size, col_size;
bool visited[MAX_SIZE][MAX_SIZE]; // starting value is false

void printMap(){
    for (int r = 0; r < MAX_SIZE; r++) {
        for (int c = 0; c < MAX_SIZE; c++) std::cout << board[r][c] << " ";
        std::cout << "\n";
    }
}

void readMap(){
    memset(board, 'E', sizeof board);
    std::cin >> row_size >> col_size;
    for (int r = 0; r < row_size; r++){
        copy_n(std::istream_iterator< char >(std::cin), col_size, board[r]);
    }
}

void printGraph(){
    for (int r = 0; r < MAX_GRAPH_SIZE; r++) {
        for (int c = 0; c < MAX_GRAPH_SIZE; c++) std::cout << rGraph[r][c] << " ";
        std::cout << "\n";
    } std::cout << "\n";
}

bool bfs(int s, int t){
    bool visited[MAX_GRAPH_SIZE];
    memset(visited, int(false), sizeof visited);

    std::queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v = 0; v < MAX_GRAPH_SIZE; v++){
            if (not visited[v] and rGraph[u][v] > 0){
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

bool fordFulkenson(int s, int t, int expected_flow){ // s = 4, t = 5, exp = 1

    memset(visited, 0, sizeof visited);

    int u,v;

    for (u = 0; u < MAX_GRAPH_SIZE; u++)
        for (v = 0; v < MAX_GRAPH_SIZE; v++)
            rGraph[u][v] = graph[u][v];

    int max_flow = 0;

    while(bfs(s, t)){

        printGraph();

        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]){
            u = parent[v];
            path_flow = std::min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]){
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow == expected_flow;
}

bool biColor(int r, int c){
    /* We start coloring a patch and constructing the graph for it
     * implementation from: http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
     * TODO: construct graph
     * */
    char color[2] = {'R','B'}; // coloring array used to switch between the two colors
    // used to iterate when expanding a node
    std::pair< int, int> directions[4] = {std::make_pair(0, 1), std::make_pair(-1, 0),
                                          std::make_pair(0, -1), std::make_pair(1, 0)};
    int counter[2] = {0,0}; // we keep track of how many R and B squares we paint

    memset(visited, 0, sizeof visited);

    std::list <std::pair <int,int> > queue;

    auto c_node = std::make_pair(c, r);
    visited[c_node.first][c_node.second] = true;
    queue.push_back(c_node);

    while (!queue.empty()) {
        // Dequeue the node to expand
        c_node = queue.front();
        queue.pop_front();

        int c_color = (c_node.first + c_node.second)%2;
        int c_node_number = c_node.first * MAX_SIZE + c_node.second;

        if (board[c_node.first][c_node.second] == '#') { // This only happens on the first node of the patch
            board[c_node.first][c_node.second] = color[c_color^1]; // c_color must be inverted
            counter[c_color^1]++;
            graph[MAX_GRAPH_SIZE - 2][c_node_number] = 1;
        }

        for (auto & direction: directions){
            auto p_node = std::make_pair(c_node.first + direction.first, c_node.second + direction.second);
            // We skip if we run out of the bounds of the table
            if (p_node.first < 0 or p_node.first > row_size or p_node.second < 0 or p_node.second > row_size) continue;

            if (board[p_node.first][p_node.second] == '#') {
                board[p_node.first][p_node.second] = color[c_color];

                int p_node_number = p_node.first * MAX_SIZE + p_node.second;
                graph[c_node_number][p_node_number] = 1; // we add the edge to our graph for max flow problem

                // TODO: if R, s->r if B b->t
                if (bool(c_color)){
                    graph[p_node_number][MAX_GRAPH_SIZE - 2] = 1;
                } else {
                    graph[p_node_number][MAX_GRAPH_SIZE - 1] = 1;
                }

                if (not visited[p_node.first][p_node.second]) {
                    visited[p_node.first][p_node.second] = true;
                    queue.push_back(p_node);
                    counter[c_color]++;
                }
            }
        }
    }

    if (counter[0] != counter[1]) return false; // R and B tiles must be equal


    return fordFulkenson(MAX_GRAPH_SIZE - 2, MAX_GRAPH_SIZE - 1, counter[0]);

}

void searchPatches(){
    for (int r = 0; r < MAX_SIZE; r++) {
        for (int c = 0; c < MAX_SIZE; c++){
            if (board[r][c] == '#'){
                if (not bool(biColor(r, c))) {
                    std::cout << "Impossible";
                    return;
                }
            }
        }
    }
    std::cout << "Possible";

}

int main() {
    readMap();
    searchPatches();
    //printMap();
    return 0;
}