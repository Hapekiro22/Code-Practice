CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# 目标文件
TARGET = BiTree.exe

# 源文件
SRCS = main.cpp

# 头文件依赖
DEPS = def.h BinaryTree.h BiTree-IO.h BiTree-Multi.h BiTree-Addons.h BiTree-Traverse.h

# 默认目标 - 直接编译生成可执行文件
all: $(TARGET)

# 一步到位编译链接
$(TARGET): $(SRCS) $(DEPS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

# 清理生成的文件
clean:
	del $(TARGET)

# 运行程序
run: $(TARGET)
	$(TARGET)

.PHONY: all clean run