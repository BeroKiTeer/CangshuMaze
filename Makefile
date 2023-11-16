CXX = g++
LD = g++
CXXFLAGS = -Iinclude/ -DFREEGLUT_STATIC -O2 -Wall -Wextra \
	-O2 -std=c++17
LDFLAGS = -static -static-libgcc \
	-lfreeglut_static -lopengl32 -lwinmm -lgdi32 -lglu32

VSCCXXFLAGS = -I include/ -g -O2 -Wall -Wextra \
    -O2 -std=c++17
VSCLDFLAGS = -static -static-libgcc \
    -lOpenGL32 -lGlU32 -lwinmm -lgdi32 \
	D:\Program_x86_64\mingw64\lib\freeglut.lib

SHELL=cmd.exe
EXEC = CangshuMaze.exe
OBJ = $(SRC:src/%.cpp=build/%.o)

MEXEC = main.exe
MOBJ = $(SRC:src/%.cpp=MainBuild/%.o)

SRC = $(wildcard src/*.cpp)

.PHONY: all clean

all: build $(EXEC)

build:
	@mkdir build

$(EXEC): $(OBJ)
	@echo LD    $@
	@$(LD) $(OBJ) $(LDFLAGS) -o $@

build/%.o: src/%.cpp
	@echo CXX   $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@


MainBuild/: 
	@mkdir MainBuild

$(MEXEC): $(MOBJ)
	@echo LD    $@
	@$(LD) $(MOBJ) $(VSCLDFLAGS) -o $@

MainBuild/%.o: src/%.cpp
	@echo CXX   $<
	@$(CXX) $(VSCCXXFLAGS) -c $< -o $@

vsc: MainBuild/ $(MEXEC)
	@echo File has complicated

clean:
	@echo CLEAN build $(EXEC)
	@-del /F /Q $(EXEC) 2> nul
	@-del /F /Q $(MEXEC) 2> nul
	@-rmdir /S /Q build 2> nul
	@-rmdir /S /Q MainBuild 2> nul
	@echo FINISH