#include <iostream>
#include <string>

//Include header for functions: TRANSFORMCHAR
#include "TransformChar.hpp"

//Begin MAIN
int main(int argc, char* argv[])
{
  char inchar{'x'};
  std::string plaintext{""};

  while(std::cin >> inchar)
    {
      plaintext += transformChar(inchar);
    }

  std::cout << plaintext << std::endl;

  return 0;
}
