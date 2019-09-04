//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    int n;
//    int res = 0;
//    vector<vector<int>> data;
//    vector<int> line;
//    cin >> n;
//    cin.get();
//    string s;
//    string str;
//    int val;
//    while (getline(cin, s))
//    {
//        s += '\n';
//        for (int i = 0; i < s.length(); ++i) {
//            if (s[i] == ' ' || s[i] == '\n') {
//                val = stoi(str);
//                line.push_back(val);
//                str.clear();
//                continue;
//            }
//            str += s[i];
//        }
//        data.push_back(line);
//        line.clear();
//        str.clear();
//        s.clear();
//    }
//    int a = 0;
//    int b = 0;
//    for (int i = 0; i < n;++i) {
//        a = data[i][0];
//        b = data[i][1];
//        int val = (a - b) * i + n * b- a;
//        int index = i;
//        for (int j = i + 1; j < n; ++j) {
//            a = data[j][0];
//            b = data[j][1];
//            int temp = (a - b) * i + n * b- a;
//            if (temp < val) {
//                val = temp;
//                index = j;
//            }
//        }
//        auto it1 = data.begin() + i;
//        auto it2 = data.begin() + index;
//        auto it3 = it1;
//        it1 = it2;
//        it2 = it3;
//        res += (data[i][0] - data[i][1]) * i + n * data[i][1] - data[i][0];
//    }
//    cout << res << endl;
//    cout << n << endl;
//    for (auto i : data) {
//        for (auto j : i) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}
