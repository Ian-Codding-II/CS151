#include <iostream>
// namespace foo {
// void hello() { std::cout << "Hello from foo\n"; }
// } // namespace foo
// namespace boo {
// void hello() { std::cout << "Hello from boo\n"; }
// } // namespace boo
// // using namespace boo;
// int main() {
//   foo::hello();
//   // Hello from foo
//   boo::hello();
//   // Hello from boo
//   // hello();
//   // compiler error
// }

using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  string name;
  cout << "Enter name: ";
  getline(cin, name);
  cout << "Your name is : " << name << endl;
  return 0;
}
