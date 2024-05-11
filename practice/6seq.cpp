#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

void addStudent(){
    ofstream outFile("student.txt",ios::app);
    if(!outFile) {
        cout<<"error in opening file";
        return;
    }
    
    Student newStudent;
    cout<<"Enter roll number: ";
    cin>>newStudent.rollNumber;

    cout<<"Enter Name";
    cin.ignore();
    getline(cin, newStudent.name);

    cout<<"Enter Division";
    cin.ignore();
    getline(cin, newStudent.division);

    cout<<"Enter Address";
    cin.ignore();
    getline(cin, newStudent.address);

    outFile<<newStudent.rollNumber<<" "<<newStudent.name<<" "<<newStudent.division<<" "<<newStudent.address<<endl;
    cout<<"student info added successfully";
    outFile.close();

}

void deleteStudent(int rollNumber){
    ifstream inFile("student.txt");
    ofstream tempFile("temp.txt");

   bool found = false;
    Student student;
    while (inFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        cout<<student.name;
        if (student.rollNumber != rollNumber) {
            tempFile << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();
    remove("student.txt");
    rename("temp.txt", "student.txt");

}


int main() {
    // addStudent();
    deleteStudent(1);
    
}