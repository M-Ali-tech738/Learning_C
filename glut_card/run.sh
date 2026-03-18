#!/bin/bash

# Compile the C++ file with OpenGL/FreeGLUT flags
echo "Compiling eid_card.cpp..."
g++ eid_card.cpp -lglut -lGLU -lGL -o eid

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    ./eid
else
    echo "Compilation failed."
fi
