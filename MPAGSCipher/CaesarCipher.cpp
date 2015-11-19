#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "CaesarCipher.hpp"
#include "ProcessCommandLine.hpp"

CaesarCipher::CaesarCipher(const std::string& cipherKey)
{
  key_ = std::stoi(cipherKey);
}

std::string CaesarCipher::cipher(std::string plaintext)
{
  std::string ciphertext{""};
  std::vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  int key;
  
  key = key_ % 26;

  for(int i {0}; i < plaintext.size(); ++i)
    {
      int indexNew{0};

      //Next two lines should iterate through the alphabet, looking for 
      //a matching letter, then index should be the number (position) 
      //equivalent to that letter. 
      auto it = std::find(alphabet.begin(), alphabet.end(), plaintext[i]);
      auto index = std::distance(alphabet.begin(), it);
      
      //Now the key can be added to the (old) index, and then the new index
      //points to the encypted letter. 
      indexNew = index + key;

      ciphertext += alphabet[indexNew];
    }
  
  return ciphertext;
}
