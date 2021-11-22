#include <iostream>
using namespace std;

long long count(int p1, int p2, int p3) {
    if (p1 == 0 && p2 == 0 && p3 == 1) return 1;
    else if (p1 < 0 || p2 < 0 || p3 < 0)
        return 0;
    else {
        return 1 + count(p1 - 1, p2 + 1, p3) + count(p1, p2 - 1, p3 + 1);
    }
}

long long count(int p1, int p2, int p3, int p4, int p5, int p6, int patient, int doctor) {
    cout << p1 << p2 << p3 << p4 << p5 << p6 << endl;
    if (p1 == 0 && p2 == 0 && p3 == patient && p4 == doctor && p5 == 0 && p6 == 0) {
        return 1;
    }

    else if (p1 < 0 || p2 < 0 || p3 < 0 || p4 < 0 || p5 < 0 || p6 < 0) {
        return 0;
    }

    else {
        // cout << p1 << p2 << p3 << p4 << p5 << p6 << endl;
        return 1 + count(p1 - 1, p2 + 1, p3, p4 - 1, p5 + 1, p6, patient, doctor) + count(p1, p2, p3, p4, p5 - 1, p6 + 1, patient, doctor) + count(p1, p2 - 1, p3 + 1, p4 + 1, p5, p6 - 1, patient, doctor);
    }
}

int main() {
    int patient, doctor;
    cout << "Input numbers of patient: ";
    cin >> patient;
    cout << "Input numbers of doctor: ";
    cin >> doctor;
    int p1, p2, p3, p4, p5, p6;
    cout << "Input tokens in Wait: ";
    cin >> p1;
    cout << "Input tokens in Inside: ";
    cin >> p2;
    cout << "Input tokens in Done: ";
    cin >> p3;
    cout << "Input tokens in Free: ";
    cin >> p4;
    cout << "Input tokens in Busy: ";
    cin >> p5;
    cout << "Input tokens in Document: ";
    cin >> p6;
    cout << count(p1, p2, p3, p4, p5, p6, p1 + p2 + p3, p4 + p5 + p6);
}