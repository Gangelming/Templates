#include "matrix.h"

template<typename T, size_t ROWS, size_t COLS>
Matrix<T, ROWS, COLS>::Matrix() {
    for (size_t i = 0; i < ROWS; ++i)
        for (size_t j = 0; j < COLS; ++j)
            m_data[i][j] = T();
}

template<typename T, size_t ROWS, size_t COLS>
Matrix<T, ROWS, COLS>::Matrix(const T& val) {
    for (size_t i = 0; i < ROWS; ++i)
        for (size_t j = 0; j < COLS; ++j)
            m_data[i][j] = val;
}

template<typename T, size_t ROWS, size_t COLS>
T& Matrix<T, ROWS, COLS>::operator()(size_t row, size_t col) {
    if (row >= ROWS || col >= COLS)
        throw std::out_of_range("Index hors limites");
    return m_data[row][col];
}

template<typename T, size_t ROWS, size_t COLS>
const T& Matrix<T, ROWS, COLS>::operator()(size_t row, size_t col) const {
    if (row >= ROWS || col >= COLS)
        throw std::out_of_range("Index hors limites");
    return m_data[row][col];
}

template class Matrix<float, 2, 2>;
template class Matrix<float, 3, 3>;
template class Matrix<float, 4, 4>;