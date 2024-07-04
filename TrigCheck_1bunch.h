//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Apr 11 13:27:10 2024 by ROOT version 6.30/04
// from TTree TreeHits/TreeHits
// found on file: data/428770/user.sarbiolv.428770.physics_MinBias.HLT_noalg_mb_L1MBTS_1_FILLED_L1afterprescale_nTrgList.merge.root
//////////////////////////////////////////////////////////

#ifndef TrigCheck_1bunch_h
#define TrigCheck_1bunch_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TEfficiency.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include <iostream>
#include <fstream>
using namespace std; 

class TrigCheck_1bunch {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           evN;
   Int_t           lmiBl;
   Float_t         mu;
   UInt_t          timestamp;
   UInt_t          bcid;
   vector<bool>    *Trigger_L1_beforePrescale;
   vector<bool>    *Trigger_L1_afterPrescale;
   vector<bool>    *Trigger_HLT_isPrescaledOut;
   vector<bool>    *Trigger_HLT_afterPrescale;
   Int_t           NVertex;
   Int_t           NInDetTrackParticles;
   Int_t           nhits[4][4];
   Int_t           nclusters[4][4];
   Int_t           ntracks[4];
   Int_t           nprotons[2];
   Int_t           NAfpProton;
   vector<int>     *AfpProton_Id;
   vector<int>     *AfpProton_Side;
   vector<float>   *AfpProton_Pt;
   vector<float>   *AfpProton_Px;
   vector<float>   *AfpProton_Py;
   vector<float>   *AfpProton_Pz;
   vector<float>   *AfpProton_E;
   vector<float>   *AfpProton_Eta;
   vector<float>   *AfpProton_Phi;
   vector<float>   *AfpProton_ChiSq;
   Int_t           NAfpTrack;
   vector<int>     *AfpTrack_Id;
   vector<int>     *AfpTrack_Station;
   vector<float>   *AfpTrack_X;
   vector<float>   *AfpTrack_Y;
   vector<float>   *AfpTrack_SX;
   vector<float>   *AfpTrack_SY;
   Int_t           NAfpCluster;
   vector<int>     *AfpCluster_Id;
   vector<int>     *AfpCluster_Station;
   vector<int>     *AfpCluster_Plane;
   vector<float>   *AfpCluster_X;
   vector<float>   *AfpCluster_Y;
   vector<float>   *AfpCluster_Z;
   vector<float>   *AfpCluster_Q;
   vector<int>     *AfpCluster_N;
   Int_t           nclusters_toolbox[4][4];
   Int_t           ntracks_toolbox[4];
   Int_t           nprotons_toolbox[2];
   Int_t           NAfpToolboxProton;
   vector<int>     *AfpToolboxProton_Id;
   vector<int>     *AfpToolboxProton_Side;
   vector<float>   *AfpToolboxProton_Pt;
   vector<float>   *AfpToolboxProton_Px;
   vector<float>   *AfpToolboxProton_Py;
   vector<float>   *AfpToolboxProton_Pz;
   vector<float>   *AfpToolboxProton_E;
   vector<float>   *AfpToolboxProton_Eta;
   vector<float>   *AfpToolboxProton_Phi;
   vector<float>   *AfpToolboxProton_ChiSq;
   Int_t           NAfpToolboxTrack;
   vector<int>     *AfpToolboxTrack_Id;
   vector<int>     *AfpToolboxTrack_Station;
   vector<float>   *AfpToolboxTrack_X;
   vector<float>   *AfpToolboxTrack_Y;
   vector<float>   *AfpToolboxTrack_SX;
   vector<float>   *AfpToolboxTrack_SY;
   Int_t           NAfpToolboxCluster;
   vector<int>     *AfpToolboxCluster_Id;
   vector<int>     *AfpToolboxCluster_Station;
   vector<int>     *AfpToolboxCluster_Plane;
   vector<float>   *AfpToolboxCluster_X;
   vector<float>   *AfpToolboxCluster_Y;
   vector<float>   *AfpToolboxCluster_Z;
   vector<float>   *AfpToolboxCluster_Q;
   vector<int>     *AfpToolboxCluster_N;
   Int_t           NAfpHit;
   vector<int>     *AfpHit_Id;
   vector<int>     *AfpHit_Station;
   vector<int>     *AfpHit_Plane;
   vector<int>     *AfpHit_Row;
   vector<int>     *AfpHit_Col;
   vector<float>   *AfpHit_Q;
   Int_t           ntofhits[2][4][4];
   Int_t           NAfpTofHit;
   vector<int>     *AfpTofHit_Station;
   vector<float>   *AfpTofHit_Time;
   vector<int>     *AfpTofHit_Train;
   vector<float>   *AfpTofHit_Length;
   vector<int>     *AfpTofHit_HptdcId;
   vector<int>     *AfpTofHit_Channel;
   vector<int>     *AfpTofHit_Bar;

   // List of branches
   TBranch        *b_evN;   //!
   TBranch        *b_lmiBl;   //!
   TBranch        *b_mu;   //!
   TBranch        *b_timestamp;   //!
   TBranch        *b_bcid;   //!
   TBranch        *b_Trigger_L1_beforePrescale;   //!
   TBranch        *b_Trigger_L1_afterPrescale;   //!
   TBranch        *b_Trigger_HLT_isPrescaledOut;   //!
   TBranch        *b_Trigger_HLT_afterPrescale;   //!
   TBranch        *b_NVertex;   //!
   TBranch        *b_NInDetTrackParticles;   //!
   TBranch        *b_nhits;   //!
   TBranch        *b_nclusters;   //!
   TBranch        *b_ntracks;   //!
   TBranch        *b_nprotons;   //!
   TBranch        *b_NAfpProton;   //!
   TBranch        *b_AfpProton_Id;   //!
   TBranch        *b_AfpProton_Side;   //!
   TBranch        *b_AfpProton_Pt;   //!
   TBranch        *b_AfpProton_Px;   //!
   TBranch        *b_AfpProton_Py;   //!
   TBranch        *b_AfpProton_Pz;   //!
   TBranch        *b_AfpProton_E;   //!
   TBranch        *b_AfpProton_Eta;   //!
   TBranch        *b_AfpProton_Phi;   //!
   TBranch        *b_AfpProton_ChiSq;   //!
   TBranch        *b_NAfpTrack;   //!
   TBranch        *b_AfpTrack_Id;   //!
   TBranch        *b_AfpTrack_Station;   //!
   TBranch        *b_AfpTrack_X;   //!
   TBranch        *b_AfpTrack_Y;   //!
   TBranch        *b_AfpTrack_SX;   //!
   TBranch        *b_AfpTrack_SY;   //!
   TBranch        *b_NAfpCluster;   //!
   TBranch        *b_AfpCluster_Id;   //!
   TBranch        *b_AfpCluster_Station;   //!
   TBranch        *b_AfpCluster_Plane;   //!
   TBranch        *b_AfpCluster_X;   //!
   TBranch        *b_AfpCluster_Y;   //!
   TBranch        *b_AfpCluster_Z;   //!
   TBranch        *b_AfpCluster_Q;   //!
   TBranch        *b_AfpCluster_N;   //!
   TBranch        *b_nclusters_toolbox;   //!
   TBranch        *b_ntracks_toolbox;   //!
   TBranch        *b_nprotons_toolbox;   //!
   TBranch        *b_NAfpToolboxProton;   //!
   TBranch        *b_AfpToolboxProton_Id;   //!
   TBranch        *b_AfpToolboxProton_Side;   //!
   TBranch        *b_AfpToolboxProton_Pt;   //!
   TBranch        *b_AfpToolboxProton_Px;   //!
   TBranch        *b_AfpToolboxProton_Py;   //!
   TBranch        *b_AfpToolboxProton_Pz;   //!
   TBranch        *b_AfpToolboxProton_E;   //!
   TBranch        *b_AfpToolboxProton_Eta;   //!
   TBranch        *b_AfpToolboxProton_Phi;   //!
   TBranch        *b_AfpToolboxProton_ChiSq;   //!
   TBranch        *b_NAfpToolboxTrack;   //!
   TBranch        *b_AfpToolboxTrack_Id;   //!
   TBranch        *b_AfpToolboxTrack_Station;   //!
   TBranch        *b_AfpToolboxTrack_X;   //!
   TBranch        *b_AfpToolboxTrack_Y;   //!
   TBranch        *b_AfpToolboxTrack_SX;   //!
   TBranch        *b_AfpToolboxTrack_SY;   //!
   TBranch        *b_NAfpToolboxCluster;   //!
   TBranch        *b_AfpToolboxCluster_Id;   //!
   TBranch        *b_AfpToolboxCluster_Station;   //!
   TBranch        *b_AfpToolboxCluster_Plane;   //!
   TBranch        *b_AfpToolboxCluster_X;   //!
   TBranch        *b_AfpToolboxCluster_Y;   //!
   TBranch        *b_AfpToolboxCluster_Z;   //!
   TBranch        *b_AfpToolboxCluster_Q;   //!
   TBranch        *b_AfpToolboxCluster_N;   //!
   TBranch        *b_NAfpHit;   //!
   TBranch        *b_AfpHit_Id;   //!
   TBranch        *b_AfpHit_Station;   //!
   TBranch        *b_AfpHit_Plane;   //!
   TBranch        *b_AfpHit_Row;   //!
   TBranch        *b_AfpHit_Col;   //!
   TBranch        *b_AfpHit_Q;   //!
   TBranch        *b_ntofhits;   //!
   TBranch        *b_NAfpTofHit;   //!
   TBranch        *b_AfpTofHit_Station;   //!
   TBranch        *b_AfpTofHit_Time;   //!
   TBranch        *b_AfpTofHit_Train;   //!
   TBranch        *b_AfpTofHit_Length;   //!
   TBranch        *b_AfpTofHit_HptdcId;   //!
   TBranch        *b_AfpTofHit_Channel;   //!
   TBranch        *b_AfpTofHit_Bar;   //!

   TrigCheck_1bunch(TTree *tree=0);
   virtual ~TrigCheck_1bunch();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   //Custom functions
   void CheckTrigger(std::vector<bool> &passTrg, std::vector<std::string> m_allTriggers);
   void CheckStations(std::vector<bool> &activeSt);
   int GetTrain(int bcid, std::vector<std::pair<int, int>> bcid_trains);
   int GetCrossBunch(int bcid, int single_bunch);
   void GetXY(int row, int col, float &x, float &y);
   
   private :

   double lowXbhmap = 0,//instead of 0 to see if there is something to the left
      highXbhmap = 16.8,
      lowYbhmap = 0, //instead of 0 to see if there is something below
      highYbhmap = 20.0;


   int nXbhmap = 336,
      nYbhmap = 81; 
};


#endif

#ifdef TrigCheck_1bunch_cxx
TrigCheck_1bunch::TrigCheck_1bunch(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/home/sjarbiolv/Work/TrigCheck/data/428770/PEB_FSC.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/home/sjarbiolv/Work/TrigCheck/data/428770/PEB_FSC.root");
      }
      f->GetObject("TreeHits",tree);

   }
   Init(tree);
}

TrigCheck_1bunch::~TrigCheck_1bunch()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t TrigCheck_1bunch::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t TrigCheck_1bunch::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void TrigCheck_1bunch::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   Trigger_L1_beforePrescale = 0;
   Trigger_L1_afterPrescale = 0;
   Trigger_HLT_isPrescaledOut = 0;
   Trigger_HLT_afterPrescale = 0;
   AfpProton_Id = 0;
   AfpProton_Side = 0;
   AfpProton_Pt = 0;
   AfpProton_Px = 0;
   AfpProton_Py = 0;
   AfpProton_Pz = 0;
   AfpProton_E = 0;
   AfpProton_Eta = 0;
   AfpProton_Phi = 0;
   AfpProton_ChiSq = 0;
   AfpTrack_Id = 0;
   AfpTrack_Station = 0;
   AfpTrack_X = 0;
   AfpTrack_Y = 0;
   AfpTrack_SX = 0;
   AfpTrack_SY = 0;
   AfpCluster_Id = 0;
   AfpCluster_Station = 0;
   AfpCluster_Plane = 0;
   AfpCluster_X = 0;
   AfpCluster_Y = 0;
   AfpCluster_Z = 0;
   AfpCluster_Q = 0;
   AfpCluster_N = 0;
   AfpToolboxProton_Id = 0;
   AfpToolboxProton_Side = 0;
   AfpToolboxProton_Pt = 0;
   AfpToolboxProton_Px = 0;
   AfpToolboxProton_Py = 0;
   AfpToolboxProton_Pz = 0;
   AfpToolboxProton_E = 0;
   AfpToolboxProton_Eta = 0;
   AfpToolboxProton_Phi = 0;
   AfpToolboxProton_ChiSq = 0;
   AfpToolboxTrack_Id = 0;
   AfpToolboxTrack_Station = 0;
   AfpToolboxTrack_X = 0;
   AfpToolboxTrack_Y = 0;
   AfpToolboxTrack_SX = 0;
   AfpToolboxTrack_SY = 0;
   AfpToolboxCluster_Id = 0;
   AfpToolboxCluster_Station = 0;
   AfpToolboxCluster_Plane = 0;
   AfpToolboxCluster_X = 0;
   AfpToolboxCluster_Y = 0;
   AfpToolboxCluster_Z = 0;
   AfpToolboxCluster_Q = 0;
   AfpToolboxCluster_N = 0;
   AfpHit_Id = 0;
   AfpHit_Station = 0;
   AfpHit_Plane = 0;
   AfpHit_Row = 0;
   AfpHit_Col = 0;
   AfpHit_Q = 0;
   AfpTofHit_Station = 0;
   AfpTofHit_Time = 0;
   AfpTofHit_Train = 0;
   AfpTofHit_Length = 0;
   AfpTofHit_HptdcId = 0;
   AfpTofHit_Channel = 0;
   AfpTofHit_Bar = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("evN", &evN, &b_evN);
   fChain->SetBranchAddress("lmiBl", &lmiBl, &b_lmiBl);
   fChain->SetBranchAddress("mu", &mu, &b_mu);
   fChain->SetBranchAddress("timestamp", &timestamp, &b_timestamp);
   fChain->SetBranchAddress("bcid", &bcid, &b_bcid);
   fChain->SetBranchAddress("Trigger_L1_beforePrescale", &Trigger_L1_beforePrescale, &b_Trigger_L1_beforePrescale);
   fChain->SetBranchAddress("Trigger_L1_afterPrescale", &Trigger_L1_afterPrescale, &b_Trigger_L1_afterPrescale);
   fChain->SetBranchAddress("Trigger_HLT_isPrescaledOut", &Trigger_HLT_isPrescaledOut, &b_Trigger_HLT_isPrescaledOut);
   fChain->SetBranchAddress("Trigger_HLT_afterPrescale", &Trigger_HLT_afterPrescale, &b_Trigger_HLT_afterPrescale);
   fChain->SetBranchAddress("NVertex", &NVertex, &b_NVertex);
   fChain->SetBranchAddress("NInDetTrackParticles", &NInDetTrackParticles, &b_NInDetTrackParticles);
   fChain->SetBranchAddress("nhits", nhits, &b_nhits);
   fChain->SetBranchAddress("nclusters", nclusters, &b_nclusters);
   fChain->SetBranchAddress("ntracks", ntracks, &b_ntracks);
   fChain->SetBranchAddress("nprotons", nprotons, &b_nprotons);
   fChain->SetBranchAddress("NAfpProton", &NAfpProton, &b_NAfpProton);
   fChain->SetBranchAddress("AfpProton_Id", &AfpProton_Id, &b_AfpProton_Id);
   fChain->SetBranchAddress("AfpProton_Side", &AfpProton_Side, &b_AfpProton_Side);
   fChain->SetBranchAddress("AfpProton_Pt", &AfpProton_Pt, &b_AfpProton_Pt);
   fChain->SetBranchAddress("AfpProton_Px", &AfpProton_Px, &b_AfpProton_Px);
   fChain->SetBranchAddress("AfpProton_Py", &AfpProton_Py, &b_AfpProton_Py);
   fChain->SetBranchAddress("AfpProton_Pz", &AfpProton_Pz, &b_AfpProton_Pz);
   fChain->SetBranchAddress("AfpProton_E", &AfpProton_E, &b_AfpProton_E);
   fChain->SetBranchAddress("AfpProton_Eta", &AfpProton_Eta, &b_AfpProton_Eta);
   fChain->SetBranchAddress("AfpProton_Phi", &AfpProton_Phi, &b_AfpProton_Phi);
   fChain->SetBranchAddress("AfpProton_ChiSq", &AfpProton_ChiSq, &b_AfpProton_ChiSq);
   fChain->SetBranchAddress("NAfpTrack", &NAfpTrack, &b_NAfpTrack);
   fChain->SetBranchAddress("AfpTrack_Id", &AfpTrack_Id, &b_AfpTrack_Id);
   fChain->SetBranchAddress("AfpTrack_Station", &AfpTrack_Station, &b_AfpTrack_Station);
   fChain->SetBranchAddress("AfpTrack_X", &AfpTrack_X, &b_AfpTrack_X);
   fChain->SetBranchAddress("AfpTrack_Y", &AfpTrack_Y, &b_AfpTrack_Y);
   fChain->SetBranchAddress("AfpTrack_SX", &AfpTrack_SX, &b_AfpTrack_SX);
   fChain->SetBranchAddress("AfpTrack_SY", &AfpTrack_SY, &b_AfpTrack_SY);
   fChain->SetBranchAddress("NAfpCluster", &NAfpCluster, &b_NAfpCluster);
   fChain->SetBranchAddress("AfpCluster_Id", &AfpCluster_Id, &b_AfpCluster_Id);
   fChain->SetBranchAddress("AfpCluster_Station", &AfpCluster_Station, &b_AfpCluster_Station);
   fChain->SetBranchAddress("AfpCluster_Plane", &AfpCluster_Plane, &b_AfpCluster_Plane);
   fChain->SetBranchAddress("AfpCluster_X", &AfpCluster_X, &b_AfpCluster_X);
   fChain->SetBranchAddress("AfpCluster_Y", &AfpCluster_Y, &b_AfpCluster_Y);
   fChain->SetBranchAddress("AfpCluster_Z", &AfpCluster_Z, &b_AfpCluster_Z);
   fChain->SetBranchAddress("AfpCluster_Q", &AfpCluster_Q, &b_AfpCluster_Q);
   fChain->SetBranchAddress("AfpCluster_N", &AfpCluster_N, &b_AfpCluster_N);
   fChain->SetBranchAddress("nclusters_toolbox", nclusters_toolbox, &b_nclusters_toolbox);
   fChain->SetBranchAddress("ntracks_toolbox", ntracks_toolbox, &b_ntracks_toolbox);
   fChain->SetBranchAddress("nprotons_toolbox", nprotons_toolbox, &b_nprotons_toolbox);
   fChain->SetBranchAddress("NAfpToolboxProton", &NAfpToolboxProton, &b_NAfpToolboxProton);
   fChain->SetBranchAddress("AfpToolboxProton_Id", &AfpToolboxProton_Id, &b_AfpToolboxProton_Id);
   fChain->SetBranchAddress("AfpToolboxProton_Side", &AfpToolboxProton_Side, &b_AfpToolboxProton_Side);
   fChain->SetBranchAddress("AfpToolboxProton_Pt", &AfpToolboxProton_Pt, &b_AfpToolboxProton_Pt);
   fChain->SetBranchAddress("AfpToolboxProton_Px", &AfpToolboxProton_Px, &b_AfpToolboxProton_Px);
   fChain->SetBranchAddress("AfpToolboxProton_Py", &AfpToolboxProton_Py, &b_AfpToolboxProton_Py);
   fChain->SetBranchAddress("AfpToolboxProton_Pz", &AfpToolboxProton_Pz, &b_AfpToolboxProton_Pz);
   fChain->SetBranchAddress("AfpToolboxProton_E", &AfpToolboxProton_E, &b_AfpToolboxProton_E);
   fChain->SetBranchAddress("AfpToolboxProton_Eta", &AfpToolboxProton_Eta, &b_AfpToolboxProton_Eta);
   fChain->SetBranchAddress("AfpToolboxProton_Phi", &AfpToolboxProton_Phi, &b_AfpToolboxProton_Phi);
   fChain->SetBranchAddress("AfpToolboxProton_ChiSq", &AfpToolboxProton_ChiSq, &b_AfpToolboxProton_ChiSq);
   fChain->SetBranchAddress("NAfpToolboxTrack", &NAfpToolboxTrack, &b_NAfpToolboxTrack);
   fChain->SetBranchAddress("AfpToolboxTrack_Id", &AfpToolboxTrack_Id, &b_AfpToolboxTrack_Id);
   fChain->SetBranchAddress("AfpToolboxTrack_Station", &AfpToolboxTrack_Station, &b_AfpToolboxTrack_Station);
   fChain->SetBranchAddress("AfpToolboxTrack_X", &AfpToolboxTrack_X, &b_AfpToolboxTrack_X);
   fChain->SetBranchAddress("AfpToolboxTrack_Y", &AfpToolboxTrack_Y, &b_AfpToolboxTrack_Y);
   fChain->SetBranchAddress("AfpToolboxTrack_SX", &AfpToolboxTrack_SX, &b_AfpToolboxTrack_SX);
   fChain->SetBranchAddress("AfpToolboxTrack_SY", &AfpToolboxTrack_SY, &b_AfpToolboxTrack_SY);
   fChain->SetBranchAddress("NAfpToolboxCluster", &NAfpToolboxCluster, &b_NAfpToolboxCluster);
   fChain->SetBranchAddress("AfpToolboxCluster_Id", &AfpToolboxCluster_Id, &b_AfpToolboxCluster_Id);
   fChain->SetBranchAddress("AfpToolboxCluster_Station", &AfpToolboxCluster_Station, &b_AfpToolboxCluster_Station);
   fChain->SetBranchAddress("AfpToolboxCluster_Plane", &AfpToolboxCluster_Plane, &b_AfpToolboxCluster_Plane);
   fChain->SetBranchAddress("AfpToolboxCluster_X", &AfpToolboxCluster_X, &b_AfpToolboxCluster_X);
   fChain->SetBranchAddress("AfpToolboxCluster_Y", &AfpToolboxCluster_Y, &b_AfpToolboxCluster_Y);
   fChain->SetBranchAddress("AfpToolboxCluster_Z", &AfpToolboxCluster_Z, &b_AfpToolboxCluster_Z);
   fChain->SetBranchAddress("AfpToolboxCluster_Q", &AfpToolboxCluster_Q, &b_AfpToolboxCluster_Q);
   fChain->SetBranchAddress("AfpToolboxCluster_N", &AfpToolboxCluster_N, &b_AfpToolboxCluster_N);
   fChain->SetBranchAddress("NAfpHit", &NAfpHit, &b_NAfpHit);
   fChain->SetBranchAddress("AfpHit_Id", &AfpHit_Id, &b_AfpHit_Id);
   fChain->SetBranchAddress("AfpHit_Station", &AfpHit_Station, &b_AfpHit_Station);
   fChain->SetBranchAddress("AfpHit_Plane", &AfpHit_Plane, &b_AfpHit_Plane);
   fChain->SetBranchAddress("AfpHit_Row", &AfpHit_Row, &b_AfpHit_Row);
   fChain->SetBranchAddress("AfpHit_Col", &AfpHit_Col, &b_AfpHit_Col);
   fChain->SetBranchAddress("AfpHit_Q", &AfpHit_Q, &b_AfpHit_Q);
   fChain->SetBranchAddress("ntofhits", ntofhits, &b_ntofhits);
   fChain->SetBranchAddress("NAfpTofHit", &NAfpTofHit, &b_NAfpTofHit);
   fChain->SetBranchAddress("AfpTofHit_Station", &AfpTofHit_Station, &b_AfpTofHit_Station);
   fChain->SetBranchAddress("AfpTofHit_Time", &AfpTofHit_Time, &b_AfpTofHit_Time);
   fChain->SetBranchAddress("AfpTofHit_Train", &AfpTofHit_Train, &b_AfpTofHit_Train);
   fChain->SetBranchAddress("AfpTofHit_Length", &AfpTofHit_Length, &b_AfpTofHit_Length);
   fChain->SetBranchAddress("AfpTofHit_HptdcId", &AfpTofHit_HptdcId, &b_AfpTofHit_HptdcId);
   fChain->SetBranchAddress("AfpTofHit_Channel", &AfpTofHit_Channel, &b_AfpTofHit_Channel);
   fChain->SetBranchAddress("AfpTofHit_Bar", &AfpTofHit_Bar, &b_AfpTofHit_Bar);
   Notify();
}

Bool_t TrigCheck_1bunch::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void TrigCheck_1bunch::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t TrigCheck_1bunch::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef TrigCheck_1bunch_cxx
