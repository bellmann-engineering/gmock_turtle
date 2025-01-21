# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -Igoogletest/include

# Directories
SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build
INCLUDE_DIR = include

# Source files
SRC = $(wildcard $(SRC_DIR)/*.cpp)
TEST_SRC = $(wildcard $(TEST_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))
TEST_OBJ = $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(TEST_SRC))

# Libraries
LIBS = -Lgoogletest/lib -lgtest -lgmock -lpthread

# Targets
TEST_EXEC = $(BUILD_DIR)/turtle_test

# Default target
all: $(TEST_EXEC)

# Build the test executable
$(TEST_EXEC): $(OBJ) $(TEST_OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(wildcard $(INCLUDE_DIR)/*.h)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp $(wildcard $(INCLUDE_DIR)/*.h)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run tests
test: $(TEST_EXEC)
	$(TEST_EXEC)

# Clean build directory
clean:
	rm -rf $(BUILD_DIR)
