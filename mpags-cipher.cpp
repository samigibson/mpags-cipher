#include <iostream>
#include <string>

//Include header for functions: TRANSFORMCHAR
#include "TransformChar.hpp"

// Declare functions: TRANSFORMCHAR converts input into string with
// only uppercase letters
//std::string transformChar(char input);

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
