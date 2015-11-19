//Header for CAESARCIPHER
#include <string>

class CaesarCipher
{
public:
  CaesarCipher(const std::string& cipherKey);

  int key_;

  std::string cipher(std::string plaintext);
};
