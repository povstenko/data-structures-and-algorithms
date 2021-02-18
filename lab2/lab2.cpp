#include <iostream>
using namespace std;

const int surname_len = 30;

struct employee {
    unsigned int id;
    char surname[surname_len];
    unsigned int age;
    unsigned int experience;
    double salary;
    void full_out() {
        cout << "ID: "<< id << endl;
        cout << "Surname: "<< surname << endl;
        cout << "Age: "<< age << endl;
        cout << "Experience: "<< experience << endl;
        cout << "salary: "<< salary << endl;
    }
    void short_out() {
        cout << id << " " << experience << endl;
    }
};

void swap_char(char a[], char b[], int size) {
    char tmp;
    for (int i = 0; i < size; i++) {
        tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}
void swap(employee &P1, employee &P2) {
    swap(P1.id, P2.id);
    swap_char(P1.surname, P2.surname, surname_len);
    swap(P1.age, P2.age);
    swap(P1.experience, P2.experience);
    swap(P1.salary, P2.salary);
}

int main() {
    int n = 2;
    employee P[n];
    
    cout << "Enter employees" << endl;
    for (int i = 0; i < n; i++) {
        P[i].id = i;
        cout << "\nID: " << P[i].id << endl;
        cout << "Surname: "; cin >> P[i].surname;
        cout << "Age: "; cin >> P[i].age;
        cout << "Experience: "; cin >> P[i].experience;
        cout << "Salary: "; cin >> P[i].salary;
    }
    
    cout << "\nEmployees (id, experience)" << endl;
    for (int i = 0; i < n; i++) {
        P[i].short_out();
    }
    
    cout << "\nSort by id desc" << endl;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if(P[j].id < P[j+1].id) {
                swap(P[j], P[j+1]);
            }
        }
    }
    
    cout << "\nEmployees (id, experience)" << endl;
    for (int i = 0; i < n; i++) {
        P[i].short_out();
    }
    
    cout << "\nSort by experience asc" << endl;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if(P[j].experience > P[j+1].experience) {
                swap(P[j], P[j+1]);
            }
        }
    }
    
    cout << "\nEmployees (id, experience)" << endl;
    for (int i = 0; i < n; i++) {
        P[i].short_out();
    }

    return 0;
}