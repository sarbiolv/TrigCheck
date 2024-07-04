#define TrigCheck_1bunch_cxx
#include "TrigCheck_1bunch.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

//Check if a trigger is passed using *Trigger_L1_beforePrescale. Takes as input a boolean vector where the results are stored
void TrigCheck_1bunch::CheckTrigger(std::vector<bool> &passTrg, std::vector<std::string> m_allTriggers){
   for(int tr=0;tr<m_allTriggers.size();tr++){
      if(Trigger_L1_beforePrescale->at(tr)){
         passTrg[tr] = true;
      }
   }
   
}

//Check which stations are active in the event. Takes as input a boolean vector where the results are stored. Check is performed 
//by checking if certain planes has registered hits
void TrigCheck_1bunch::CheckStations(std::vector<bool> &activeSt){
   //Loop over stations
   for(int st=0;st<4;st++){
      bool activePl[4] = {false,false,false,false};
      for(int pl=0;pl<4;pl++){
         //Checks if there are hits in the planes using Int_t           nhits[4][4];
         if(nhits[st][pl]>0){
            activePl[pl] = true;
         }
      }
      
      //if(st==0 && (activePl[0] + activePl[1] + activePl[3])>=2){ //455818
      if(st==0 && (activePl[0] + activePl[1] + activePl[2])>=2){ //428770
         activeSt[st] = true;
      }
      //if(st==1 && (activePl[1] + activePl[2] + activePl[3])>=2){ //455818
      if(st==1 && (activePl[0] + activePl[1] + activePl[2])>=2){   //428770  
         activeSt[st] = true;
      }
      //if(st==2 && (activePl[0] + activePl[1] + activePl[2])>=2){ //455818
      if(st==2 && (activePl[0] + activePl[1] + activePl[2])>=2){   //428770
         activeSt[st] = true;
      }
      //if(st==3 && (activePl[0] + activePl[1] + activePl[2])>=2){ //455818
      if(st==3 && (activePl[0] + activePl[1] + activePl[2])>=2){   //428770
         activeSt[st] = true;
      }
   }
}

//Takes bcid and bcid train and returns the number of the train
int TrigCheck_1bunch::GetTrain(int bcid, std::vector<std::pair<int, int>> bcid_trains){
   for(int tr=0;tr<bcid_trains.size();tr++){
      if(bcid>=bcid_trains[tr].first && bcid<=bcid_trains[tr].second){
         return tr;
      }
   }
   return -1;
}
//Takes bcid and bcid train and returns an integer from 0 to 7, each meaning:
//0: 2 bcid before the train 1: 1 bcid before the train 2: first bcid of the train 3: 2 bcid of the train
//4: 2 bcid before the end of the train 5: 1 bcid before the end of the train 6: 1 bcid after the end of the train 7: 2 bcid after the end of the train
int TrigCheck_1bunch::GetCrossBunch(int bcid, int single_bunch){
      if(bcid==single_bunch-2){
         return 0;
      }
      if(bcid==single_bunch-1){
         return 1;
      }
      if(bcid==single_bunch){
         return 2;
      }
      if(bcid==single_bunch+1){
         return 3;
      }
      if(bcid==single_bunch+2){
         return 4;
      }
   return -1;
}
   
   

void TrigCheck_1bunch::Loop()
{
//   In a ROOT session, you can do:
//      root> .L TrigCheck.C
//      root> TrigCheck t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

  int runnumber = 428770;

  //List of triggers
  std::vector<std::string> m_allTriggers {"HLT_noalg_L1RD0_FILLED","HLT_noalg_mb_L1MBTS_1","HLT_noalg_mb_L1MBTS_2","HLT_noalg_J12","HLT_j20_L1J12",
    "HLT_j20_L1AFP_A_OR_C","HLT_j20_L1AFP_A_AND_C","HLT_j20f_L1AFP_A_OR_C","HLT_noalg_L1AFP_A_OR_C_J12","HLT_noalg_L1AFP_A_AND_C_J12","L1_AFP_A", "L1_AFP_C",
    "L1_AFP_A_OR_C","L1_AFP_A_AND_C","L1_AFP_NSA_BGRP12", "L1_AFP_NSC_BGRP12", "L1_AFP_FSA_BGRP12", "L1_AFP_FSC_BGRP12","HLT_noalg_AFPPEB_L1AFP_FSA_BGRP12",
    "HLT_noalg_AFPPEB_L1AFP_NSA_BGRP12","HLT_noalg_AFPPEB_L1AFP_NSC_BGRP12", "HLT_noalg_AFPPEB_L1AFP_FSC_BGRP12"};

   int nTriggers = m_allTriggers.size(); 
   int ref_trig = 21;

   std::vector<int> analyzed_triggers = {18,19,20,21};

  //Definition of dimensions constants
   float lowXbhmap = -16.8,
        highXbhmap = 0,
        lowYbhmap = 0.0, 
        highYbhmap = 20.0;


   int nXbhmap = 336,
        nYbhmap = 81;
   
   //Definition of lmiBl limits 
   int lowLmiBl = 0;
   int highLmiBl = 1;
   if(runnumber==455818){
      lowLmiBl = 144;
      highLmiBl = 438;
   }
   if(runnumber==428770){
      lowLmiBl = 206;
      highLmiBl = 326;
   }
   int single_bunch=-1;

   if(runnumber==455818){
      single_bunch = 86;    
   }

   if(runnumber==428770){
      single_bunch = 811;      
   }

   //Definition of bcid histograms 

   TH1F *h_bcid_inthits[nTriggers][4][4];

   for(int tr=0;tr<nTriggers;tr++){
      for(int st=0;st<4;st++)
      {
         for(int pl=0;pl<4;pl++)
         {
            h_bcid_inthits[tr][st][pl] = new TH1F(Form("h_bcid_inthits_%s_%d_%d",m_allTriggers[tr].c_str(),st,pl),Form("h_bcid_inthits_%s_%d_%d",m_allTriggers[tr].c_str(),st,pl),5,-0.5,4.5);
         }
      }  
   }

   
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      //Add output each 10000 events 
      if(jentry%10000==0) {std::cout << "Processing event " << jentry << std::endl;}
      //Check lumiblock range
      if(lmiBl<lowLmiBl || lmiBl>highLmiBl) {continue;}

      //Check which triggers are passed
      std::vector<bool> b_passTrg(nTriggers, false);
      CheckTrigger(b_passTrg,m_allTriggers);

      if(b_passTrg[10] && b_passTrg[11] && !b_passTrg[13]){std::cout<<m_allTriggers[10]<<" "<<b_passTrg[10]<<" "<<m_allTriggers[11]<<" "<<b_passTrg[11]<<" "<<m_allTriggers[13]<<b_passTrg[13]<<" "<<std::endl;}
      if(((!b_passTrg[10]) || (!b_passTrg[11])) && b_passTrg[13]){std::cout<<m_allTriggers[10]<<" "<<b_passTrg[10]<<" "<<m_allTriggers[11]<<" "<<b_passTrg[11]<<" "<<m_allTriggers[13]<<b_passTrg[13]<<" "<<std::endl;}

      //Check which stations are active
      std::vector<bool> activeSt(nTriggers, false);
      CheckStations(activeSt);

      //Check if the event pass selection
      std::vector<bool> b_passSel(nTriggers, false);

      //random trigger pass selection if the event pass the trigger
      if(b_passTrg[ref_trig]){b_passSel[0] = true;}
      if(b_passTrg[ref_trig]){b_passSel[1] = true;}
      if(b_passTrg[ref_trig]){b_passSel[2] = true;}

      //Check if the event pass the selection depending on the active stations 
      if((activeSt[0] && activeSt[1]) || (activeSt[2] && activeSt[3])){b_passSel[5] = true;}
      if(activeSt[0] && activeSt[1] && activeSt[2] && activeSt[3]){b_passSel[6] = true;}
      if(activeSt[0] && activeSt[1]){b_passSel[10] = true;}
      if(activeSt[2] && activeSt[3]){b_passSel[11] = true;}
      if((activeSt[0] && activeSt[1]) || (activeSt[2] && activeSt[3])){b_passSel[12] = true;}
      if(activeSt[0] && activeSt[1] && activeSt[2] && activeSt[3]){b_passSel[13] = true;}
      if(activeSt[1]){b_passSel[14] = true;}
      if(activeSt[2]){b_passSel[15] = true;}
      if(activeSt[0]){b_passSel[16] = true;}
      if(activeSt[3]){b_passSel[17] = true;}
      if(activeSt[0]){b_passSel[18] = true;}
      if(activeSt[1]){b_passSel[19] = true;}
      if(activeSt[2]){b_passSel[20] = true;}
      if(activeSt[3]){b_passSel[21] = true;}

      //Check if triggers are passed when selection is not passed
      if(!b_passSel[10] && b_passTrg[10]){std::cout<<"Trigger: "<<m_allTriggers[10]<<" pass but does not pass selection"<<std::endl;}
      if(!b_passSel[11] && b_passTrg[11]){std::cout<<"Trigger: "<<m_allTriggers[11]<<" pass but does not pass selection"<<std::endl;}
      if(!b_passSel[12] && b_passTrg[12]){std::cout<<"Trigger: "<<m_allTriggers[12]<<" pass but does not pass selection"<<std::endl;}
      if(!b_passSel[13] && b_passTrg[13]){std::cout<<"Trigger: "<<m_allTriggers[13]<<" pass but does not pass selection"<<std::endl;}
     
      //Loop over triggers
      for(int tr=0;tr<nTriggers;tr++){
         //Check if the trigger is to be analyzed
         if(!(std::find(analyzed_triggers.begin(),analyzed_triggers.end(),tr)!=analyzed_triggers.end())){continue;}
           
         int bcid_case = GetCrossBunch(bcid,single_bunch); //We get the case of our bcid
         if(b_passTrg[tr] && b_passSel[tr]){
            if(bcid_case>=0){
               for(int st=0;st<4;st++){
                  for(int pl=0;pl<4;pl++){
                    h_bcid_inthits[tr][st][pl]->Fill(bcid_case);
                  }
               }
            }
         }   
      }

   }

   std::cout<<"Number of entries: "<<nentries<<std::endl;

   //Save the histograms in a file
   TFile *f = new TFile(Form("results/%d/%s/single_bunch/output.root",runnumber,m_allTriggers[ref_trig].c_str()),"recreate");
   f->cd();
   for(int tr=0;tr<nTriggers;tr++){
      //Check if the trigger is to be analyzed
      if(!(std::find(analyzed_triggers.begin(),analyzed_triggers.end(),tr)!=analyzed_triggers.end())){continue;}
      for(int st=0;st<4;st++){
         for(int pl=0;pl<4;pl++){
            h_bcid_inthits[tr][st][pl]->Write();
         }
      }
   }
   f->Close();
}

int main(int argc, char *argv[]){
   TrigCheck_1bunch t;
   t.Loop();
   return 0;
}