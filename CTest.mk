##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=CTest
ConfigurationName      :=Debug
WorkspacePath          := "D:\gitprogramme\CTest"
ProjectPath            := "D:\gitprogramme\CTest"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Sascha
Date                   :=11/10/14
CodeLitePath           :="F:\Programme\CodeLite"
LinkerName             :=F:/Programme/MiniGW/bin/g++.exe 
SharedObjectLinkerName :=F:/Programme/MiniGW/bin/g++.exe -shared -fPIC
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
ObjectsFileList        :="CTest.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=F:/Programme/MiniGW/bin/windres.exe 
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)D:/glfw32/include/ $(IncludeSwitch)D:/glfw64/include/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)opengl32 $(LibrarySwitch)gdi32 $(LibrarySwitch)glfw3 
ArLibs                 :=  "opengl32.dll" "gdi32.dll" "glfw3" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)D:/glfw32/lib $(LibraryPathSwitch)D:/glfw64/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := F:/Programme/MiniGW/bin/ar.exe rcu
CXX      := F:/Programme/MiniGW/bin/g++.exe 
CC       := F:/Programme/MiniGW/bin/gcc.exe 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -Wall -O0  $(Preprocessors)
ASFLAGS  := 
AS       := F:/Programme/MiniGW/bin/as.exe 


##
## User defined environment variables
##
CodeLiteDir:=F:\Programme\CodeLite
UNIT_TEST_PP_SRC_DIR:=F:\Programme\Cunit
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/Math3D.c$(ObjectSuffix) $(IntermediateDirectory)/Vektor4.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/gitprogramme/CTest/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/Math3D.c$(ObjectSuffix): Math3D.c $(IntermediateDirectory)/Math3D.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/gitprogramme/CTest/Math3D.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Math3D.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Math3D.c$(DependSuffix): Math3D.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Math3D.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Math3D.c$(DependSuffix) -MM "Math3D.c"

$(IntermediateDirectory)/Math3D.c$(PreprocessSuffix): Math3D.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Math3D.c$(PreprocessSuffix) "Math3D.c"

$(IntermediateDirectory)/Vektor4.c$(ObjectSuffix): Vektor4.c $(IntermediateDirectory)/Vektor4.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/gitprogramme/CTest/Vektor4.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Vektor4.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Vektor4.c$(DependSuffix): Vektor4.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Vektor4.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Vektor4.c$(DependSuffix) -MM "Vektor4.c"

$(IntermediateDirectory)/Vektor4.c$(PreprocessSuffix): Vektor4.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Vektor4.c$(PreprocessSuffix) "Vektor4.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-debug/CTest"


