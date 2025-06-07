# Matrix Operations Program

This program is a C program that performs various operations on square matrices. The basic features of the program and usage instructions are described below.

## Usage

1. **Initialization:**
   - The program starts by prompting the user to enter the size of a square matrix (`matrix_size`).

2. **Matrix Creation:**
   - The user is given the option to manually input matrix elements or fill them with random values within a specified range.

3. **Conversion to Upper Triangular Matrix:**
   - The `upperTriangularize` function converts the input matrix to an upper triangular form.

4. **Printing Matrices to Screen:**
   - The `printMatrix` function prints the original matrix and the upper triangular matrix to the screen.

5. **Determinant Calculation:**
   - The `calcDet` function calculates the determinant of the upper triangular matrix.

6. **Solving Equations using Cramer's Method:**
   - The `solveUsingCramer` function solves equations using Cramer's method and prints the results to the screen.

7. **Calculating Matrix Trace and Taking Transpose:**
   - The program calculates the matrix trace and takes the transpose of the matrix, printing the results to the screen.

8. **Memory Cleanup:**
   - The program releases memory used to prevent memory leaks.

## Installation

To use the project, you can follow these steps:

1. Clone the repository: `git clone https://github.com/akyurekridvan2101/Matrix-tool-kit.git`
2. Navigate to the project directory: `cd MATRIX-TOOL-KIT/"Matrix tool kit"`
3. Compile the program: `gcc matrixToolKit.c -o matrix_tool_kit`
4. Run the program: `./matrix_tool_kit`

## Video

https://github.com/akyurekridvan2101/Matrix-tool-kit/assets/98421577/c9fe3b01-9f21-4344-b903-cc71bb7a9ec5

## Warning: Potential Overflow Situations

This program includes a warning that there may be overflows in `long int` size when matrix dimensions or elements are too large. Especially when working with values exceeding the `long int` size, correct results may not be obtained.

When matrix dimensions or elements are very large, it may be more reliable to keep the matrix size and elements as small as possible rather than relying on the results of the program. Additionally, it's important to carefully verify the inputs and outputs of the program.

If a matrix's size or elements are too large and unexpected results are obtained, reducing the matrix size and elements or solving the problem with a different method may correct this situation.
