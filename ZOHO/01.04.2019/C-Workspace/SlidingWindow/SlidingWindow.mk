##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=SlidingWindow
ConfigurationName      :=Debug
WorkspacePath          :=F:/C-programs/ZOHO/01.04.2019/C-Workspace
ProjectPath            :=F:/C-programs/ZOHO/01.04.2019/C-Workspace/SlidingWindow
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=admin
Date                   :=02/04/2019
CodeLitePath           :=G:/CodeLite
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="SlidingWindow.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=G:\CodeLite
Objects0=$(IntermediateDirectory)/sample.c$(ObjectSuffix) $(IntermediateDirectory)/sliding.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/sample.c$(ObjectSuffix): sample.c $(IntermediateDirectory)/sample.c$(DependSuffix)
	$(CC) $(SourceSwitch) "F:/C-programs/ZOHO/01.04.2019/C-Workspace/SlidingWindow/sample.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sample.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sample.c$(DependSuffix): sample.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sample.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sample.c$(DependSuffix) -MM sample.c

$(IntermediateDirectory)/sample.c$(PreprocessSuffix): sample.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sample.c$(PreprocessSuffix) sample.c

$(IntermediateDirectory)/sliding.c$(ObjectSuffix): sliding.c $(IntermediateDirectory)/sliding.c$(DependSuffix)
	$(CC) $(SourceSwitch) "F:/C-programs/ZOHO/01.04.2019/C-Workspace/SlidingWindow/sliding.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sliding.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sliding.c$(DependSuffix): sliding.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sliding.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sliding.c$(DependSuffix) -MM sliding.c

$(IntermediateDirectory)/sliding.c$(PreprocessSuffix): sliding.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sliding.c$(PreprocessSuffix) sliding.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


