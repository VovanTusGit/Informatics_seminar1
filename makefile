CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

program:
	$(CXX) $(CXXFLAGS) src/main.cpp src/DynamicArray.cpp -o program