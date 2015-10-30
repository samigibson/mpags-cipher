#include <iostream>
#include <string>

int main(int argc, char* argv[])

{
  char in_char{'x'};

  while(std::cin >> in_char)
    {
      //switch (in_char) 
    }

  for (int i(0); i < argc; ++i)
    {
      std::string argument = argv[i];
      std::cout << argv[i] << std::endl;
    }
  
  return 0;
}
