# Simple Data Handling in C++

This project demonstrates basic data handling in C++, using custom data structures and algorithms such as Merge Sort and Binary Search. The application manages a list of students and provides functionalities for adding, retrieving, updating, and removing student data.

## Features
- Add a student
- Retrieve a student by ID (Binary Search)
- Update student details
- Remove a student by ID
- Sort students by name (Merge Sort)

## How to Build and Run
1. Clone this repository.
2. Compile the `main.cpp` file using a C++ compiler:
   ```
   g++ main.cpp -o SimpleDataHandling
   ```
3. Run the executable:
   ```
   ./SimpleDataHandling
   ```

## Limitations
- The application uses a vector to store student data, which may not be optimal for very large datasets.
- Error handling is minimal.