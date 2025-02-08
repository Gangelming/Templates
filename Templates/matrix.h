#pragma once
#include <stdexcept>

template<typename T, size_t ROWS, size_t COLS>
class Matrix {
private:
    T m_data[ROWS][COLS];

public:
    Matrix();
    explicit Matrix(const T& val);

    T& operator()(size_t row, size_t col);
    const T& operator()(size_t row, size_t col) const;

    // Multiplication matrice
    template<size_t OTHER_COLS>
    Matrix<T, ROWS, OTHER_COLS> operator*(const Matrix<T, COLS, OTHER_COLS>& other) const {
        Matrix<T, ROWS, OTHER_COLS> result(0);
        for (size_t i = 0; i < ROWS; ++i)
            for (size_t j = 0; j < OTHER_COLS; ++j)
                for (size_t k = 0; k < COLS; ++k)
                    result(i, j) += m_data[i][k] * other(k, j);
        return result;
    }
};