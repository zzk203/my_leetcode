CXX      = g++
CXXFLAGS = -std=c++17 -g -I include
LDFLAGS  = -lgtest -lgtest_main -pthread
TARGET   = solution_test
SRCS     = $(wildcard src/*.cpp) $(wildcard tests/*.cpp)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(TARGET)
