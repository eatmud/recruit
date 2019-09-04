//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int once_quick_sort(vector<int>& data, int left, int right)
//{
//    int key = data[left];
//    while (left < right) {
//        while (left < right && key <= data[right]) {
//            --right;
//        }
//        if (left < right) {
//            data[left] = data[right];
//            ++left;
//        }
//        while (left < right && key > data[left]) {
//            ++left;
//        }
//        if (left < right) {
//            data[right] = data[left];
//            --right;
//        }
//    }
//    data[left] = key;
////    for (auto val : data) {
////        cout << val << " ";
////    }
////    cout << endl;
//    return left;
//}
//int quick_sort(vector<int> & data, int left, int right)
//{
//    if (left >= right )
//    {
//        return 1;
//    }
//    int middle = 0;
//    middle = once_quick_sort(data, left, right);
//    quick_sort(data, left, middle-1);
//    quick_sort(data, middle + 1, right);
//}
//
//int main()
//{
//    vector<int> data ={3, 4, 1, 6, 2};
//    quick_sort(data, 0, data.size() - 1);
//    for (auto val : data) {
//        cout << val << " ";
//    }
//    cout << endl;
//    return 0;
//}
