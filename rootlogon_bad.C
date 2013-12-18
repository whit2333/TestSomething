{
/**  Whitney Armstrong (whit@temple.edu)
 * 
 */
   //gStyle->Reset();
   gErrorIgnoreLevel=1; // Ignore Info
   //gErrorIgnoreLevel=1001; // Ignore Info
   //gErrorIgnoreLevel=2001; // Ignore Warnings
   //gSystem->Load("libMinuit2.so");
   gSystem->Load("libFoam");
   gSystem->Load("libTreeViewer");
   gSystem->Load("libEG");
   //gSystem->Load("libcurl.so");
   //gROOT->ProcessLine("#include <curl/curl.h>");
   //gSystem->Load("libPythia6"); // this has to be loaded before libInSANE ... don't know why
   //gSystem->Load("libEGPythia6");

   // Load ATest library
   gSystem->AddIncludePath(" -I/home/whit/TestSomething/include");
   gSystem->Load("libATest.so");

   gROOT->ProcessLine(".x /home/whit/.rootconfiglib.C");
   TNamed * something = new TNamed("someobject","ugh");
   std::cout << "hi" << std::endl;
   //gROOT->ProcessLine(".x /home/whit/.rootconfiglib.C");
}
