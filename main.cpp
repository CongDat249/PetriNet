#include "petri_net.cpp"
#include "petri_net.h"
using namespace std;

void problem1() {
    Net n;
    string places[] = {"pFree", "pBusy", "pDocu"};
    string trans[] = {"tStart", "tChange", "tEnd"};
    string arcs[] = {"pFree->tStart", "tStart->pBusy"};
    int nP = sizeof(places) / sizeof(places[0]);
    int nT = sizeof(trans) / sizeof(trans[0]);
    int nA = sizeof(arcs) / sizeof(arcs[0]);

    n.addPlaces(places, nP);
    n.addTransitions(trans, nT);
    n.addArcs(arcs, nA);
    n.setInitialM();

    int c = 0;
    while (true) {
        if (c == 3) break;
        cout << n.toString() << endl;
        bool changed = n.changStage();
        c++;
    }
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
    int M0[3] = {5, 0, 1};

    n.addPlaces(places, nP);
    n.addTransitions(trans, nT);
    n.addArcs(arcs, nA);
    n.initial(M0, 3);

    // Initial marking
    // change stage
    // Fix no dead lock

    int c = 0;
    while (true) {
        cout << n.toString() << endl;
        bool changed = n.changStage();
        if (!changed) {
            break;
        }
        c++;
    }
}

void problem3() {
    Net n;
    string places[] = {"pFree", "pBusy", "pDocu", "pInside", "pWait", "pDone"};
    string trans[] = {"tStart", "tChange", "tEnd"};
    string arcs[] = {
        "pFree->tStart",
        "tStart->pBusy",
        "pStart->pInside",
        "pInside->tEnd",
        "tEnd->pDone",
        "pBusy->tChange", "tChange->pDocu", "pDocu->tEnd", "tEnd->pFree", "pFree->tStart"};
    int nP = sizeof(places) / sizeof(places[0]);
    int nT = sizeof(trans) / sizeof(trans[0]);
    int nA = sizeof(arcs) / sizeof(arcs[0]);
    int M0[nP] = {1, 0, 0, 0, 4, 1};

    n.addPlaces(places, nP);
    n.addTransitions(trans, nT);
    n.addArcs(arcs, nA);
    n.initial(M0, nP);

    int c = 0;
    while (true) {
        cout << n.toString() << endl;
        bool changed = n.changStage();
        if (!changed) {
            break;
        }
        c++;
    }
}

void problem4() {
}

int main() {
    //Greeting
    problem1();
    while (true) {
        int choice;
        cout << "Enter your Problem choice: ";
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
        cout << "Enter 1 to continue or 0 to exit: ";
        if (!res) break;
    }
    return 0;
}