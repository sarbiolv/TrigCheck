#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TEfficiency.h>

#include <iostream>
#include <TH2F.h>
#include <TStyle.h>
using namespace std;

void Plotting_1bunch() {
    //List of triggers
  std::vector<std::string> m_allTriggers {"HLT_noalg_L1RD0_FILLED","HLT_noalg_mb_L1MBTS_1","HLT_noalg_mb_L1MBTS_2","HLT_noalg_J12","HLT_j20_L1J12",
    "HLT_j20_L1AFP_A_OR_C","HLT_j20_L1AFP_A_AND_C","HLT_j20f_L1AFP_A_OR_C","HLT_noalg_L1AFP_A_OR_C_J12","HLT_noalg_L1AFP_A_AND_C_J12","L1_AFP_A", "L1_AFP_C",
    "L1_AFP_A_OR_C","L1_AFP_A_AND_C","L1_AFP_NSA_BGRP12", "L1_AFP_NSC_BGRP12", "L1_AFP_FSA_BGRP12", "L1_AFP_FSC_BGRP12","HLT_noalg_AFPPEB_L1AFP_FSA_BGRP12",
    "HLT_noalg_AFPPEB_L1AFP_NSA_BGRP12","HLT_noalg_AFPPEB_L1AFP_NSC_BGRP12", "HLT_noalg_AFPPEB_L1AFP_FSC_BGRP12"};

   int ref_trig = 21;

   int nTriggers = m_allTriggers.size(); 


   std::vector<int> analyzed_triggers = {18,19,20,21};

   // Open the .root file
    int runnumber = 428770;
    TFile* file = new TFile(Form("results/%d/%s/single_bunch/output.root",runnumber,m_allTriggers[ref_trig].c_str()), "READ");

    // Check if the file is open
    if (!file || file->IsZombie()) {
        std::cout << "Error opening file!" << std::endl;
        return;
    }


   float lowXbhmap = -16.8,
        highXbhmap = 0,
        lowYbhmap = 0.0, 
        highYbhmap = 20.0;


   int nXbhmap = 336,
        nYbhmap = 81;    
   

    int single_bunch=-1;

   if(runnumber==455818){
      single_bunch = 86;    
   }

   if(runnumber==428770){
      single_bunch = 811;      
   }

   TH1F *h_bcid_inthits[nTriggers][4][4];

   //Get the histograms from the file
    for(int tr=0;tr<nTriggers;tr++){
        if(!(std::find(analyzed_triggers.begin(),analyzed_triggers.end(),tr)!=analyzed_triggers.end())){continue;}
        for(int st=0;st<4;st++)
        {
            for(int pl=0;pl<4;pl++)
            {
                h_bcid_inthits[tr][st][pl] = (TH1F*)file->Get(Form("h_bcid_inthits_%s_%d_%d",m_allTriggers[tr].c_str(),st,pl));
            }
        }
    }    

    //Print number of entries of each histogram
    for(int tr=0;tr<nTriggers;tr++){
        if(!(std::find(analyzed_triggers.begin(),analyzed_triggers.end(),tr)!=analyzed_triggers.end())){continue;}
        for(int st=0;st<4;st++)
        {
            for(int pl=0;pl<4;pl++)
            {
                std::cout << "Number of entries in h_bcid_inthits_" << m_allTriggers[tr] << "_" << st << "_" << pl << ": " << h_bcid_inthits[tr][st][pl]->GetEntries() << std::endl;
            }
        }
    }
    //Change color palette
    gStyle->SetPalette(kRainbow);
    //Plot the histograms each in its own .pdf file
    for(int tr=0;tr<nTriggers;tr++){
        if(!(std::find(analyzed_triggers.begin(),analyzed_triggers.end(),tr)!=analyzed_triggers.end())){continue;}
        for(int st=0;st<4;st++)
        {
            for(int pl=0;pl<4;pl++)
            {
                TCanvas* c_inth = new TCanvas(Form("c_inth_%s_st%d",m_allTriggers[tr].c_str(),st),Form("c_inth_%s_st%d",m_allTriggers[tr].c_str(),st),800,600);
                c_inth->SetLogy();
                //Divide histogram per number of entries
                h_bcid_inthits[tr][st][pl]->Sumw2();
                h_bcid_inthits[tr][st][pl]->Scale(1/h_bcid_inthits[tr][st][pl]->GetEntries());
                //Axis labels
                h_bcid_inthits[tr][st][pl]->GetXaxis()->SetTitle("BCID type");
                //Set labels per bin
                h_bcid_inthits[tr][st][pl]->GetXaxis()->SetBinLabel(1,"BCID_i-2");
                h_bcid_inthits[tr][st][pl]->GetXaxis()->SetBinLabel(2,"BCID_i-1");
                h_bcid_inthits[tr][st][pl]->GetXaxis()->SetBinLabel(3,"BCID_i");
                h_bcid_inthits[tr][st][pl]->GetXaxis()->SetBinLabel(4,"BCID_i+1");
                h_bcid_inthits[tr][st][pl]->GetXaxis()->SetBinLabel(5,"BCID_i+2");

                h_bcid_inthits[tr][st][pl]->GetYaxis()->SetTitle("Events (normalized to 1)");
                h_bcid_inthits[tr][st][pl]->Draw();
                c_inth->SaveAs(Form("results/%d/%s/single_bunch/int_hits/h_bcid_inthits_%s_%d_%d.pdf",runnumber,m_allTriggers[ref_trig].c_str(),m_allTriggers[tr].c_str(),st,pl));
            }
        }
    }
    file->Close();
}

int main() {
    Plotting_1bunch();
    return 0;
}