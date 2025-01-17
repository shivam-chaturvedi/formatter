# Code Formatter for C, C++, and Java Files

This project is a simple C++ program that formats code files written in C, C++, or Java. It processes the given files by adding appropriate indentation, removing extra spaces, and ensuring that the code is easy to read and maintain.

## Features
- **Automatic Code Formatting:** This program formats code files by managing indentation and removing unnecessary spaces.
- **Supports Multiple Files:** You can pass multiple filenames as command-line arguments to format all of them in one go.
- **Handles Common Syntax:** The formatter manages braces `{}`, indentation, and spacing around keywords and operators.

## How It Works
The program reads each file character by character, handles indentation based on `{` and `}`, removes extra spaces, and then writes the formatted code back to the file.

### Key Logic:
- **Path Compression for Lines:** Automatically removes extra spaces at the start of lines and handles indentation effectively.
- **Indentation Management:** Increases or decreases indentation levels based on opening or closing braces.
- **Single Space Enforcement:** Ensures only one space exists between tokens where needed, avoiding cluttered code.

## How to Use

### Compilation
First, compile the code using a C++ compiler like `g++`:
```bash
g++ -o formatter formatter.cpp
```

### Running the Program
You can pass one or more filenames as arguments to the program:
```bash
./formatter file1.cpp file2.c file3.java
```

After running the command, the specified files will be formatted, and you'll receive a message indicating how many lines each file contains after formatting.

### Example
Suppose you have a file called `example.cpp`:
```cpp
int main(){
if(true) {  cout<<"Hello"; }
}
```

After formatting with this program, the file will look like:
```cpp
int main() {
    if (true) {
        cout << "Hello";
    }
}
```

## Code Walkthrough

### Main Formatting Logic
The core formatting is handled by the `format` function:
```cpp
int format(string filename) {
    fstream fin(filename, ios::in);
    // Logic to handle formatting: adjusting spaces, managing braces, etc.
    fstream fout(filename, ios::out);
    fout.put(buffer.at(i)); // Writes the formatted code back to the file
    fout.close();
    return lines;
}
```

### Handling Command Line Arguments
The `main` function handles command-line arguments:
```cpp
int main(int argc, char *argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            int lines = format(argv[i]);
            cout << argv[i] << " now contains " << lines << " lines!" << endl;
        }
    } else {
        cout << "Please Provide a file name ( .c | .cpp | .java)" << endl;
    }
    return 0;
}
```

## Use Cases
- **Code Review Preparation:** Ensure your code has a consistent format before submitting it for review.
- **Legacy Code Maintenance:** Quickly clean up messy code from older projects.
- **Project Onboarding:** Ensure new team members start with a clean and readable codebase.

## Dependencies
- C++ Standard Library (no additional dependencies).


## Contribution
Feel free to contribute to the project by submitting issues, suggesting improvements, or creating pull requests!

---

Happy coding! 🎉