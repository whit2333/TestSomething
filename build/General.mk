
GeneralLibName := ATestGeneral

GeneralLibObjs := lib/TestSomething.o 

FortranLibObjs := 

$(FortranLibObjs) : $(builddir)/%.o :
	$(FC) -c $(F77FLAGS) -o $@  $(@:$(builddir)/%.o=$(srcdir)/%.f)


GeneralLibHead := $(GeneralLibObjs:lib/%.o=$(incdir)/%.h)

$(GeneralLibObjs) : $(builddir)/%.o : %.h
	$(CXX) $(CXXFLAGS) -c -o $@  $(@:$(builddir)/%.o=$(srcdir)/%.C)

#$(srcdir)/$(GeneralLibName)Dict.cxx $(srcdir)/$(GeneralLibName)Dict.h : $(GeneralLibHead)\

$(srcdir)/$(GeneralLibName)Dict.cxx : $(GeneralLibHead) $(incdir)/$(GeneralLibName)_LinkDef.h 
	rootcling -v4 -f $(srcdir)/$(GeneralLibName)Dict.cxx $(RCINTFLAGS)  \
	$(GeneralLibHead)   $(incdir)/$(GeneralLibName)_LinkDef.h 
	#mv $(srcdir)/$(GeneralLibName)Dict.h $(incdir)/.
#_____________________________________________________________________________/
#$(builddir)/$(GeneralLibName)Dict.o : $(GeneralLibName)Dict.cxx $(incdir)/$(GeneralLibName)Dict.h

$(builddir)/$(GeneralLibName)Dict.o : $(GeneralLibName)Dict.cxx 
	$(CXX) $(CXXFLAGS) -c -fPIC -o $@  $(srcdir)/$(GeneralLibName)Dict.cxx 
#_____________________________________________________________________________/
$(GeneralLibName) : $(GeneralLibObjs) $(builddir)/$(GeneralLibName)Dict.o $(FortranLibObjs)
	g++ $(CXXFLAGS) -shared  -Wl,-soname,lib$(GeneralLibName).so.$(LIBMAJOR).$(LIBMINOR) -o \
        lib/lib$(GeneralLibName).so.$(LIBMAJOR).$(LIBMINOR) $(GeneralLibObjs) $(builddir)/$(GeneralLibName)Dict.o $(FortranLibObjs)  $(LDLIBS)
