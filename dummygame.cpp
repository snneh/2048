#include <bits/stdc++.h>
using namespace std;

void clearConsole() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape code to clear screen and move cursor to top-left
}

void display(const vector<vector<int>> &board);

char dir;
vector<vector<int>> board(4, vector<int>(4, 0));
vector<vector<bool>> validMoves(4, vector<bool>(4, true));
vector<int> emptyIndices;

mt19937 gen(static_cast<unsigned>(time(nullptr)));
uniform_int_distribution<> dis1(0, 15);



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

}

void generateNewTile(){

}

bool canMove() {
    emptyIndices.clear(); 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (validMoves[i][j]) {
                emptyIndices.push_back(i * 4 + j + 1);
            }
        }
    }

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

void slideleft(vector<vector<int>> &board) {
    
}

void slideright(vector<vector<int>> &board) {
    for (auto &row : board) {
        int n = count(row.begin(), row.end(), 0);
        vector<int> modified(n, 0);
        for (int i = 0; i < row.size(); i++) {
            if (row[i] != 0) {
                modified.push_back(row[i]);
            }
        }
        row = modified;
    }

    

    if (!emptyIndices.empty()) {
        uniform_int_distribution<> dis2(0, emptyIndices.size() - 1);
        int newIndex = dis2(gen);
        board[newIndex / 4][newIndex % 4] = 2;
    }
    
}

void slide(vector<vector<int>> &board, char ch) {
    switch (ch) {
        case 'a':
        case 'A':
            slideleft(board);
            display(board);
            break;

        case 'd':
        case 'D':
            slideright(board);
            display(board);
            break;

        default:
            cout << "Invalid move! \n";
    }
}

int main() {
    clearConsole();
    newgame();

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (validMoves[i][j]) {
                emptyIndices.push_back(i * 4 + j + 1);
            }
        }
    }
    uniform_int_distribution<> dis2(0, emptyIndices.size() - 1);

    display(board);
    while (canMove()) {
        cin >> dir;
        slide(board, dir);
    }

    
    return 0;
}
