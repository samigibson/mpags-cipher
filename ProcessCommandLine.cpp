// Taken (pretty much) verbatim from solution

#include <iostream>
#include <string>

int processCommandLine(int argc, char* argv[]) 
{
  // Command line inputs
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};

  // Process command line arguments - ignore zeroth element of argv
  // as we know this to be the program name and don't need to worry
  // about it
  for (int i {1}; i < argc; ++i) 
    {
      std::string argvString(argv[i]);

      if (argvString == "-h" || argvString == "--help") 
	{
	  helpRequested = true;
	}
      else if (argvString == "--version") 
	{
	  versionRequested = true;
	}
      else if (argvString == "-i") 
	{
	  // Handle input file option
	  // Next element is filename unless -i is the last argument
	  if (i == argc-1) 
	    {
	      std::cout << "-i requires a filename argument" << std::endl;
	      // exit main with non-zero return to indicate failure
	      return 1;
	    }
	  else 
	    {
	      // Got filename, so assign value and advance past it.
	      inputFile = argv[i+1];
	      i += 1;
	    }
	}
      else if (argvString == "-o") 
	{
	  // Handle output file option
	  // Next element is filename unless -i is the last argument
	  if (i == argc-1) 
	    {
	      std::cout << "-o requires a filename argument" << std::endl;
	      // exit main with non-zero return to indicate failure
	      return 1;
	    }
	  else 
	    {
	      // Got filename, so assign value and advance past it.
	      outputFile = argv[i+1];
	      i += 1;
	    }
	}
      else 
	{
	  // Have an unknown flag to output error message and return non-zero
	  // exit status to indicate failure
	  std::cout << "[error] unknown argument '" << argvString << "'\n";
	  return 1;
	}
    }

  // Handle help, if requested
  if (helpRequested) 
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
      // Help requires no further action, so return from main
      // with 0 used to indicate success
      return 0;
    }

  // Handle version, if requested. Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) 
    {
      std::cout << "0.1.0" << std::endl;
      return 0;
    }

  // Read in user input from stdin/file
  // Warn that input file option not yet implemented
  if (!inputFile.empty()) 
    {
      std::cout << "[warning] input from file ('"
		<< inputFile
		<< "') not implemented yet, using stdin\n";
    }

  // INPUT FROM TERMINAL WAS HERE

  // Output the input text
  // Warn that output file option not yet implemented
  if (!outputFile.empty()) 
    {
      std::cout << "[warning] output to file ('"
		<< outputFile
		<< "') not implemented yet, using stdout\n";
    }

  std::cout << inputText << "\n";

  // No requirement to return from main, but we do so for clarity and
  // consistency with other functions.

  return 0;
}
