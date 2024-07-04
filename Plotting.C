#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TEfficiency.h>

#include <iostream>
#include <TH2F.h>
#include <TStyle.h>
using namespace std;

void Plotting() {
    //List of triggers
  std::vector<std::string> m_allTriggers {"HLT_noalg_L1RD0_FILLED","HLT_noalg_mb_L1MBTS_1","HLT_noalg_mb_L1MBTS_2","HLT_noalg_J12","HLT_j20_L1J12",
    "HLT_j20_L1AFP_A_OR_C","HLT_j20_L1AFP_A_AND_C","HLT_j20f_L1AFP_A_OR_C","HLT_noalg_L1AFP_A_OR_C_J12","HLT_noalg_L1AFP_A_AND_C_J12","L1_AFP_A", "L1_AFP_C",
    "L1_AFP_A_OR_C","L1_AFP_A_AND_C","L1_AFP_NSA_BGRP12", "L1_AFP_NSC_BGRP12", "L1_AFP_FSA_BGRP12", "L1_AFP_FSC_BGRP12","HLT_noalg_AFPPEB_L1AFP_FSA_BGRP12",
    "HLT_noalg_AFPPEB_L1AFP_NSA_BGRP12","HLT_noalg_AFPPEB_L1AFP_NSC_BGRP12", "HLT_noalg_AFPPEB_L1AFP_FSC_BGRP12"};

   int ref_trig = 0;

   int nTriggers = m_allTriggers.size(); 


   std::vector<int> analyzed_triggers = {0,1,2,5,6,10,11,12,13,14,15,16,17,18,19,20,21};

   // Open the .root file
    int runnumber = 428770;
    string save_path = "/media/sergio/8e49a8ae-42cd-45af-8778-543c9c263d83/second_home/results";
    TFile* file = new TFile(Form("%s/%d/%s/output.root",save_path.c_str(),runnumber,m_allTriggers[ref_trig].c_str()), "READ");
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
   

    //Definition of bcid trains and crossing bunches
   std::vector<std::pair<int, int>> bcid_trains;
   std::vector<int> cross_bunches;

   if(runnumber==455818){
      bcid_trains.push_back(std::make_pair(86, 86));
      bcid_trains.push_back(std::make_pair(302, 467));
      bcid_trains.push_back(std::make_pair(1196, 1361));
      bcid_trains.push_back(std::make_pair(2090, 2255));

      cross_bunches={86, 302, 303, 304, 305, 306, 307, 308, 309, 314, 315, 316, 317, 318, 319, 320, 321, 326, 327, 328, 329, 330, 331, 332, 333, 338,
       339, 340, 341, 342, 343, 344, 345, 350, 351, 352, 353, 354, 355, 356, 357, 362, 363, 364, 365, 366, 367, 368, 369, 374, 375, 376, 377, 378, 379, 
       380, 381, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 
       416, 417, 418, 419, 420, 421, 422, 423, 424, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 
       452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 1196, 1197, 1198, 1199, 1200, 1201, 1202, 1203, 1208, 1209, 1210, 
       1211, 1212, 1213, 1214, 1215, 1220, 1221, 1222, 1223, 1224, 1225, 1226, 1227, 1232, 1233, 1234, 1235, 1236, 1237, 1238, 1239, 1244, 1245, 1246, 
       1247, 1248, 1249, 1250, 1251, 1256, 1257, 1258, 1259, 1260, 1261, 1262, 1263, 1268, 1269, 1270, 1271, 1272, 1273, 1274, 1275, 1283, 1284, 1285, 
       1286, 1287, 1288, 1289, 1290, 1291, 1292, 1293, 1294, 1295, 1296, 1297, 1298, 1299, 1300, 1301, 1302, 1303, 1304, 1305, 1306, 1307, 1308, 1309, 
       1310, 1311, 1312, 1313, 1314, 1315, 1316, 1317, 1318, 1326, 1327, 1328, 1329, 1330, 1331, 1332, 1333, 1334, 1335, 1336, 1337, 1338, 1339, 1340,
       1341, 1342, 1343, 1344, 1345, 1346, 1347, 1348, 1349, 1350, 1351, 1352, 1353, 1354, 1355, 1356, 1357, 1358, 1359, 1360, 1361, 1871, 2090, 2091, 
       2092, 2093, 2094, 2095, 2096, 2097, 2102, 2103, 2104, 2105, 2106, 2107, 2108, 2109, 2114, 2115, 2116, 2117, 2118, 2119, 2120, 2121, 2126, 2127, 
       2128, 2129, 2130, 2131, 2132, 2133, 2138, 2139, 2140, 2141, 2142, 2143, 2144, 2145, 2150, 2151, 2152, 2153, 2154, 2155, 2156, 2157, 2162, 2163, 
       2164, 2165, 2166, 2167, 2168, 2169, 2177, 2178, 2179, 2180, 2181, 2182, 2183, 2184, 2185, 2186, 2187, 2188, 2189, 2190, 2191, 2192, 2193, 2194, 
       2195, 2196, 2197, 2198, 2199, 2200, 2201, 2202, 2203, 2204, 2205, 2206, 2207, 2208, 2209, 2210, 2211, 2212, 2220, 2221, 2222, 2223, 2224, 2225, 
       2226, 2227, 2228, 2229, 2230, 2231, 2232, 2233, 2234, 2235, 2236, 2237, 2238, 2239, 2240, 2241, 2242, 2243, 2244, 2245, 2246, 2247, 2248, 2249, 
       2250, 2251, 2252, 2253, 2254, 2255};      
   }

    if(runnumber==428770){
      bcid_trains.push_back(std::make_pair(4, 15));
      bcid_trains.push_back(std::make_pair(257, 304));
      bcid_trains.push_back(std::make_pair(336, 383));
      bcid_trains.push_back(std::make_pair(415, 462));
      bcid_trains.push_back(std::make_pair(1151, 1198));
      bcid_trains.push_back(std::make_pair(1230, 1277));
      bcid_trains.push_back(std::make_pair(1309, 1356));
      bcid_trains.push_back(std::make_pair(2045, 2092));
      bcid_trains.push_back(std::make_pair(2124, 2171));
      bcid_trains.push_back(std::make_pair(2203, 2250));
      bcid_trains.push_back(std::make_pair(2939, 2986));
      bcid_trains.push_back(std::make_pair(3018, 3065));
      bcid_trains.push_back(std::make_pair(3097, 3144));

      cross_bunches={4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 
      275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 
      304, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 
      364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 415, 416, 417, 418, 419, 420, 421, 422, 423, 
      424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 
      453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 811, 1151, 1152, 1153, 1154, 1155, 1156, 1157, 1158, 1159, 1160, 1161, 1162, 1163, 1164, 1165, 
      1166, 1167, 1168, 1169, 1170, 1171, 1172, 1173, 1174, 1175, 1176, 1177, 1178, 1179, 1180, 1181, 1182, 1183, 1184, 1185, 1186, 1187, 1188, 1189, 
      1190, 1191, 1192, 1193, 1194, 1195, 1196, 1197, 1198, 1230, 1231, 1232, 1233, 1234, 1235, 1236, 1237, 1238, 1239, 1240, 1241, 1242, 1243, 1244, 
      1245, 1246, 1247, 1248, 1249, 1250, 1251, 1252, 1253, 1254, 1255, 1256, 1257, 1258, 1259, 1260, 1261, 1262, 1263, 1264, 1265, 1266, 1267, 1268, 
      1269, 1270, 1271, 1272, 1273, 1274, 1275, 1276, 1277, 1309, 1310, 1311, 1312, 1313, 1314, 1315, 1316, 1317, 1318, 1319, 1320, 1321, 1322, 1323, 
      1324, 1325, 1326, 1327, 1328, 1329, 1330, 1331, 1332, 1333, 1334, 1335, 1336, 1337, 1338, 1339, 1340, 1341, 1342, 1343, 1344, 1345, 1346, 1347, 
      1348, 1349, 1350, 1351, 1352, 1353, 1354, 1355, 1356, 2045, 2046, 2047, 2048, 2049, 2050, 2051, 2052, 2053, 2054, 2055, 2056, 2057, 2058, 2059, 
      2060, 2061, 2062, 2063, 2064, 2065, 2066, 2067, 2068, 2069, 2070, 2071, 2072, 2073, 2074, 2075, 2076, 2077, 2078, 2079, 2080, 2081, 2082, 2083, 
      2084, 2085, 2086, 2087, 2088, 2089, 2090, 2091, 2092, 2124, 2125, 2126, 2127, 2128, 2129, 2130, 2131, 2132, 2133, 2134, 2135, 2136, 2137, 2138, 
      2139, 2140, 2141, 2142, 2143, 2144, 2145, 2146, 2147, 2148, 2149, 2150, 2151, 2152, 2153, 2154, 2155, 2156, 2157, 2158, 2159, 2160, 2161, 2162, 
      2163, 2164, 2165, 2166, 2167, 2168, 2169, 2170, 2171, 2203, 2204, 2205, 2206, 2207, 2208, 2209, 2210, 2211, 2212, 2213, 2214, 2215, 2216, 2217, 
      2218, 2219, 2220, 2221, 2222, 2223, 2224, 2225, 2226, 2227, 2228, 2229, 2230, 2231, 2232, 2233, 2234, 2235, 2236, 2237, 2238, 2239, 2240, 2241, 
      2242, 2243, 2244, 2245, 2246, 2247, 2248, 2249, 2250, 2596, 2939, 2940, 2941, 2942, 2943, 2944, 2945, 2946, 2947, 2948, 2949, 2950, 2951, 2952, 
      2953, 2954, 2955, 2956, 2957, 2958, 2959, 2960, 2961, 2962, 2963, 2964, 2965, 2966, 2967, 2968, 2969, 2970, 2971, 2972, 2973, 2974, 2975, 2976, 
      2977, 2978, 2979, 2980, 2981, 2982, 2983, 2984, 2985, 2986, 3018, 3019, 3020, 3021, 3022, 3023, 3024, 3025, 3026, 3027, 3028, 3029, 3030, 3031, 
      3032, 3033, 3034, 3035, 3036, 3037, 3038, 3039, 3040, 3041, 3042, 3043, 3044, 3045, 3046, 3047, 3048, 3049, 3050, 3051, 3052, 3053, 3054, 3055, 
      3056, 3057, 3058, 3059, 3060, 3061, 3062, 3063, 3064, 3065, 3097, 3098, 3099, 3100, 3101, 3102, 3103, 3104, 3105, 3106, 3107, 3108, 3109, 3110, 
      3111, 3112, 3113, 3114, 3115, 3116, 3117, 3118, 3119, 3120, 3121, 3122, 3123, 3124, 3125, 3126, 3127, 3128, 3129, 3130, 3131, 3132, 3133, 3134, 
      3135, 3136, 3137, 3138, 3139, 3140, 3141, 3142, 3143, 3144};      
   }
   
   //Definition of integer counters and histograms counter for each trigger 
   TH2F *h_passTrg[nTriggers][4];
   TH2F *h_passSel[nTriggers][4];

   /*for(int tr=0;tr<nTriggers;tr++){
      for(int st=0;st<4;st++)
      {
            h_passTrg[tr][st] = new TH2F(Form("h_passTrg_%s_st%d",m_allTriggers[tr].c_str(),st),Form("h_passTrg_st%s_%d",m_allTriggers[tr].c_str(),st),nXbhmap,lowXbhmap,highXbhmap,nYbhmap,lowYbhmap,highYbhmap);
            h_passSel[tr][st] = new TH2F(Form("h_passSel_%s_st%d",m_allTriggers[tr].c_str(),st),Form("h_passSel_st%s_%d",m_allTriggers[tr].c_str(),st),nXbhmap,lowXbhmap,highXbhmap,nYbhmap,lowYbhmap,highYbhmap);
      }
   }*/

   //Definition of bcid histograms 
   
   TH1F *h_bcid_passTrg[nTriggers][4][bcid_trains.size()];
   TH1F *h_bcid_passSel[nTriggers][4][bcid_trains.size()];

   TH1F *h_bcid_inthits[nTriggers][4][4];

   /*for(int tr=0;tr<nTriggers;tr++){
      for(int bc=0;bc<bcid_trains.size();bc++)
      {
         for(int st=0;st<4;st++)
         {
            //h_bcid_passTrg[tr][st][bc] = new TH1F(Form("h_bcid_passTrg_%s_st%d_trn%d",m_allTriggers[tr].c_str(),st,bc),Form("h_bcid_passTrg_%s_st%d_trn%d",m_allTriggers[tr].c_str(),st,bc),bcid_trains[bc].second - bcid_trains[bc].first+1,bcid_trains[bc].first,bcid_trains[bc].second);
            h_bcid_passSel[tr][st][bc] = new TH1F(Form("h_bcid_passSel_%s_st%d_trn%d",m_allTriggers[tr].c_str(),st,bc),Form("h_bcid_passSel_%s_st%d_trn%d",m_allTriggers[tr].c_str(),st,bc),bcid_trains[bc].second - bcid_trains[bc].first+1,bcid_trains[bc].first,bcid_trains[bc].second);
            for(int pl=0;pl<4;pl++)
            {
               if(bc==0){h_bcid_inthits[tr][st][pl] = new TH1F(Form("h_bcid_inthits_%s_%d_%d",m_allTriggers[tr].c_str(),st,pl),Form("h_bcid_inthits_%s_%d_%d",m_allTriggers[tr].c_str(),st,pl),8,-0.5,7.5);}
            }
         }
      }
   }*/

   TEfficiency *effTrg[nTriggers][4];
   TEfficiency *effbcid[nTriggers][4][bcid_trains.size()];

   //Get the histograms from the file
    for(int tr=0;tr<nTriggers;tr++){
        if(!(std::find(analyzed_triggers.begin(),analyzed_triggers.end(),tr)!=analyzed_triggers.end())){continue;}
        for(int st=0;st<4;st++)
        {
            for(int bc=0;bc<bcid_trains.size();bc++)
            {
                h_bcid_passTrg[tr][st][bc] = (TH1F*)file->Get(Form("h_bcid_passTrg_%s_st%d_trn%d",m_allTriggers[tr].c_str(),st,bc));
                std::cout<<Form("h_bcid_passTrg_%s_st%d_trn%d",m_allTriggers[tr].c_str(),st,bc)<<std::endl;
                h_bcid_passSel[tr][st][bc] = (TH1F*)file->Get(Form("h_bcid_passSel_%s_st%d_trn%d",m_allTriggers[tr].c_str(),st,bc));
                //effbcid[tr][st][bc] = (TEfficiency*)file->Get(Form("effbcid_%s_st%d_bc%d",m_allTriggers[tr].c_str(),st,bc));
                effbcid[tr][st][bc] = (TEfficiency*)file->Get(Form("effbcid_%s_st%d_trn%d",m_allTriggers[tr].c_str(),st,bc));
            }
            for(int pl=0;pl<4;pl++)
            {
                h_bcid_inthits[tr][st][pl] = (TH1F*)file->Get(Form("h_bcid_inthits_%s_%d_%d",m_allTriggers[tr].c_str(),st,pl));
            }
            h_passTrg[tr][st] = (TH2F*)file->Get(Form("h_passTrg_%s_st%d",m_allTriggers[tr].c_str(),st));
            h_passSel[tr][st] = (TH2F*)file->Get(Form("h_passSel_%s_st%d",m_allTriggers[tr].c_str(),st));
            effTrg[tr][st] = (TEfficiency*)file->Get(Form("effTrg_%s_st%d",m_allTriggers[tr].c_str(),st));
        }
    }    

    // For coloring. Yellow filled crossing bunches, gray non filled bunches
    TH1F *h_bcid_cross_bunches[bcid_trains.size()];
    TH1F *h_bcid_all_bunches[bcid_trains.size()];
    for(int bc=0;bc<bcid_trains.size();bc++)
    {
        h_bcid_cross_bunches[bc] = new TH1F(Form("h_bcid_cross_bunches_trn%d",bc),Form("h_bcid_cross_bunches_trn%d",bc),bcid_trains[bc].second - bcid_trains[bc].first+1,bcid_trains[bc].first,bcid_trains[bc].second);
        h_bcid_all_bunches[bc] = new TH1F(Form("h_bcid_all_bunches_trn%d",bc),Form("h_bcid_all_bunches_trn%d",bc),bcid_trains[bc].second - bcid_trains[bc].first+1,bcid_trains[bc].first,bcid_trains[bc].second);
       
        //Coloring the bins that are in cross_bunches with full boxes 
        h_bcid_cross_bunches[bc]->SetFillColor(kYellow);
        h_bcid_all_bunches[bc]->SetFillColor(kGray);
       
        for(int bcid=bcid_trains[bc].first;bcid<=bcid_trains[bc].second;bcid++)
        {
            if(std::find(cross_bunches.begin(),cross_bunches.end(),bcid)!=cross_bunches.end())
            {
                h_bcid_cross_bunches[bc]->SetBinContent(bcid-bcid_trains[bc].first+1,10000);
                h_bcid_all_bunches[bc]->SetBinContent(bcid-bcid_trains[bc].first+1,10000);
            }
            else
            {
                h_bcid_all_bunches[bc]->SetBinContent(bcid-bcid_trains[bc].first+1,10000);
            }
        }
    }

    //Print number of entries of each histogram
    for(int tr=0;tr<nTriggers;tr++){
        if(!(std::find(analyzed_triggers.begin(),analyzed_triggers.end(),tr)!=analyzed_triggers.end())){continue;}
        for(int st=0;st<4;st++)
        {
            std::cout << "Number of entries in h_passTrg_" << m_allTriggers[tr] << "_st" << st << ": " << h_passTrg[tr][st]->GetEntries() << std::endl;
            std::cout << "Number of entries in h_passSel_" << m_allTriggers[tr] << "_st" << st << ": " << h_passSel[tr][st]->GetEntries() << std::endl;
            //Print the efficiencies
            std::cout << "Number of entries in effTrg_" << m_allTriggers[tr] << "_st" << st << ": " << effTrg[tr][st]->GetTotalHistogram()->GetEntries() << std::endl;
            for(int bc=0;bc<bcid_trains.size();bc++)
            {
                std::cout << "Number of entries in h_bcid_passTrg_" << m_allTriggers[tr] << "_st" << st << "_trn" << bc << ": " << h_bcid_passTrg[tr][st][bc]->GetEntries() << std::endl;
                std::cout << "Number of entries in h_bcid_passSel_" << m_allTriggers[tr] << "_st" << st << "_trn" << bc << ": " << h_bcid_passSel[tr][st][bc]->GetEntries() << std::endl;
            }
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
            TCanvas* c = new TCanvas(Form("c_%s_st%d",m_allTriggers[tr].c_str(),st),Form("c_%s_st%d",m_allTriggers[tr].c_str(),st),800,600);
            h_passTrg[tr][st]->Draw("colz");
            c->SaveAs(Form("%s/%d/%s/distributions/h_passTrg_%s_st%d.pdf",save_path.c_str(),runnumber,m_allTriggers[ref_trig].c_str(),m_allTriggers[tr].c_str(),st));
            h_passSel[tr][st]->Draw("colz");
            c->SaveAs(Form("%s/%d/%s/distributions/h_passSel_%s_st%d.pdf",save_path.c_str(),runnumber,m_allTriggers[ref_trig].c_str(),m_allTriggers[tr].c_str(),st));
            effTrg[tr][st]->Draw();
            c->SaveAs(Form("%s/%d/%s/efficiency_distributions/2D/effTrg_%s_st%d.pdf",save_path.c_str(),runnumber,m_allTriggers[ref_trig].c_str(),m_allTriggers[tr].c_str(),st));
            for(int bc=0;bc<bcid_trains.size();bc++)
            {
                if(runnumber == 455818 && bc == 0){continue;}
                h_bcid_all_bunches[bc]->SetMaximum(0.55);
                //Colour scheme
                h_bcid_all_bunches[bc]->Draw();
                h_bcid_cross_bunches[bc]->Draw("same");
                //Axis labels
                h_bcid_passTrg[tr][st][bc]->GetXaxis()->SetTitle("BCID");
                h_bcid_passTrg[tr][st][bc]->GetYaxis()->SetTitle("Events passed trigger");
                //Draw
                h_bcid_passTrg[tr][st][bc]->Draw("same E");
                c->SaveAs(Form("%s/%d/%s/bcid/h_bcid_passTrg_%s_st%d_trn%d.pdf",save_path.c_str(),runnumber,m_allTriggers[ref_trig].c_str(),m_allTriggers[tr].c_str(),st,bc));

                h_bcid_all_bunches[bc]->Draw();
                h_bcid_cross_bunches[bc]->Draw("same");
                h_bcid_passSel[tr][st][bc]->GetXaxis()->SetTitle("BCID");
                h_bcid_passSel[tr][st][bc]->GetYaxis()->SetTitle("Events passed selection");
                h_bcid_passSel[tr][st][bc]->Draw("same E");
                c->SaveAs(Form("%s/%d/%s/bcid/h_bcid_passSel_%s_st%d_trn%d.pdf",save_path.c_str(),runnumber,m_allTriggers[ref_trig].c_str(),m_allTriggers[tr].c_str(),st,bc));

                h_bcid_all_bunches[bc]->GetXaxis()->SetTitle("BCID");
                h_bcid_all_bunches[bc]->GetYaxis()->SetTitle("Efficiency");
                h_bcid_all_bunches[bc]->Draw();
                h_bcid_cross_bunches[bc]->Draw("same");
                effbcid[tr][st][bc]->Draw("same E");
                c->SaveAs(Form("%s/%d/%s/bcid/effbcid_%s_st%d_bc%d.pdf",save_path.c_str(),runnumber,m_allTriggers[ref_trig].c_str(),m_allTriggers[tr].c_str(),st,bc));
            }
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
                h_bcid_inthits[tr][st][pl]->GetXaxis()->SetBinLabel(6,"BCID_f-2");
                h_bcid_inthits[tr][st][pl]->GetXaxis()->SetBinLabel(7,"BCID_f-1");
                h_bcid_inthits[tr][st][pl]->GetXaxis()->SetBinLabel(8,"BCID_f");
                h_bcid_inthits[tr][st][pl]->GetXaxis()->SetBinLabel(9,"BCID_f+1");
                h_bcid_inthits[tr][st][pl]->GetXaxis()->SetBinLabel(10,"BCID_f+2");

                h_bcid_inthits[tr][st][pl]->GetYaxis()->SetTitle("Events (normalized to 1)");
                h_bcid_inthits[tr][st][pl]->Draw();
                c_inth->SaveAs(Form("%s/%d/%s/int_hits/h_bcid_inthits_%s_%d_%d.pdf",save_path.c_str(),runnumber,m_allTriggers[ref_trig].c_str(),m_allTriggers[tr].c_str(),st,pl));
            }
        }
    }
    file->Close();
}

int main() {
    Plotting();
    return 0;
}