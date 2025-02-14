#include <bits/stdc++.h>
using namespace std;

void clearConsole() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape code to clear screen and move cursor to top-left
}

void display(const vector<vector<int>> &board);
void updateValidPositions();

char dir;
vector<vector<int>> board(4, vector<int>(4, 0));
vector<vector<bool>> validMoves(4, vector<bool>(4, true));

mt19937 gen(static_cast<unsigned>(time(nullptr)));
uniform_int_distribution<> dis1(0, 15);

class EmptyCoods {
public: 
    int x;
    int y;

    EmptyCoods(int x, int y) {
        this->x = x;
        this->y = y;
    }

};

vector<EmptyCoods> emptyIndices;

void newgame() {
    int random_index1 = dis1(gen);
    int random_index2;

    do {
        random_index2 = dis1(gen);
    } while (random_index1 == random_index2);

    int x1 = random_index1 / 4, y1 = random_index1 % 4;
    int x2 = random_index2 / 4, y2 = random_index2 % 4;

    board[x1][y1] = 2;
    board[x2][y2] = 2;

    validMoves[x1][y1] = false;
    validMoves[x2][y2] = false;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (validMoves[i][j]) {
                EmptyCoods validCoods(i, j);
                emptyIndices.push_back(validCoods);
            }
        }
    }

}

void updateValidPositions(){
    emptyIndices.clear();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                EmptyCoods validCoods(i, j);
                emptyIndices.push_back(validCoods);
            }
        }
    }
}

void generateNewPosition(){
    uniform_int_distribution<> dis2(0, emptyIndices.size() - 1);
    int index = dis2(gen);
    EmptyCoods newCoods = emptyIndices[index];
    board[newCoods.x][newCoods.y] = 2;

}

bool canMove() {
    return !emptyIndices.empty();
}

void display(const vector<vector<int>> &board) {
    for (const auto &eachrow : board) {
        for (auto element : eachrow) {
            cout << element << " ";
        }
        cout << endl;
    }
}


void mergeRight(vector<int> &row) {
    for (int i=3; i>0; --i) {
        if (row[i] == row[i-1]) {
            row[i] = 2 * row[i];
            row[i-1] = 0;
        }
    }
}


void slideright(vector<int> &row) {
    int n = count(row.begin(), row.end(), 0);
    vector<int> modified(n, 0);
    for (int i = 0; i < row.size(); i++) {
        if (row[i] != 0) {
            modified.push_back(row[i]);
        }
    }
    row = modified;
}


void slide(vector<vector<int>> &board, char ch) {
    switch (ch) {
        case 'a':
        case 'A':
            break;

        case 'd':
        case 'D':
            for (auto &row : board) {
                slideright(row);
                mergeRight(row);
            }
            break;

        default:
            cout << "Invalid move! \n";
    }
}

int main() {
    clearConsole();
    newgame();


    uniform_int_distribution<> dis2(0, emptyIndices.size() - 1);

    display(board);
    while (canMove()) {
        cin >> dir;
        slide(board, dir);
        updateValidPositions();
        generateNewPosition();
        display(board);
    }

    
    return 0;
}
