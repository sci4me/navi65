SRC_DIR=src
CC=g++

SOURCES=$(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*/*.cpp)
OBJECTS=$(patsubst %.cpp,%.o,$(filter %.cpp,$(SOURCES)))

EXECUTABLE=navi65
LDFLAGS=
CXXFLAGS=

.PHONY: all clean

all: release

release: clean
release: CXXFLAGS+=-O2
release: $(EXECUTABLE)

debug: clean
debug: LDFLAGS+=-g
debug: CXXFLAGS+=-g
debug: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o "$@" $(OBJECTS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CXXFLAGS) -c -o "$@" "$<"

clean:
	rm -f $(OBJECTS)
	rm -f $(EXECUTABLE)