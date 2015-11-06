#include <string>

struct CommandLineInfo
{
  bool helpRequested = false;
  bool versionRequested = false;
  std::string inputFile;
  std::string outputFile;
};

bool processCommandLine(int argc, char argv[], CommandLineInfo Info);
