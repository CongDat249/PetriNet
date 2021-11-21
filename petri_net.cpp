#include "petri_net.h"

// Places function

Place::Place(string name = "", int nT = 0) {
    this->name = name;
    this->nTokens = nT;
}

void Place::addToken(int nT) {
    this->nTokens += nT;
}

void Place::minusToken(int nT) {
    if (this->nTokens < nT) return;
    else {
        this->nTokens -= nT;
    }
}

int Place::getToken() {
    return this->nTokens;
}

void Place::setToken(int nT) {
    this->nTokens = nT;
}

//Transititon
void Transition::addArcOut(Place* p) {
    out.push_back(p);
}

void Transition::addArcIn(Place* p) {
    in.push_back(p);
}

bool Transition::isEnabled() {
    for (auto it = in.begin(); it != in.end(); ++it) {
        if ((*it)->getToken() == 0) return false;
    }

    return true;
}

void Transition::firing() {
    if (this->isEnabled()) {
        for (auto it = in.begin(); it != in.end(); ++it) {
            (*it)->minusToken(1);
        }
        for (auto it = out.begin(); it != out.end(); ++it) {
            (*it)->addToken(1);
        }
    }
}

// Net function
Place* Net::getPlace(string name) {
    for (auto it = p.begin(); it != p.end(); ++it) {
        if ((*it)->name == name) return *it;
    }
    return nullptr;
}

Transition* Net::getTrans(string name) {
    for (auto it = t.begin(); it != t.end(); ++it) {
        if ((*it)->name == name) return *it;
    }

    return nullptr;
}

void Net::addPlace(string name, int token = 0) {
    p.push_back(new Place(name, token));
}

void Net::addTransition(string name) {
    t.push_back(new Transition(name));
}

void Net::addArcOut(string t, string p) {
    Place* pP = getPlace(p);
    Transition* pT = getTrans(t);

    if (pP && pT) pT->addArcOut(pP);
}

void Net::addArcIn(string p, string t) {
    Place* pP = getPlace(p);
    Transition* pT = getTrans(t);

    if (pP && pT) pT->addArcIn(pP);
}

void Net::addArc(string sou, string des) {
    bool isIn = sou[0] == 'p' ? 1 : 0;
    if (isIn) addArcIn(sou, des);
    else {
        addArcOut(sou, des);
    }
}

bool Net::changStage() {
    for (auto it = t.begin(); it != t.end(); ++it) {
        if ((*it)->isEnabled()) {
            (*it)->firing();
            return true;
        }
    }
    return false;
}

string Net::toString() {
    string res = "[";
    for (auto it = p.begin(); it != p.end(); ++it) {
        res += (*it)->name.substr(1) + "(" + to_string((*it)->getToken()) + "), ";
    }
    res = res.length() ? res.substr(0, res.length() - 2) : res;
    res += "]";
    return res;
}

// Nam
void Net::addPlaces(string* places, int nP) {
    // addPlace
    // input places = {p1, p2, p3, p4};
    int token = 0;
    for (int i = 0; i < nP; i++) {
        p.push_back(new Place(places[i], token));
    }

    this->nP += nP;
}

// Thu
void Net::addTransitions(string* trans, int nT) {
    // addTransition
    for (int i = 0; i < nT; i++) {
        t.push_back(new Transition(trans[i]));
    }

    this->nT += nT;
}

// Phong
void Net::addArcs(string* arcs, int nA) {
    // addArcs
    // input arcs = {"p1->t0", "t0->p2"}
    for (int i = 0; i < nA; i++) {
        string in = arcs[i].substr(0, arcs[i].find('-'));
        string out = arcs[i].substr(arcs[i].find('>') + 1);
        addArc(in, out);
    }
    return;
}

// Hung
void Net::initial(int* marking, int nP) {
    // input marking = {1, 0, 1, 0, 0}, nP = 4
    // viet them setToken o class place
    for (int i = 0; i < nP; i++) {
        p[i]->setToken(marking[i]);
    }
}

string Net::getPlaces() {
    string res = "Places: ";
    for (auto it = p.begin(); it != p.end(); ++it) {
        res += (*it)->name.substr(1) + ", ";
    }
    res = res.length() ? res.substr(0, res.length() - 2) : res;
    return res;
}
string Net::getTransitions() {
    string res = "Transitions: ";
    for (auto it = t.begin(); it != t.end(); ++it) {
        res += (*it)->name.substr(1) + ", ";
    }
    res = res.length() ? res.substr(0, res.length() - 2) : res;
    return res;
}

int* Net::setInitialM() {
    int* arr = new int[nP];
    for (int i = 0; i < nP; i++) {
        cout << "Enter number of tokens at place " << p[i]->name << ": ";
        int tokens = 0;
        cin>> tokens;
        p[i]->setToken(tokens);
    }
    return arr;
}