#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<std::vector<int>> Matrix;
typedef std::vector<int> Row;

// Define a custom iterator for iterating through rows of a 2D vector
class MatrixRowIterator {
private:
    Matrix::iterator rowIterator;
    Matrix::iterator rowEnd;

public:
    MatrixRowIterator(Matrix::iterator begin, Matrix::iterator end)
        : rowIterator(begin), rowEnd(end) {}

    // Define operators for the iterator
    bool operator!=(const MatrixRowIterator& other) const {
        return rowIterator != other.rowIterator;
    }

    Row& operator*() {
        return *rowIterator;
    }

    MatrixRowIterator& operator++() {
        ++rowIterator;
        return *this;
    }
};

// Define a helper function to create the begin and end iterators
MatrixRowIterator begin(Matrix& matrix) {
    return MatrixRowIterator(matrix.begin(), matrix.end());
}

MatrixRowIterator end(Matrix& matrix) {
    return MatrixRowIterator(matrix.end(), matrix.end());
}

int main() {
    Matrix my2DVector = {
        {3, 2, 1},
        {6, 5, 4},
        {9, 8, 7}
    };

    // Sort the rows of the 2D vector using the custom iterator
    std::sort(begin(my2DVector), end(my2DVector));

    // Print the sorted 2D vector
    for (const Row& row : my2DVector) {
        for (int value : row) {
            std::cout << value << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
