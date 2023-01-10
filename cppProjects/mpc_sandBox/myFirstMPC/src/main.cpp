#include <iostream>
#include <vector>
#include <array>
#include <ctime>
#include <Eigen/Dense>
#include <Eigen/Sparse>

// double determinant(const std::vector<std::vector<double>> &matrix) {
//     unsigned long rows {matrix.size()};
//     unsigned long cols {matrix[0].size()};
//     unsigned long long det;

//     std::cout << "rows = " << rows << "\ncols = " << cols << std::endl;

//     for (int i = 0; i < cols; i++) {
//             std::cout << matrix[i] << rows << "\ncols = " << cols << std::endl;
//     }
    
//     return 0.0;
// };


int main () {


    // Eigen::MatrixXd m(3,3);
    // m << 1, 2, 3,
    //      4, 5, 6,
    //      7, 8, 9;
    Eigen::MatrixXd m = Eigen::MatrixXd::Random(300,300);
    Eigen::SparseMatrix<double> s = m.sparseView();


    double HI = 12345.67; // set HI and LO according to your problem.
    double LO = 0.01;
    double range= HI-LO;
    double threshold {0.75};

   // m = (m + Eigen::MatrixXd::Constant(300,300,1.))*range/2.; // add 1 to the matrix to have values between 0 and 2; multiply with range/2
    //m = (m + MatrixXd::Constant(300,3,LO)); //set LO as the lower bound (offset)

    //std::cout << "m=\n" << m << std::endl;


    clock_t time;
    time = clock();
    m = (threshold < m.array()).select(m, 0.0f);
   //m = (threshold < inout.array().abs()).select(inout, 0.0f);
    //std::cout << m.inverse() << std::endl;
    time = clock() - time;


    std::cout << "s=\n" << s << std::endl;
    std::cout << float(time)/CLOCKS_PER_SEC << std::endl;

    return 0;
}


