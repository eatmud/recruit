//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int main()
//{
//    int lineNum = 3; // 行数
//    int rowNum = 3;  // 列数
//    // 矩阵
//    int matrix[lineNum][rowNum] = {
//    {1, 2, 3},
//    {4, 5, 6},
//    {7, 8, 9}
//    };
//    int val = matrix[1][1];  // 需要比较的那个数，这里取 5
//    int absVal[lineNum][rowNum]; // 存放绝对值
//    for (int i = 0; i < lineNum; ++i) {         //先取一行，再对每一行的每一列遍历
//        for (int j = 0; j < rowNum; ++j) {
//            absVal[i][j] = abs(matrix[i][j] - val); //取出矩阵元素，取两数绝对值，存放到绝对值矩阵里面
//        }
//    }
//    // 答应绝对值矩阵
//   for (int i = 0; i < lineNum; ++i) {
//        for (int j = 0; j < rowNum; ++j) {
//            cout << absVal[i][j] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}
