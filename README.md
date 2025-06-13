# CS210 Reflection

Objective:
This project addressed the need for the Corner Grocer to analyze daily purchase records to determine how frequently each item was bought. By reading a transaction log from a file (CS210_Project_Three_Input_File.txt), the program counts item occurrences and outputs them to both the screen and a backup file (frequency.dat). It helps the store identify purchasing trends to inform better store layout and inventory planning.

What went well?
Object-Oriented Design: The use of a well-encapsulated ItemTracker class made the program modular and easy to maintain.
Clear Menu Logic: The menu system was intuitive, with proper input validation for user selections.
Histogram Output: The visual representation of item frequency using asterisks was clean and user-friendly.
Robust File Handling: The code checks for file access errors, which is crucial for real-world reliability.

Where could you enhance your code?
Areas for improvement:
Case Insensitive Item Matching: User input matching could be made case-insensitive to improve usability.
Input Validation for Item Name: More robust input checking (e.g., handling spaces or special characters in item names) could prevent runtime issues.
Exception Handling: Replace exit(1) with exception handling (try-catch) for better control and error reporting.
Command-Line File Input: Accepting the input file name via command-line arguments would make the program more flexible.
Benefits of improvements:
Improves user experience, program security, and scalability.
Enhances code robustness in diverse real-world scenarios.

Which pieces of the code did you find most challenging to write, and how did you overcome this?
The most challenging aspect was implementing the histogram generation and formatting in a way that looked neat and aligned correctly. Using the iomanip library with setw() and left formatting solved the alignment issue. To overcome this, I reviewed C++ documentation on output formatting and tested multiple layouts to find one that was clean and readable.
I also had a hard time grasping the MAP data type at first and had to seek help to understand it better.

What tools or resources are you adding to your support network?
C++ Reference (cppreference.com) – For syntax and standard library features like maps and file streams.
Stack Overflow – For troubleshooting syntax and logic errors.
ZyBooks and course material – For structured examples and guidance.
Visual Studio / SNHU Virtual Lab – For a consistent development environment with debugging tools.


What skills from this project will be particularly transferable to other projects or coursework?
Object-Oriented Programming: Designing and organizing code into classes and methods.
File I/O: Reading from and writing to files—a critical real-world skill.
Data Structures (Maps): Using maps for frequency counting or associative data access.
Input Validation: Ensuring reliable user interaction in menu-driven programs.
Histogram Visualization: Useful for any text-based reporting in CLI applications.

How did you make this program maintainable, readable, and adaptable?
Used consistent naming conventions and clear variable names.
Added inline comments to explain logic for future developers.
Broke functionality into modular methods inside a class, promoting code reuse and easier debugging.
Allowed easy extension (e.g., changing output format or adding export to JSON/CSV) by isolating file operations and UI logic.
