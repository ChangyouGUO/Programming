#include <iostream>
// input/ouput file stream
#include <fstream>
// input/output manipulator
#include <iomanip>
#include <string>

using namespace std;

int main() {
  // 修改流的属性，修改后，记得恢复。

  /*
   格式 setw, setfill
  */
  cout << setw(8) << 1000 << "|" << endl;
  // 左对齐
  cout << left << setw(8) << 1000 << "|" << endl;
  // 右对齐
  cout << right << setw(8) << 1000 << "|" << endl;

  // 指定填充内容
  cout << setfill('0') << setw(8) << 1000 << "|" << endl;
  // 后期使用setw都会使用这个符号
  cout << setw(8) << 1000 << "|" << endl;

  // setfill() 仅仅与 setw有效
  cout << setfill('X') << "Some     Spaces" << endl;
  // 建议使用后修改会' '
  cout << setw(8) << 1000 << "|" << setfill(' ') << endl;
  cout << setw(8) << 1000 << "|" << endl;

  /*
    boolalpha, noboolalpha
  */
  cout << true << endl;
  cout << boolalpha << true << endl;
  cout << true << endl;
  cout << noboolalpha << true << endl << endl;

  /*
  radix 进制
  */
  cout << 10 << endl;
  cout << dec << 10 << endl;
  cout << oct << 10 << endl;
  cout << hex << 10 << endl;
  cout << 10 << endl;

  int x;
  cout << "Input a num(0x)" << endl;
  cin >> hex >> x;
  // check if an error occurred
  if (cin.fail()) {
      // error process
  }
  cout << "input: "
       << "(hex)" << x << "(dec)" << dec << x << endl;

  /*
    ws
  */
  ifstream myfile;
  myfile.open("./test.txt");

  // above equals
  ifstream myfile2("./test.txt");

  if (!myfile.is_open()) {
      cerr << "Cannot open file" << endl;
  } else {
      string value;
      // ws: whitespace skip, usefull: in conjunction with these other functions
      myfile >> ws >> value;
  }

  return 0;
}