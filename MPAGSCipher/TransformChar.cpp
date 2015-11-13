#include <string>
#include <cctype> //isalpha

//Inlcude header for TRANSFORMCHAR
#include "TransformChar.hpp"

//TRANSFORMCHAR function: takes single character input, converts 
//letters to uppercase, converts digits to upercase text, discards 
//other characters
std::string transformChar(char input)
{
  std::string instring{""};

  //Makes letters uppercase
  if(isalpha(input))
    {
      instring += std::toupper(input);
    }

  //Turns each digit into an uppercase word
  switch(input)
    {
    case '0':
      instring += "ZERO";
      break;
    case '1':
      instring += "ONE";
      break;
    case '2':
      instring += "TWO";
      break;
    case '3':
      instring += "THREE";
      break;
    case '4':
      instring += "FOUR";
      break;
    case '5':
      instring += "FIVE";
      break;
    case '6':
      instring += "SIX";
      break;
    case '7':
      instring += "SEVEN";
      break;
    case '8':
      instring += "EIGHT";
      break;
    case '9':
      instring += "NINE";
      break;
    }

  return instring;
}
