#include <iostream>
#include <fstream>
#include <cstdlib> // for exit()
#include <string>

int main()
{
  using namespace std;

  ofstream outf("/Users/kris/Documents/Coding/learncpp/Sample.txt", ios::app); //append to an already existing file

  //If the file could not have been opened for writing
  if(!outf)
  {
    //print an error and exit
    cerr << "Well, looks like we're not opening Sample for writing :(" << endl;
    exit(1);
  }

  //Write two lines into the file
  // outf << "This is line 1" << endl;
  // outf << "This is line 2" << endl;

  //Read from a file
  ifstream inf("/Users/kris/Documents/Coding/learncpp/Sample.txt", ifstream::binary);

  if (!inf)
    {
      // Print an error and exit
      cerr << "Uh oh, Sample.txt could not be opened for reading!" << endl;
      exit(1);
    }

  while(inf)
  {
    std::string strInput;
    std::getline(inf, strInput);
    std::cout << strInput << endl;
  }

  std::cout << "\n\n";

  inf.seekg(0, ios::beg);
  std::cout << "Trying to output:\n";
  std::string currentInput;
  std::getline(inf, currentInput);
  std::cout << currentInput << endl;

  inf.seekg(0, ios::end); // move to end of file
  cout << inf.tellg();

  return 0;
}
