#include "DelphesTree.h"


DelphesTree::DelphesTree(TString path, TString pattern) : fChain(0)
{

    TChain *tree = new TChain("Delphes");
    cout << "Adding pattern " << (path + "/*" + pattern + "*.root").Data() << endl;
    tree -> Add(path + "/*" + pattern + "*.root");
    Init(tree);

}

DelphesTree::~DelphesTree()
{
    if (!fChain) return;
}

void DelphesTree::Init(TChain *tree)
{
    if (!tree) return;
    fChain = tree;
    m_treeReader = new ExRootTreeReader(fChain);

    m_branchEvent = m_treeReader->UseBranch("Event");
    m_branchWeight = m_treeReader->UseBranch("Weight");
    m_branchParticle = m_treeReader->UseBranch("Particle");
    m_branchTrack = m_treeReader->UseBranch("Track");
    m_branchTower = m_treeReader->UseBranch("Tower");
    m_branchEFlowTrack = m_treeReader->UseBranch("EFlowTrack");
    m_branchEFlowPhoton = m_treeReader->UseBranch("EFlowPhoton");
    m_branchEFlowNeutralHadron = m_treeReader->UseBranch("EFlowNeutralHadron");
    m_branchGenJet = m_treeReader->UseBranch("GenJet");
    m_branchGenMissingET = m_treeReader->UseBranch("GenMissingET");
    m_branchJet = m_treeReader->UseBranch("Jet");
    m_branchElectron = m_treeReader->UseBranch("Electron");
    m_branchPhoton = m_treeReader->UseBranch("Photon");
    m_branchMuon = m_treeReader->UseBranch("Muon");
    m_branchFatJet = m_treeReader->UseBranch("FatJet");
    m_branchMissingET = m_treeReader->UseBranch("MissingET");
    m_branchScalarHT = m_treeReader->UseBranch("ScalarHT");

}

