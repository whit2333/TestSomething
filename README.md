ATest Library
=============

Author: Whitney Armstrong (whit@temple.edu)

A minimal test of compiling shared libraries linked with ROOT 
that are then used with cling. 

Install
-------

Run 'make'. Then add the lib directory to your library path. For example:

    $LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/whit/TestSomething/lib

Using the rootlogon_good.C the library works but using rootlogon_bad.C 
causes a crash. Note both call .rootconfiglib.C which needs to be fixed. 


