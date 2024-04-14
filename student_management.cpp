#include<iostream>
#include<fstream>
using namespace std;

class temp {
    string rollNo, name, fName, address, searchRoll;
    fstream file;
public:
    temp() : rollNo(""), name(""), fName(""), address(""), searchRoll(""), file() {}
    void addstu();
    void viewstu();
    void searchstu();
};

void temp::addstu() {
    cout << "....Enter student Details...." << endl;
    cout << "Enter Student Roll No. :";
    cin.ignore(); // Clear input buffer before getline
    getline(cin, rollNo);
    cout << "\nEnter student Name :";
    getline(cin, name);
    cout << "\nEnter Student Father's Name :";
    getline(cin, fName);
    cout << "\nEnter Student Address :";
    getline(cin, address);

    file.open("StudentData.txt", ios::out | ios::app);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    file << rollNo << "*" << name << "*" << fName << "*" << address << endl;
    file.close();
}

void temp::viewstu() {
    file.open("StudentData.txt", ios::in);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    while (getline(file, rollNo, '*')) {
        getline(file, name, '*');
        getline(file, fName, '*');
        getline(file, address, '\n');
        cout << "Student Roll Number :" << rollNo << endl;
        cout << "Student Name :" << name << endl;
        cout << "Student Father's Name :" << fName << endl;
        cout << "Student Address :" << address << endl;
    }
    file.close();
}

void temp::searchstu() {
    cout << "Enter Student Roll Number :";
    cin.ignore(); // Clear input buffer before getline
    getline(cin, searchRoll);

    file.open("StudentData.txt", ios::in);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    bool found = false;
    while (getline(file, rollNo, '*')) {
        getline(file, name, '*');
        getline(file, fName, '*');
        getline(file, address, '\n');
        if (searchRoll == rollNo) {
            cout << "Student Roll Number :" << rollNo << endl;
            cout << "Student Name :" << name << endl;
            cout << "Student Father's Name :" << fName << endl;
            cout << "Student Address :" << address << endl;
            found = true;
            break; // No need to continue searching
        }
    }
    if (!found) {
        cout << "Student with Roll Number " << searchRoll << " not found." << endl;
    }
    file.close();
}

int main() {
    temp obj;
    char choice;
    cout << "..........Student Management System.........." << endl;
    cout << "1.Add Student Details" << endl;
    cout << "2.View Student Details" << endl;
    cout << "3.Search Student Details" << endl;
    cout << "4.Exit" << endl;
    cout << endl;
    cout << "Enter Your choice :";
    cin >> choice;
    switch (choice) {
        case '1': {
            obj.addstu();
            break;
        }
        case '2': {
            obj.viewstu();
            break;
        }
        case '3': {
            obj.searchstu();
            break;
        }
        case '4': {
            return 0;
            break;
        }
        default:
            cout << "Invalid choice ......!" << endl;
    }
    return 0;
}
