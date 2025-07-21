BUILD_DIR = build
SRC_DIR = src
TEST_DIR = tests
CXX = clang++
CXXFLAGS = -Wall -O2 -MMD -MP

TARGET = $(BUILD_DIR)/main
TEST_TARGET = $(BUILD_DIR)/test

SRC = $(wildcard $(SRC_DIR)/*.cpp)
SRC_OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC))

TEST_SRC = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ = $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.test.o,$(TEST_SRC))

# src/main.cpp 特例化，单独提取出来
MAIN_OBJ = $(BUILD_DIR)/main.o
MODULE_OBJ = $(filter-out $(MAIN_OBJ), $(SRC_OBJ))

DEP = $(SRC_OBJ:.o=.d) $(TEST_OBJ:.o=.d)

$(TARGET): $(SRC_OBJ)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(SRC_OBJ) -o $(TARGET)

$(TEST_TARGET): $(MODULE_OBJ) $(TEST_OBJ)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(MODULE_OBJ) $(TEST_OBJ) -o $(TEST_TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.test.o: $(TEST_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEP)

.PHONY: clean run test

clean:
	rm -rf $(BUILD_DIR)

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)
