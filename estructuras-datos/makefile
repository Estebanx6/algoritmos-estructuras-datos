# Compilador y banderas
CXX = g++
CXXFLAGS = -Wall -Wextra -g -fopenmp -Isource
LDFLAGS = -fopenmp

# Directorios
SRC_DIR = source
BUILD_DIR = build
BIN_DIR = bin

# Archivos
TARGET = $(BIN_DIR)/tp2
SRC = $(SRC_DIR)/main.cpp
OBJ = $(BUILD_DIR)/main.o

# Regla principal
$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compilar .o
$(OBJ): $(SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC) -o $(OBJ)

# Crear build/
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Crear bin/
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Limpiar compilación
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

# Ejecutar
run: $(TARGET)
	./$(TARGET)
