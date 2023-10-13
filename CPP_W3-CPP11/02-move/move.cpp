#include <cstring>
#include <iostream>
#include <string_view>

class String {
public:
  String() = default;

  String(std::string_view v) {
    _str = new char[v.size() + 1];
    char* ptr = _str;
    for (auto& c: v) 
      *ptr++ = c;
    *ptr = '\0';
  }

  ~String() {
    delete[] _str;
  }

  char& operator[](size_t index) {
    return _str[index];
  }

  friend std::ostream& operator<< (std::ostream& out, String& str);

private:
  char* _str{nullptr};
};

std::ostream& operator<< (std::ostream& out, String& str) {
  if (str._str == nullptr)
    out << "invalid" ;
  else
    out << str._str;
  return out;
}

String get_one(int depth) {
  if (depth == 0)
    return String{"Another String"};
  return get_one(depth - 1);
}

int main(int argc, char **argv) {
  String x{"HelloWorld"};
  String y{x};
  x[0] = 'h';
  String z{std::move(x)};

  y[1] = 'E';
  z[2] = 'L';

  std::cout << x << "\n";
  std::cout << y << "\n";
  std::cout << z << "\n";
  return 0;
}
