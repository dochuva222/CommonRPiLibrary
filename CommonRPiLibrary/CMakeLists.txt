# CMakeList.txt: проект CMake для CommonRPiLibrary; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_library (CommonRPiLibrary "CommonRPiLibrary.cpp" "CommonRPiLibrary.h" "SPI.h" "SPI.cpp" "USB.h" "USB.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
