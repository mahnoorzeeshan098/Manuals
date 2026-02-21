#include <iostream>
#include <vector>

int main() {
    int size;

    // Prompt user for the size of the square matrix
    std::cout << "Enter the size of the square matrix (e.g., 3 for a 3x3 matrix): ";
    std::cin >> size;

    // Check for invalid input
    if (size <= 0) {
        std::cout << "Invalid size. Size must be a positive integer." << std::endl;
        return 1;
    }

    // Declare a 2D array (or vector of vectors)
    // Using a 2D array with a fixed maximum size for simplicity of the prompt
    // For more dynamic handling, a vector of vectors is better in modern C++.
    // Using vector of vectors:
    std::vector<std::vector<int>> matrix(size, std::vector<int>(size));

    // Take input for the matrix elements
    std::cout << "Enter the elements of the matrix:" << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << "Enter element at row " << i + 1 << ", column " << j + 1 << ": ";
            std::cin >> matrix[i][j];
        }
    }

    // Output the diagonal entries (principal diagonal)
    std::cout << "\nDiagonal entries of the matrix:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << matrix[i][i] << " ";
    }
    std::cout << std::endl;

    // Optional: Output the anti-diagonal entries
    std::cout << "\nAnti-diagonal entries of the matrix:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << matrix[i][size - 1 - i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
3
