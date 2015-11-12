// (Taken from solution but now edited)

#include <iostream>
#include <fstream> //files
#include <string>

//Include header for PROCESSCOMMANDLINE
#include "ProcessCommandLine.hpp"

//PROCESSCOMMANDLINE function: looks at command line arguments, 
//can output help or version info if requested, 
//and deal with input and output files if specified. 
bool processCommandLine(int argc, char* argv[], CommandLineInfo& info) 
{
  // Process command line arguments - ignore zeroth element of argv
  // as we know this to be the program name and don't need to worry
  // about it
  for (int i {1}; i < argc; ++i) 
    {
      std::string argvString(argv[i]);

      if (argvString == "-h" || argvString == "--help") 
	{
	  info.helpRequested = true;
	}
      else if (argvString == "--version") 
	{
	  info.versionRequested = true;
	}
      else if (argvString == "-i") 
	{
	  info.ifileRequested = true;
	  
	  // Handle input file option
	  // Next element is filename unless -i is the last argument
	  if (i == argc-1) 
	    {
	      std::cout << "-i requires a filename argument" << std::endl;
	      // exit PROCESSCOMMANDLINE with non-zero return to indicate failure
	      return 1;
	    }
	  else 
	    {
	      // Got filename, so assign value and advance past it.
	      info.inputFile = argv[i+1];
	      i += 1;
	    }
	}
      else if (argvString == "-o") 
	{
	  info.ofileRequested = true;
	  
	  // Handle output file option
	  // Next element is filename unless -i is the last argument
	  if (i == argc-1) 
	    {
	      std::cout << "-o requires a filename argument" << std::endl;
	      // exit PROCESSCOMMANDLINE with non-zero return to indicate failure
	      return 1;
	    }
	  else 
	    {
	      // Got filename, so assign value and advance past it.
	      info.outputFile = argv[i+1];
	      i += 1;
	    }
	}
      else 
	{
	  // Have an unknown flag to output error message and return non-zero
	  // exit status to indicate failure
	  std::cout << "[error] unknown argument: " << argvString << std::endl;
	  return 1;
	}
    }

  // Handle help, if requested
  if (info.helpRequested) 
    {
      // Line splitting for readability
      std::cout
        << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
        << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
        << "Available options:\n\n"
        << "  -h|--help        Print this help message and exit\n\n"
        << "  --version        Print version information\n\n"
        << "  -i FILE          Read text to be processed from FILE\n"
        << "                   Stdin will be used if not supplied\n\n"
        << "  -o FILE          Write processed text to FILE\n"
        << "                   Stdout will be used if not supplied\n\n";
      // Help requires no further action, so return from PROCESSCOMANDLINE
      // with 0 used to indicate success
      return 0;
    }

  // Handle version, if requested. Like help, requires no further action,
  // so return from main with zero to indicate success
  if (info.versionRequested) 
    {
      std::cout << "0.1.0" << std::endl;
      return 0;
    }

  /*// Read in user input from stdin/file
  // Warn that input file option not yet implemented
  if (info.ifileRequested) 
    {
      std::cout << "[warning] input from file ('"
		<< info.inputFile
		<< "') not implemented yet, using stdin\n";
    }

  // If requested, open and then check output file
  if (info.ofileRequested) 
    {
      std::ofstream out_file{info.outputFile};

      bool out_ok = out_file.good();

      if(!out_ok)
	{
	  //If output file not opened correctly, print error and end
	  std::cout << "[error] problem with output file: "
	            << info.outputFile << std::endl;
	  return 1;
	}
    }*/

  // Return zero to indicate PROCESSCOMMANDLINE finished successfully
  return 0;
}
