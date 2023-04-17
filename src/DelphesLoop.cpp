#include "DelphesTree.h"

#include <TH2.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TStyle.h>
#include <TCanvas.h>

void DelphesTree::Loop(TString outtag)
{
    if (fChain == 0) return;
    Long64_t nentries = m_treeReader->GetEntries();
    int ToRunOver = nentries;

    TString outfilename = "analyzed_histos_" + outtag + ".root";
    TFile *outfile = new TFile(outfilename, "recreate");


    cout << "Will loop over " << ToRunOver << " events." << endl;

    // loop over events in the TTree
    for (Long64_t jentry = 0; jentry < ToRunOver; jentry++) {

        //if (jentry % verbose == 0) {
            cout << "Processing " << jentry << "/" << nentries << " [" << Form("%2.1f", jentry/(1.*nentries) * 100) << "%]" << endl;
        //}

        m_treeReader->ReadEntry(jentry);

        HepMCEvent *event = (HepMCEvent*)m_branchEvent->At(0);

        for (unsigned int i = 0; i < m_branchElectron->GetEntries(); ++i) {
            Electron* el = (Electron*) m_branchElectron->At(i);
            cout << "  i=" << i << " pt= " << el->PT << " eta= " << fabs(el->Eta) << " phi = "<< fabs(el->Phi) <<  endl;
        }
    }
    // +--------------------+
    // |  End of the loop!  |
    // +--------------------+

    cout << "Writing output..." << endl;
    outfile->Write();

    cout << "DONE! Enjoy the output!;-)" << endl;

}
