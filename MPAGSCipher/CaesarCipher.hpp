//Header for CAESARCIPHER
#include <string>

#include "Cipher.hpp"

class CaesarCipher : public Cipher
{
public:
  CaesarCipher(const std::string& cipherKey);
  
  virtual std::string encrypt(const std::string& input) const = 0;
  virtual std::string decrypt(const std::string& input) const = 0;

private:
  std::string applyCipher(std::string input};

  int key_;
};
