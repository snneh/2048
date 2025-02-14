#include <bits/stdc++.h>
using namespace std;

void clearConsole() {
    std::cout << "\033[2J\033[1;1H"; 
}

void display(const vector<vector<int>> &board);

char dir;
vector<vector<int>> board(4, vector<int>(4, 0));


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
}

void generateNewPosition() {
    emptyIndices.clear();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                emptyIndices.emplace_back(i, j);
            }
        }
    }

    if (!emptyIndices.empty()) {
        uniform_int_distribution<> dis2(0, emptyIndices.size() - 1);
        EmptyCoods newCoods = emptyIndices[dis2(gen)];
        board[newCoods.x][newCoods.y] = 2;
    }
}

bool canMove() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) return true;
            if (j < 3 && board[i][j] == board[i][j + 1]) return true; // Check right
            if (i < 3 && board[i][j] == board[i + 1][j]) return true; // Check down
        }
    }
    return false;
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
    for (int i = 3; i > 0; --i) {
        if (row[i] == row[i - 1] && row[i] != 0) {
            row[i] *= 2;
            row[i - 1] = 0;
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
        case 'd':
        case 'D':
            for (auto &row : board) {
                slideright(row);
                mergeRight(row);
                slideright(row);
            }
            generateNewPosition();
            display(board);
            break;

        default:
            cout << "Invalid move! \n";
    }
}

int main() {
    clearConsole();
    newgame();

    display(board);
    while (canMove()) {
        cin >> dir;
        slide(board, dir);
    }

    cout << "Game Over!" << endl;
    return 0;
}


void clearConsole() {
    std::cout << "\033[2J\033[1;1H"; 
}

void display(const vector<vector<int>> &board);

char dir;
vector<vector<int>> board(4, vector<int>(4, 0));


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
}

void generateNewPosition() {
    emptyIndices.clear();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                emptyIndices.emplace_back(i, j);
            }
        }
    }

    if (!emptyIndices.empty()) {
        uniform_int_distribution<> dis2(0, emptyIndices.size() - 1);
        EmptyCoods newCoods = emptyIndices[dis2(gen)];
        board[newCoods.x][newCoods.y] = 2;
    }
}

bool canMove() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) return true;
            if (j < 3 && board[i][j] == board[i][j + 1]) return true; // Check right
            if (i < 3 && board[i][j] == board[i + 1][j]) return true; // Check down
        }
    }
    return false;
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
    for (int i = 3; i > 0; --i) {
        if (row[i] == row[i - 1] && row[i] != 0) {
            row[i] *= 2;
            row[i - 1] = 0;
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
        case 'd':
        case 'D':
            for (auto &row : board) {
                slideright(row);
                mergeRight(row);
                slideright(row);
            }
            generateNewPosition();
            display(board);
            break;

        default:
            cout << "Invalid move! \n";
    }
}

int main() {
    clearConsole();
    newgame();

    display(board);
    while (canMove()) {
        cin >> dir;
        slide(board, dir);
    }

    cout << "Game Over!" << endl;
    return 0;
}
