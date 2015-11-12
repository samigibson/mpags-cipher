#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "CaesarCipher.hpp"
#include "ProcessCommandLine.hpp"

void cipher(std::string plaintext)
{
  std::string ciphertext{"HAI"};
  std::vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  for(int i {0}; i < plaintext.size(); ++i)
    {
      //Next two lines should iterated through the alphabet, looking for 
      //a matching letter, then index should be the number (position) 
      //equivalent to that letter. 
      auto it = std::find(alphabet.begin(), alphabet.end(), plaintext[i]);
      auto index = std::distance(alphabet.begin(), it);
      
      //Now the key can be added to the number for the letter, and then
      //that number can be converted back to a letter. 
      //BE CAREFUL ABOUT INDEXING STARTING AT 0!!
      std::cout << index << std::endl;
    }
  
}
