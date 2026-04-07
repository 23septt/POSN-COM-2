#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;
long long dist[305][305];

int main() {
    int N;
    cin >> N;

    // 1. รับข้อมูล Input และตั้งค่าเริ่มต้น
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> dist[i][j];
            if (i != j && dist[i][j] == 0) dist[i][j] = INF; // กรณีไม่มีเส้นทาง (ถ้าโจทย์ไม่ได้การันตี)
        }
    }

    // 2. Floyd-Warshall เพื่อหาระยะสั้นที่สุดทุกคู่
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    long long min_of_max = INF;

    // 3. หาคนที่เป็นจุดเริ่มต้นที่ดีที่สุด (ทวนคำสั่งได้เร็วที่สุดในเคสที่แย่ที่สุด)
    for (int i = 1; i <= N; i++) {
        long long current_max = 0;
        for (int j = 1; j <= N; j++) {
            if (i != j) {
                current_max = max(current_max, dist[i][j]);
            }
        }
        min_of_max = min(min_of_max, current_max);
    }

    cout << min_of_max << endl;

    return 0;
}