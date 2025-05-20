# Matrix Operations Program

This program is a C program that performs various operations on square matrices. Below are the key features and usage instructions of the program.

## Usage

1. **Getting Started:**
   - The program prompts the user to enter the size of a square matrix (`matrix_size`).

2. **Creating the Matrix:**
   - The user is given the option to manually enter the matrix elements or fill them with random values within a specified range.

3. **Upper Triangularization:**
   - The `upperTriangularize` function transforms the input matrix into an upper triangular form.

4. **Printing Matrices to the Screen:**
   - The `printMatrix` function prints the initial matrix and the upper triangular matrix to the screen.

5. **Calculating Determinant:**
   - The `calcDet` function calculates the determinant of the upper triangular matrix.

6. **Solving Equations using Cramer's Method:**
   - The `solveUsingCramer` function solves the equations using Cramer's method and prints the results to the screen.

7. **Calculating Matrix Trace and Taking Transpose:**
   - The program calculates the matrix trace and takes the transpose of the matrix, printing the results to the screen.

8. **Memory Cleanup:**
   - The program releases the used memory to prevent memory leaks.

## Installation

To use the project, you can follow the steps below:

1. Clone the repository: `git clone https://github.com/akyurekridvan2101/Matrix-tool-kit.git`
2. Navigate to the project directory: `cd MATRIX-TOOL-KIT/"Matrix tool kit"`
3. Compile the program: `gcc matrixToolKit.c -o matrix_tool_kit`
4. Run the program: `./matrix_tool_kit`

## Contributing

If you wish to contribute to this project, please review the [Contribution Guide](CONTRIBUTING.md) for details.
