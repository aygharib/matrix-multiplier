#include <array>
#include <iostream>

void print_matrix(std::array<std::array<int, 3>, 3>& matrix) {
    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < matrix[0].size(); col++) {
            std::cout << matrix[row][col] << ", ";
        }
        std::cout << "\n";
    }
}

auto main() -> int {
    auto A =
        std::array<std::array<int, 3>, 3>{{{1, 2, -1}, {3, 2, 0}, {-4, 0, 2}}};
    auto B =
        std::array<std::array<int, 3>, 3>{{{3, 4, 2}, {0, 1, 0}, {-2, 0, 1}}};
    auto C =
        std::array<std::array<int, 3>, 3>{{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};

    for (int row = 0; row < A.size(); row++) {
        for (int col = 0; col < A[0].size(); col++) {
            int result = 0;

            for (int stride = 0; stride < A.size(); stride++) {
                result += A[row][stride] * B[stride][col];
            }

            C[row][col] = result;
        }
    }

    print_matrix(C);
}