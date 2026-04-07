#include <iostream>
#include <vector>

using namespace std;

int board[8][8];

// ฟังก์ชันสำหรับเช็คว่าตำแหน่ง (row, col) ปลอดภัยหรือไม่
bool isSafe(int row, int col) {
    // เช็คแนวตั้ง (Column)
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    // เช็คแนวทแยงซ้ายบน
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // เช็คแนวทแยงขวาบน
    for (int i = row, j = col; i >= 0 && j < 8; i--, j++)
        if (board[i][j]) return false;

    return true;
}

// ฟังก์ชัน Backtracking เพื่อวางราชินีทีละแถว
bool solve(int row) {
    if (row >= 8) return true; // วางครบ 8 ตัวแล้ว

    for (int col = 0; col < 8; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1; // วางราชินี

            if (solve(row + 1)) return true; // ไปแถวถัดไป

            board[row][col] = 0; // ถ้าไปต่อไม่ได้ ให้หยิบออก (Backtrack)
        }
    }
    return false;
}

int main() {
    if (solve(0)) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}