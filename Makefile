CXX=g++
CXXFLAGS=-Wall -Wextra -MMD -I ./include -g
LDFLAGS=-L/lib/x86_64-linux-gnu -lsfml-graphics -lsfml-window -lsfml-system

# Noms des executables
EXE=pop
TEST_EXE=test

# Fichiers sources du programme principal
SRC=$(wildcard src/*.cpp)
OBJ=$(addprefix build/,$(SRC:src/%.cpp=%.o))
DEP=$(addprefix build/,$(SRC:src/%.cpp=%.d))

# Fichiers sources des tests
TEST_SRC=$(wildcard tests/*.cpp)
TEST_OBJ=$(addprefix build/,$(TEST_SRC:tests/%.cpp=%.o))
TEST_DEP=$(addprefix build/,$(TEST_SRC:tests/%.cpp=%.d))

all: $(EXE) $(TEST_EXE)

# Compilation du programme principal
$(EXE): $(OBJ)
	$(CXX) -o $(EXE) $^ $(LDFLAGS)

# Compilation des tests
$(TEST_EXE): $(TEST_OBJ)
	$(CXX) -o $(TEST_EXE) $^ $(LDFLAGS)


build/%.o: src/%.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

build/%.o: tests/%.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch $(EXE) $(TEST_EXE)

-include $(DEP)
-include $(TEST_DEP)


