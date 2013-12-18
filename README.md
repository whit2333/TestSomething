ATest Library
=============

Author: Whitney Armstrong (whit@temple.edu)

A minimal test of compiling shared libraries linked with ROOT 
that are then used with cling. 

Using the rootlogon_good.C the library works but using rootlogon_bad.C 
causes a crash. Note both call .rootconfiglib.C which needs to be fixed. 

