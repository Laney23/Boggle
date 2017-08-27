CXX = g++
BIN_DIR = bin
TARGET = $(BIN_DIR)/boggle
BUILD_DIR = build
SRC_DIR = src
INC_DIR = include
CXXFLAGS = -Wall -g -std=c++11

# Get all source files
SRCS := $(shell find $(SRC_DIR) -name *.cpp)
# Get all object files by replacing src directory with build directory and replace extension
OBJS := $(subst $(SRC_DIR), $(BUILD_DIR), $(SRCS:%.cpp=%.o))
# Get all depend files by replacing extensions
DEPS := $(OBJS:.o=.d)
# Get all includes by searching include directory
INCS := $(shell find $(INC_DIR) -name *.hpp)
# Append -I to the front of each include
INCS := $(foreach d, $(INCS), -I$d)
# Using VPATH to find files in src/ include/ and build/
VPATH := $(SRC_DIR):$(INC_DIR):$(BUILD_DIR)


all: dirs $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJS) -o $(TARGET)

dirs: 
	mkdir -p $(BUILD_DIR)

# Build object files and put in build directory
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Place dependency files in build directory
# automatically generate dependency rules
$(BUILD_DIR)/%.d: %.cpp
	$(CXX) $(CXXFLAGS) -MF"$@" -MG -MM -MP -MT"$@" -MT"$(OBJS)" "$<"
# -MF  write the generated dependency rule to a file
# -MG  assume missing headers will be generated and don't stop with an error
# -MM  generate dependency rule for prerequisite, skipping system headers
# -MP  add phony target for each header to prevent errors when header is missing
# -MT  add a target to the generated dependency

.PHONY: all clean dirs

clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

-include $(DEPS)
