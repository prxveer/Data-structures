#include <iostream>
using namespace std;

struct Node {
    int coeff, exp;
    Node* prev; Node* next;
    Node(int c, int e) : coeff(c), exp(e), prev(nullptr), next(nullptr) {}
};

class Polynomial {
    Node* head;
public:
    Polynomial() : head(nullptr) {}
    ~Polynomial() { while (head) deleteTerm(head->exp); }
    
    void insertTerm(int c, int e) {
        if (c == 0) return; 
        Node* newNode = new Node(c, e);
        if (!head || head->exp < e) { newNode->next = head; if (head) head->prev = newNode; head = newNode; return; }
        
        Node* temp = head;
        while (temp->next && temp->next->exp > e) temp = temp->next;

        if (temp->exp == e) { temp->coeff += c; delete newNode; if (temp->coeff == 0) deleteTerm(e); return; }
        newNode->prev = temp; newNode->next = temp->next;
        if (temp->next) temp->next->prev = newNode; temp->next = newNode;
    }
    
    void deleteTerm(int e) {
        Node* temp = head; while (temp && temp->exp != e) temp = temp->next;
        if (!temp) return; if (temp->prev) temp->prev->next = temp->next; else head = temp->next; 
        if (temp->next) temp->next->prev = temp->prev; delete temp;
    }
    
    Polynomial add(const Polynomial& other) const {
        Polynomial result; for (Node *p1 = head, *p2 = other.head; p1 || p2;) {
            if (!p1 || (p2 && p2->exp > p1->exp)) result.insertTerm(p2->coeff, p2->exp), p2 = p2->next;
            else if (!p2 || (p1 && p1->exp > p2->exp)) result.insertTerm(p1->coeff, p1->exp), p1 = p1->next;
            else result.insertTerm(p1->coeff + p2->coeff, p1->exp), p1 = p1->next, p2 = p2->next;
        }
        return result;
    }
    
    void printPolynomial() const {
        for (Node* temp = head; temp; temp = temp->next) cout << temp->coeff << "x^" << temp->exp << (temp->next ? " + " : "");
        cout << endl;
    }
};

int main() {
    Polynomial poly1, poly2; int coeff, exp;
    for (int coeff, exp; cin >> coeff && coeff != -1; cout << "Enter coefficient and exponent (-1 to finish): ") {
        cin >> exp; poly1.insertTerm(coeff, exp);
    }
    for (int coeff, exp; cin >> coeff && coeff != -1; cout << "Enter coefficient and exponent (-1 to finish): ") {
        cin >> exp; poly2.insertTerm(coeff, exp);
    }
    Polynomial result = poly1.add(poly2);
    cout << "Polynomial A: "; poly1.printPolynomial();
    cout << "Polynomial B: "; poly2.printPolynomial();
    cout << "Result of A + B: "; result.printPolynomial();
    return 0;
}
