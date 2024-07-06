#include <iostream>
#include <vector>
using namespace std;

bool isAllowed(int maze[][4], int row, int col, int newi, int newj, vector<vector<bool>> &visited) {
    // It is ony allowed to visit a location, if:
    // i)   location to be visited is not out of bound
    // ii)  it's allowed to visit that particular location in the maze, i.e path is open, i.e. 1
    // iii) the location to be visited is marked 'not visited' i.e. 'false' in 'visited' array'
    if((newi>=0 && newi<row) && (newj>=0 && newj<col)
        && (maze[newi][newj] == 1)
        && (visited[newi][newj] == false)) {
            return true;
    } else {
        return false;
    }
}

void printAllPath(int maze[][4], int row, int col, int i, int j, string &output, vector<vector<bool>> &visited) {
    // base case
    if(i==row-1 && j==col-1) {   // maze[row-1][col-1] is the destination
        cout << output << endl;
        return;
    }

    // The rat can either move up, right, down or left. So we will visit all directions.
    // UP
    int newi = i - 1;
    int newj = j;
    if(isAllowed(maze, row, col, newi, newj, visited)) {
        output.push_back('U');
        visited[newi][newj] = true;   // the location (newi, newj) will be visited now,
                                     // so we are marking visited[newi][newj] as true
        printAllPath(maze, row, col, newi, newj, output, visited);   // recursive call to find next location
        visited[newi][newj] = false;   // backtracking, i.e. marking the location (newi, newj) as false
                                      // so that it can be visited in further operations
        output.pop_back();   // clearing out the character 'U' from 'output' string
    }

    // RIGHT
    newi = i;
    newj = j + 1;
    if(isAllowed(maze, row, col, newi, newj, visited)) {
        output.push_back('R');
        visited[newi][newj] = true;   // the location (newi, newj) will be visited now,
                                     // so we are marking visited[newi][newj] as true
        printAllPath(maze, row, col, newi, newj, output, visited);   // recursive call to find next location
        visited[newi][newj] = false;   // backtracking, i.e. marking the location (newi, newj) as false
                                      // so that it can be visited in further operations
        output.pop_back();   // clearing out the character 'U' from 'output' string
    }

    // DOWN
    newi = i + 1;
    newj = j;
    if(isAllowed(maze, row, col, newi, newj, visited)) {
        output.push_back('D');
        visited[newi][newj] = true;   // the location (newi, newj) will be visited now,
                                     // so we are marking visited[newi][newj] as true
        printAllPath(maze, row, col, newi, newj, output, visited);   // recursive call to find next location
        visited[newi][newj] = false;   // backtracking, i.e. marking the location (newi, newj) as false
                                      // so that it can be visited in further operations
        output.pop_back();   // clearing out the character 'U' from 'output' string
    }

    // LEFT
    newi = i;
    newj = j - 1;
    if(isAllowed(maze, row, col, newi, newj, visited)) {
        output.push_back('L');
        visited[newi][newj] = true;   // the location (newi, newj) will be visited now,
                                     // so we are marking visited[newi][newj] as true
        printAllPath(maze, row, col, newi, newj, output, visited);   // recursive call to find next location
        visited[newi][newj] = false;   // backtracking, i.e. marking the location (newi, newj) as false
                                      // so that it can be visited in further operations
        output.pop_back();   // clearing out the character 'U' from 'output' string
    }
}

int main() {
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1}
    };
    int row = 4;
    int col = 4;

    int i = 0;   // 'i' will represent row number
    int j = 0;   // 'j' will represent column number

    string output = " ";

    // creating a 2D vector to keep track of locations that has already been visited
    vector <vector<bool>> visited(row, vector<bool>(col, false));

    if(maze[0][0] == 0) {   // if source is closed, rat cannot move
        cout << "No path exists" << endl;
    } else {
        // if source is open, i.e. first element of 'maze' array is 1. In this case, rat can move;
        // which means it has already visited maze[0][0], thus we are marking visited[0][0] as true.
        visited[0][0] = true;  
        printAllPath(maze, row, col, i, j, output, visited);
    }

    return 0;
}
