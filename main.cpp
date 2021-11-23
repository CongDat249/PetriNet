#include "petri_net.cpp"
#include "petri_net.h"
using namespace std;

void problem1() {
    Net n;
    string places[] = {"pFree", "pDocu", "pBusy"};
    string trans[] = {"tStart", "tChange", "tEnd"};
    string arcs[] = {"pFree->tStart", "tStart->pBusy", "pBusy->tChange", "tChange->pDocu", "pDocu->tEnd", "tEnd->pFree"};
    int nP = sizeof(places) / sizeof(places[0]);
    int nT = sizeof(trans) / sizeof(trans[0]);
    int nA = sizeof(arcs) / sizeof(arcs[0]);

    n.addPlaces(places, nP);
    n.addTransitions(trans, nT);
    n.addArcs(arcs, nA);
    int problem = 1;
    n.setInitialM(problem);
    n.changeStage(problem);

    //  Nhap M0 (co ham setInitalM())
    // changeStage
}

void problem2() {
    Net n;
    string places[] = {"pWait", "pInside", "pDone"};
    string trans[] = {"tStart", "tChange"};
    string arcs[] = {"pWait->tStart",
                     "tStart->pInside",
                     "pInside->tChange",
                     "tChange->pDone"};
    int nP = sizeof(places) / sizeof(places[0]);
    int nT = sizeof(trans) / sizeof(trans[0]);
    int nA = sizeof(arcs) / sizeof(arcs[0]);

    n.addPlaces(places, nP);
    n.addTransitions(trans, nT);
    n.addArcs(arcs, nA);

    // Initial marking
    // change stage
    // Fix no dead lock

    int problem = 2;
    n.setInitialM(problem);
    n.changeStage(problem);
}

void problem3() {
    Net n;
    string places[] = {"pFree", "pWait", "pInside", "pDone", "pBusy", "pDocu"};
    string trans[] = {"tStart", "tChange", "tEnd"};
    string arcs[] = {
        "pFree->tStart",
        "pWait->tStart",
        "tStart->pBusy",
        "pStart->pInside",
        "pInside->tEnd",
        "tEnd->pDone",
        "pBusy->tChange", "tChange->pDocu", "pDocu->tEnd", "tEnd->pFree", "pFree->tStart"};
    int nP = sizeof(places) / sizeof(places[0]);
    int nT = sizeof(trans) / sizeof(trans[0]);
    int nA = sizeof(arcs) / sizeof(arcs[0]);

    n.addPlaces(places, nP);
    n.addTransitions(trans, nT);
    n.addArcs(arcs, nA);

    int problem = 3;
    n.setInitialM(problem);
    n.changeStage(problem);
}

long long count(int p1, int p2, int p3, int p4, int p5, int p6, int patient, int doctor) {

    if (p1 == 0 && p2 == 0 && p3 == patient && p4 == doctor && p5 == 0 && p6 == 0) {
        return 1;
    }

    else if (p1 < 0 || p2 < 0 || p3 < 0 || p4 < 0 || p5 < 0 || p6 < 0) {
        return 0;
    }

    else {
        return 1 + count(p1 - 1, p2 + 1, p3, p4 - 1, p5 + 1, p6, patient, doctor) + count(p1, p2, p3, p4, p5 - 1, p6 + 1, patient, doctor) + count(p1, p2 - 1, p3 + 1, p4 + 1, p5, p6 - 1, patient, doctor);
    }
}
void problem4() {
    Net n;
    string places[] = {"pFree", "pWait", "pInside", "pDone", "pBusy", "pDocu"};
    string trans[] = {"tStart", "tChange", "tEnd"};
    string arcs[] = {
        "pFree->tStart",
        "pWait->tStart",
        "tStart->pBusy",
        "pStart->pInside",
        "pInside->tEnd",
        "tEnd->pDone",
        "pBusy->tChange", "tChange->pDocu", "pDocu->tEnd", "tEnd->pFree", "pFree->tStart"};
    int nP = sizeof(places) / sizeof(places[0]);
    int nT = sizeof(trans) / sizeof(trans[0]);
    int nA = sizeof(arcs) / sizeof(arcs[0]);

    n.addPlaces(places, nP);
    n.addTransitions(trans, nT);
    n.addArcs(arcs, nA);

    int problem = 3;
    n.setInitialM(problem);
    int p1, p2, p3, p4, p5, p6;
    int  * M = n.getMarking();
    p1 = M[1];
    p2 = M[2]; //3
    p3 = M[3]; 
    p4 = M[0]; //
    p5 = M[4];  //
    p6 = M[5];
    // cout << "Input tokens in Wait: ";
    // cin >> p1;
    // cout << "Input tokens in Inside: ";
    // cin >> p2;
    // cout << "Input tokens in Done: ";
    // cin >> p3;
    // cout << "Input tokens in Free: ";
    // cin >> p4;
    // cout << "Input tokens in Busy: ";
    // cin >> p5;
    // cout << "Input tokens in Document: ";
    // cin >> p6;
    cout << "Resutls is: " << count(p1, p2, p3, p4, p5, p6, p1 + p2 + p3, p4 + p5 + p6) << endl;
}

int main() {
    //Greeting
    while (true) {
        int choice;
        cout << "Enter your Problem choice (1->4): ";
        cin >> choice;
        switch (choice) {
        case 1:
            problem1();
            break;
        case 2:
            problem2();
            break;
        case 3:
            problem3();
            break;
        case 4:
            problem4();
            break;
        default:
            cout << "Your choice is invalid, please enter a number of your Problem choice!!" << endl;
        }
        int res;
        cout << "Other problem[1], Exit[0]: ";
        cin >> res;
        if (res == 1) continue;
        break;
    }
    return 0;
}