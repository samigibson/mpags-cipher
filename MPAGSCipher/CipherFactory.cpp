#include <memory>

#include "CipherFactory.hpp"
#include "CaesarCipher.hpp"

std::unique_ptr<Cipher> cipherFactory(const CipherType type,
				      std::string const key)
{
  switch(type)
    {
    case CipherType::caesar:
      return std::make_unique<CaesarCipher>(key);
    }
}
