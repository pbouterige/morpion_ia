cmake_minimum_required(VERSION 3.10)
project(morpion_ia VERSION 1.0.0 LANGUAGES CXX)

# Définir la version du standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options de compilation
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Trouver tous les fichiers source
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Créer l'exécutable
add_executable(morpion_ia ${SOURCES})

# Inclure les répertoires d'en-têtes pour la cible
target_include_directories(morpion_ia PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Définir les propriétés de l'exécutable
set_target_properties(morpion_ia PROPERTIES
    OUTPUT_NAME "morpion_ia"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Installation
install(TARGETS morpion_ia
    RUNTIME DESTINATION bin
)

# Message de configuration
message(STATUS "Configuration du projet morpion_ia")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "Compilateur C++: ${CMAKE_CXX_COMPILER}")
message(STATUS "Standard C++: ${CMAKE_CXX_STANDARD}")