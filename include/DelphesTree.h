#ifndef DelphesTree_h
#define DelphesTree_h

#include "DelphesClasses.h"
#include "ExRootTreeReader.h"

#include <fstream>

#include "TSystem.h"
#include "TROOT.h"
#include "TString.h"
#include "TF2.h"
#include "TChain.h"
#include "TFile.h"
#include "TRefArray.h"
#include "TRef.h"
#include "TRandom3.h"

#include "TClonesArray.h"
#include "TObject.h"
#include "TVector3.h"
#include "TLorentzVector.h"

#include <iostream>
#include <vector>

using namespace std;

class DelphesTree {
public :
    DelphesTree(TString path, TString pattern);
    virtual ~DelphesTree();
    void Loop(TString outtag);
    virtual void     Init(TChain *tree);

    TChain          *fChain; 
    ExRootTreeReader *m_treeReader;

    TClonesArray *m_branchEvent;
    TClonesArray *m_branchJetJES;
    TClonesArray *m_branchLJet;
    TClonesArray *m_branchMet;
    TClonesArray *m_branchGenLJet;
    TClonesArray *m_branchGenMet;
    TClonesArray *m_branchGenElectron;
    TClonesArray *m_branchGenMuon;
    TClonesArray *m_branchGenPhoton;
    TClonesArray *m_branchGenBhadrons;
    TClonesArray *m_branchGenTop;
    TClonesArray *m_branchGenW;
    TClonesArray *m_branchWeight;
    TClonesArray *m_branchParticle;
    TClonesArray *m_branchTrack;
    TClonesArray *m_branchTower;
    TClonesArray *m_branchEFlowTrack;
    TClonesArray *m_branchEFlowPhoton;
    TClonesArray *m_branchEFlowNeutralHadron;
    TClonesArray *m_branchGenJet;
    TClonesArray *m_branchGenMissingET;
    TClonesArray *m_branchJet;
    TClonesArray *m_branchElectron;
    TClonesArray *m_branchPhoton;
    TClonesArray *m_branchMuon;
    TClonesArray *m_branchFatJet;
    TClonesArray *m_branchMissingET;
    TClonesArray *m_branchScalarHT;


};

#endif

