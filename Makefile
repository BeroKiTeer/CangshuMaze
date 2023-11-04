CXX = g++
LD = g++
CXXFLAGS = -Iinclude/ -DFREEGLUT_STATIC -Wall -Wextra \
	-O2 -std=c++17
LDFLAGS = -static -static-libgcc \
	-lfreeglut_static -lopengl32 -lwinmm -lgdi32 -lglu32

EXEC = CangshuMaze.exe
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=build/%.o)

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

clean:
	@echo CLEAN build $(EXEC)
	@-del /F /Q $(EXEC) 2> nul
	@-rmdir /S /Q build 2> nul
	@echo FINISH


# CXX = g++: 定义一个名为CXX的变量，它存储了C++编译器的名称，通常是g++。

# LD = g++: 定义一个名为LD的变量，它存储了链接器的名称，也是g++，因为通常使用相同的编译器来链接应用程序。

# CXXFLAGS = ...: 定义一个名为CXXFLAGS的变量，它包含了编译器的参数和标志，用于编译源文件。这些参数包括：

# -Iinclude/：告诉编译器在include/目录中查找头文件。
# -DFREEGLUT_STATIC：定义了一个预处理宏，用于条件编译。
# -Wall -Wextra：开启警告，以便检测代码中的潜在问题。
# -O2：开启优化级别2，以提高代码执行效率。
# -std=c++17：指定C++标准为C++17。
# LDFLAGS = ...: 定义一个名为LDFLAGS的变量，它包含了链接器的参数和标志，用于链接目标文件。这些参数包括：

# -static -static-libgcc：告诉链接器生成一个静态可执行文件，并静态链接libgcc。
# -lfreeglut_static -lopengl32 -lwinmm -lgdi32 -lglu32：指定链接的库文件，包括OpenGL和其他库。
# EXEC = EqnoCraft.exe: 定义一个名为EXEC的变量，它存储了生成的可执行文件的名称，这里是EqnoCraft.exe。

# SRC = $(wildcard src/*.cpp): 使用wildcard函数，查找src/目录下的所有.cpp文件，并将它们的文件名存储在SRC变量中。

# OBJ = $(SRC:src/%.cpp=build/%.o): 使用模式替换，将SRC中的每个.cpp文件的路径替换为build/目录下的.o目标文件路径，并将这些目标文件的名称存储在OBJ变量中。

# .PHONY: all clean: 声明all和clean为伪目标（不是文件），以确保它们不会与同名文件冲突。

# all: build $(EXEC): 这是一个默认目标，表示构建整个项目。它依赖于build目录和$(EXEC)可执行文件。

# build:: 这是一个伪目标，用于创建build目录。如果该目录不存在，它会被创建。

# $(EXEC): $(OBJ): 这个规则定义了如何生成可执行文件$(EXEC)，它依赖于目标文件$(OBJ)。当所有依赖都准备好时，链接器将执行链接操作。

# build/%.o: src/%.cpp: 这个规则定义了如何生成目标文件，它将.cpp源文件编译成.o目标文件。这是一个模式规则，使用$(CXX)编译器和$(CXXFLAGS)标志来执行编译操作。

# clean:: 这是一个伪目标，用于清理生成的文件。它包括删除可执行文件和build目录。

# @echo ...: 这些行用于在终端输出消息，以显示正在执行的操作，如编译和链接。

# @-del ...: 这些行用于删除可执行文件。@表示不在终端输出执行的命令，-表示即使删除失败也不显示错误消息。

# @-rmdir ...: 这些行用于删除build目录。同样，@和-表示不显示错误消息。

# @echo FINISH: 最后，输出一条消息表示清理完成。