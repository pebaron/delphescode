#include "DelphesTree.h"
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char *argv[])

{
	
   TString path = "";
  TString pattern = "";
  if (argc < 2) {
      cout << "Usage " << argv[0] << " path pattern" << endl;
	  return -1;
  }
  path = argv[1];
  pattern = argv[2];

  cout << "Running over " << path.Data() << "/*" << pattern.Data() << "*.root" << endl;

  gSystem->Load("/home/petr/Ljubljana/MG5_aMC_v2_6_5/Delphes/libDelphes.so");


  DelphesTree *delphesTree = new DelphesTree(path, pattern);
  TString outtag = pattern;
  // Loop! ;-)
  delphesTree -> Loop(outtag);
  delete delphesTree;
  return 0;
}
