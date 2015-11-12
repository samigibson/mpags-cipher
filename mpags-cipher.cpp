#include <iostream>
#include <fstream>
#include <string>

//Include header for functions: TRANSFORMCHAR, PROCESSCOMMANDLINE
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "CaesarCipher.hpp"

//Begin MAIN
int main(int argc, char* argv[])
{
  CommandLineInfo info{false, false, false, false, "", "", 0, true};
  
  //Introduce boolian to end program if error found in command line arguments
  //(sf = success/failure)
  bool sf{true};
  
  //Use PROCESSCOMMANDLINE to check for i/o, help, version requests
  sf = processCommandLine(argc, argv, info);
  
  //Initialise plaintext and ciphertext string, used for file/screen input/output
  char inchar{'x'};
  std::string plaintext{""};
  std::string ciphertext{""};

  //If PROCESSCOMMANDLINE unsuccessful, end program
  if(sf==1)
    {
      return 1;
    }
 
  switch(info.ifileRequested)
    {
    case true:
      {
      //Input file given, so open and use
      std::ifstream infile{info.inputFile};
      bool in_ok{infile.good()};

      if(in_ok)
	{
	  while(infile >> inchar)
	    {
	      //Use TRANSFORMCHAR to convert text from the input file 
	      //to uppercase-only plaintext
	      plaintext += transformChar(inchar);
	    }
	  
	  //Close input file once finished
	  infile.close();
	}
      else
	{
	  //If input file not opened correctly, print error and end
	  std::cout << "[error] problem opening input file: "
	            << info.inputFile << std::endl;
	  return 1;
	}
      }
      break;

    case false:
      {
      //Prompt user to enter text in terminal
      std::cout << "Type the text to be encrypted, followed by ENTER, then CTRL+D:"
	        << std::endl;
      
      while(std::cin >> inchar)
	{
	  //No input file given, so use TRANSFORMCHAR to convert 
	  //input from screen into uppercase-only plaintext
	  plaintext += transformChar(inchar);
	}
      }
      break;
    }
    
  cipher(plaintext);

  switch(info.ofileRequested)
    {
    case true:
      {
      //Output file given, so open and use 
      std::ofstream outfile{info.outputFile};
      bool out_ok = outfile.good();

      if(out_ok)
	{
	  //If output file ok, write plaintext into it
	  outfile << plaintext;

	  //Close output file once finished
	  outfile.close();
	}
      else
	{
	  //If output file not opened correctly, print error and end
	  std::cout << "[error] problem opening output file: "
	            << info.outputFile << std::endl;
	  return 1;
	}
      }
      break;

    case false:
      {
      //No output file specified, so print plaintext to screen
      std::cout << plaintext << std::endl;
      }
      break;
    }

  return 0;
}
