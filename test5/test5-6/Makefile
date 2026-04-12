# 编译器
CXX = g++

# 编译选项
CXXFLAGS = -std=c++11 -Wall -g

# 目标文件
TARGET = test

# 源文件
SRCS = $(wildcard *.cpp)

# 目标文件（.o）
OBJS = $(SRCS:.cpp=.o)

# 默认目标
all: $(TARGET)

# 链接生成可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# 编译 .cpp -> .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理
clean:
	rm -f $(OBJS) $(TARGET)
