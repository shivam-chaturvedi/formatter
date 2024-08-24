#include <iostream> 
#include <string> 
#include <fstream> // For file input and output
using namespace std;
// Function to format the file
// tihs method will take the filename and format the file 
int format(string filename) {
   // first open the file for reading
   fstream fin(filename, ios::in);
   if (!fin) {
      // If the file couldn't be opened, print an error message and exit
      cout << "Error while opening file " << filename << endl;
      exit(0);
   }

   const string default_space = " "; // Default space for indentation to make code look better
   char ch; // To hold each character read from the file
   int lines = 0; // To count the number of lines in the file
   int spaces = 0; // To track the current indentation level it will help to remove extra spaces from beginning of the line
   bool newline = false; // To check if the last character was a newline
   bool flag = false; // To ensure spaces are added only after certain characters
   char prev; // To keep track of the previous character
   string buffer; // To accumulate formatted content temp
   // read the file character by character
   while (fin.get(ch)) {
      // skip spaces if the previous character was a newline
      if (ch == ' ' && newline) {
         continue;
      } 
      // Handle spaces and newlines
      else if (!newline && ch == ' ') {
         // Add space to buffer if it's the first space after a non-newline character
         if (prev == ' ') {
            // this is to ensur ethat only one spaced will be there extra spaces is removed
            continue;
         }

         buffer += ch;
      } 
      // Handle newline characters
      else if (ch == '\n') {
         // Add a newline and appropriate indentation if previous character was '}'
      if (prev == '}') {
      buffer += "\n";
   } 
   // skip lines if we are at a newline or if flag is false
   else if (newline || !flag) {
      continue;
   }

   // increment line count and set newline flag
   lines++;
   newline = true;
   buffer += ch;
} 
// Handle opening braces '{'
   else if (ch == '{') {
         newline = false;
         buffer += ch;
         spaces++;
      } 
      // Handle closing braces '}'
   else if (ch == '}') {
   spaces--;
   if (newline) {
      // Add spaces for indentation if newline flag is true
      for (int i = 0; i < spaces; i++) {
         buffer += default_space;
      }

   }

   newline = false;
   buffer += ch;
} 
// Handle all other characters
else {
   if (newline) {
      // Add spaces for indentation if newline flag is true
      for (int i = 0; i < spaces; i++) {
         buffer += default_space;
      }

   }

   newline = false;
   buffer += ch;
}

// Update flags and previous character
flag = true;
prev = ch;
}

// Close the input file
fin.close();
// Open the file for writing
fstream fout(filename, ios::out);
for (int i = 0; i < buffer.length(); i++) {
fout.put(buffer.at(i)); //now put formatted string and make a new file
}

// Close the output file
fout.close();
return lines; // Return the number of lines in the formatted file
}

// Main function to handle command line arguments
int main(int argc, char *argv[]) {
// Check if at least one argument (filename) is provided
if (argc > 1) {
int lines = 0;
// now process each file provided as an argument so we can handel mutiple files
for (int i = 1; i < argc; i++) {
   lines = format(argv[i]);
   cout << argv[i] << " now contains " << lines << " lines!" << endl;
}

} else {
cout << "Please Provide a file name ( .c | .cpp | .java)" << endl;
}

return 0; 
}

//now lets test this,first lets add random spaces andl lines
// so its format the whle file you can adjust indetation 