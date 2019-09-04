//#include <vector>
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    string data;
//    cin >> n;
//    cin.get();
//    getline(cin, data);
//    vector<int> number;
//    vector<char> operate;
//    int val= 0;
//    string str = "";
//    str += data[0];
//    for (int i = 1; i < data.length(); ++i) {
//        if (data[i] == ' ') {
//            if (!(data[i-1] == '+' || data[i-1] == '-' || data[i-1] == '*'|| data[i-1] == '/')) {
//                val = stoi(str);
//                number.push_back(val);
//                str.clear();
//                continue;
//            } else {
//                operate.push_back(data[i - 1]);
//                str.clear();
//                continue;
//            }
//        }
//        str += data[i];
//    }
//    val = stoi(str);
//    number.push_back(val);
//    for (int i = 0; i < operate.size(); ++i) {
//        if (operate[i] == '*') {
//            if (number[i + 1] < number[i]) {
//                swap(num[i + 1], number[i]);
//            }
//            continue;
//        } else if (operate[i] == '/') {
//            if (number[i + 1] == 1) {
//                swap(number[i + 1], number[i]);
//            }
//            continue;
//        } else if (operate[i] == '-') {
//            continue;
//        }
//
//    }
//    for (auto i : number) {
//        cout << i << " ";
//    }
//    cout << endl;
//    for (auto ch : operate) {
//        cout << ch << " ";
//    }
//    cout << endl;
////    cout << n << endl;
////    cout << data << endl;
//    return 0;
//}
//
//
