SHELL = /bin/bash
.SUFFIXES: .C .o .h .so 
VPATH = lib:src:include:
DESTDIR = bin 
basedir := ./
incdir := include
srcdir := src
builddir := lib

PROJECTNAME := ATest
LIBNAME	  := ATest

SOLIBNAMES := ATestGeneral
LIBRARY	  = lib$(LIBNAME).so
LIBMAJOR  = 1
LIBOBJS	  = 1
LIBMINOR  = 1
LIBREVIS  = 0
SOLIBS := $(SOLIBNAMES:%=lib/lib%.so.$(LIBMAJOR).$(LIBMINOR) )
SOLINKLIBS := $(SOLIBNAMES:%=-Llib/lib%.so.$(LIBMAJOR).$(LIBMINOR) )


RCINTFLAGS += -c 
#RCINTFLAGS += -DDebug 

CPPFLAGS += $(shell root-config --cflags )
CPPFLAGS += -Iinclude -I.
CPPFLAGS +=  -g -pipe  
#-D_LARGEFILE_SOURCE -fno-strict-aliasing

CPPFLAGS += -D"ATest_DATA_DIR=\"$(shell echo ${ATest_DATA_DIR})\"" 
#RCINTFLAGS += -D'ATest_DATA_DIR=$(shell echo ${ATest_DATA_DIR})' 

LDLIBS += $(shell root-config --ldflags)
LDLIBS += $(shell root-config --glibs --libs )
#LDLIBS += -lgfortran
#LDLIBS += -lg2c -lgfortran

CXX = g++
FC  = gfortran

CXXFLAGS  += -O2 -Wall -fPIC 
CXXFLAGS  += $(CPPFLAGS)

F77FLAGS += -g -O2 -Wall -fPIC -Iinclude 

##############################################################################/

default : atest link

atest : shared_libs
	@echo 
	@echo === Building binary ===
	@echo 
	g++ -o atest ATest.C $(CXXFLAGS) $(LDLIBS) $(SOLIBS)
	mv atest bin/.


# Shared Libraries
##############################################################################/

convert : $(SOLIBNAMES)
	g++ $(CXXFLAGS) -shared  -Wl,-soname,$(LIBRARY).$(LIBMAJOR).$(LIBMINOR)\
	 -o lib/$(LIBRARY).$(LIBMAJOR).$(LIBMINOR)  \
	  $(SOLIBS) $(LDLIBS) 


# Shared Libraries
##############################################################################/

shared_libs : $(SOLIBNAMES)
	@echo 
	@echo === Building main shared library ===
	@echo 
	g++ $(CXXFLAGS) -shared  -Wl,-soname,$(LIBRARY).$(LIBMAJOR).$(LIBMINOR)\
          -o lib/$(LIBRARY).$(LIBMAJOR).$(LIBMINOR)  \
            $(LDLIBS) lib/*.o
#            $(SOLIBS) $(LDLIBS) lib/*.o
#	ln -s $(builddir)/libInSANE.so.1.1 $(builddir)/libInSANE.so
#	ln -s $(builddir)/libInSANE.so.1.1 $(builddir)/libInSANE.so.1
#	ln -s $(builddir)/libInSANE.so.1.1 $(builddir)/libInSANE.so
#_____________________________________________________________________________/
# Utilitiy
##############################################################################/

doc: 
	doxygen doc/Doxyfile_ATest #	doxygen doc/Doxyfile_insaneweb
	@echo "HTML Documentation created"

.PHONY : clean printstuff doc snapshot

snapshot:
	git archive HEAD --format=tar | gzip >ATest-`date +%m_%d_%Y_`.tar.gz

#git archive HEAD --format=tar | gzip >InSANE-`date +%m_%d_%Y_`.tar.gz

clean:
	rm -f lib/libATest*
	rm -f lib/InSANE*Dict.o
	rm -f lib/*.o
	rm -f bin/atest
	rm -f src/*Dict.cxx
	rm -f include/*Dict.h 

printstuff : 
	@echo $(SOLIBS)
#	@ls lib/*.o

makefiledir := build
include  $(makefiledir)/General.mk

link:
	cd lib/ ; ln -sf libATestGeneral.so.$(LIBMAJOR).$(LIBMINOR) libATestGeneral.so
	cd lib/ ; ln -sf libATest.so.$(LIBMAJOR).$(LIBMINOR) libATest.so
# 	cp lib/*.so $(HOME)/lib/.
# 	cp lib/*.so.* $(HOME)/lib/.
# 	cd lib/ ; ln -sf libInSANECut.so.$(LIBMAJOR).$(LIBMINOR) libInSANECut.so
# 	cd lib/ ; ln -sf libInSANEGeo.so.$(LIBMAJOR).$(LIBMINOR) libInSANEGeo.so
# 	cd lib/ ; ln -sf libInSANECluster.so.$(LIBMAJOR).$(LIBMINOR) libInSANECluster.so
# 	cd lib/ ; ln -sf libInSANEEvent.so.$(LIBMAJOR).$(LIBMINOR) libInSANEEvent.so
# 	cd lib/ ; ln -sf libInSANE.so.$(LIBMAJOR).$(LIBMINOR) libInSANE.so
