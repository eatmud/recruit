//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int main()
//{
//    int lineNum = 3; // ����
//    int rowNum = 3;  // ����
//    // ����
//    int matrix[lineNum][rowNum] = {
//    {1, 2, 3},
//    {4, 5, 6},
//    {7, 8, 9}
//    };
//    int val = matrix[1][1];  // ��Ҫ�Ƚϵ��Ǹ���������ȡ 5
//    int absVal[lineNum][rowNum]; // ��ž���ֵ
//    for (int i = 0; i < lineNum; ++i) {         //��ȡһ�У��ٶ�ÿһ�е�ÿһ�б���
//        for (int j = 0; j < rowNum; ++j) {
//            absVal[i][j] = abs(matrix[i][j] - val); //ȡ������Ԫ�أ�ȡ��������ֵ����ŵ�����ֵ��������
//        }
//    }
//    // ��Ӧ����ֵ����
//   for (int i = 0; i < lineNum; ++i) {
//        for (int j = 0; j < rowNum; ++j) {
//            cout << absVal[i][j] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}
