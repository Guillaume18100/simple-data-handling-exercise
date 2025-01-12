#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the Student struct
struct Student {
    int id;
    string name;
    int year_of_enrollment;
    float gpa;
};

// Function to display a student
void displayStudent(const Student& student) {
    cout << "ID: " << student.id << ", Name: " << student.name 
         << ", Year of Enrollment: " << student.year_of_enrollment 
         << ", GPA: " << student.gpa << endl;
}

// Function to add a student
void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter ID: ";
    cin >> newStudent.id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    cout << "Enter Year of Enrollment: ";
    cin >> newStudent.year_of_enrollment;
    cout << "Enter GPA: ";
    cin >> newStudent.gpa;
    students.push_back(newStudent);
    cout << "Student added successfully!\n";
}

// Binary Search to find a student by ID
int binarySearch(const vector<Student>& students, int id) {
    int left = 0;
    int right = students.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].id == id)
            return mid;
        if (students[mid].id < id)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Function to retrieve a student
void retrieveStudent(const vector<Student>& students) {
    int id;
    cout << "Enter Student ID to retrieve: ";
    cin >> id;
    int index = binarySearch(students, id);
    if (index != -1) {
        cout << "Student found:\n";
        displayStudent(students[index]);
    } else {
        cout << "Student not found.\n";
    }
}

// Function to update a student's details
void updateStudent(vector<Student>& students) {
    int id;
    cout << "Enter Student ID to update: ";
    cin >> id;
    int index = binarySearch(students, id);
    if (index != -1) {
        cout << "Enter new details for the student:\n";
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, students[index].name);
        cout << "Enter Year of Enrollment: ";
        cin >> students[index].year_of_enrollment;
        cout << "Enter GPA: ";
        cin >> students[index].gpa;
        cout << "Student details updated successfully!\n";
    } else {
        cout << "Student not found.\n";
    }
}

// Function to remove a student by ID
void removeStudent(vector<Student>& students) {
    int id;
    cout << "Enter Student ID to remove: ";
    cin >> id;
    int index = binarySearch(students, id);
    if (index != -1) {
        students.erase(students.begin() + index);
        cout << "Student removed successfully!\n";
    } else {
        cout << "Student not found.\n";
    }
}

// Merge Sort helper function
void merge(vector<Student>& students, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Student> leftStudents(n1);
    vector<Student> rightStudents(n2);

    for (int i = 0; i < n1; i++)
        leftStudents[i] = students[left + i];
    for (int i = 0; i < n2; i++)
        rightStudents[i] = students[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftStudents[i].name <= rightStudents[j].name) {
            students[k] = leftStudents[i];
            i++;
        } else {
            students[k] = rightStudents[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        students[k] = leftStudents[i];
        i++;
        k++;
    }

    while (j < n2) {
        students[k] = rightStudents[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(vector<Student>& students, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(students, left, mid);
        mergeSort(students, mid + 1, right);
        merge(students, left, mid, right);
    }
}

// Function to display the menu
void displayMenu() {
    cout << "1. Add Student\n";
    cout << "2. Retrieve Student\n";
    cout << "3. Update Student\n";
    cout << "4. Remove Student\n";
    cout << "5. Sort Students by Name\n";
    cout << "6. Display All Students\n";
    cout << "7. Exit\n";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                retrieveStudent(students);
                break;
            case 3:
                updateStudent(students);
                break;
            case 4:
                removeStudent(students);
                break;
            case 5:
                mergeSort(students, 0, students.size() - 1);
                cout << "Students sorted by name.\n";
                break;
            case 6:
                for (const auto& student : students) {
                    displayStudent(student);
                }
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 7);

    return 0;
}
