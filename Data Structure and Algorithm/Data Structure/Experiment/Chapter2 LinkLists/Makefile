CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# 目标文件
TARGET = link_lists.exe

# 源文件
SRCS = main.cpp

# 头文件依赖
DEPS = def.h Link-Lists.h Link-Lists-IO.h Link-Lists-Multi.h Link-Lists-Addons.h

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