#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ฟังก์ชัน Backtracking สำหรับสร้างวงเล็บ
void generateParenthesis(vector<string>& result, string current, int open, int close, int n) {

    // กรณีฐาน: เมื่อความยาวของ string ครบ 2*n (หมายความว่าครบทุกคู่แล้ว)
    cout << current << endl;
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    // เงื่อนไข 1: เติมวงเล็บเปิด '(' ได้ถ้าจำนวนที่เปิดไปยังไม่ครบ N
    if (open < n) {
        generateParenthesis(result, current + "(", open + 1, close, n);
    }

    // เงื่อนไข 2: เติมวงเล็บปิด ')' ได้ถ้าจำนวนที่ปิดยังน้อยกว่าจำนวนที่เปิดอยู่ (Well-formed)
    if (close < open) {
        generateParenthesis(result, current + ")", open, close + 1, n);
    }
}

int main() {
    int n;
    cout << "กรุณาใส่จำนวนคู่ (N): ";
    cin >> n;

    vector<string> result;
    generateParenthesis(result, "", 0, 0, n);

    cout << "รูปแบบวงเล็บที่ดีทั้งหมดสำหรับ " << n << " คู่ มีดังนี้:" << endl;
    for (const string& s : result) {
        cout << s << endl;
    }
    
    cout << "รวมทั้งหมด: " << result.size() << " รูปแบบ" << endl;

    return 0;
}