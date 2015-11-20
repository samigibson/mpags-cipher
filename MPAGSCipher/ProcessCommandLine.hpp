//Header for PROCESSCOMMANDLINE
#include <string>

//Create structure CommandLineInfo to hold information related to the 
//command line arguments 
//(help, version, input file, output file, cipher, key)
struct CommandLineInfo
{
  bool helpRequested;
  bool versionRequested;
  bool ifileRequested;
  bool ofileRequested;
  std::string inputFile;
  std::string outputFile;
  std::string cipher;
  std::string key;
};

enum class CipherMode
{encrypt, decrypt};

enum class CipherType
{ceasar}

//PROCESSCOMMANDLINE function: looks at command line arguments, 
//can output help or version info if requested, 
//and deal with input and output files if specified. 
bool processCommandLine(int argc, char* argv[], CommandLineInfo& Info);
