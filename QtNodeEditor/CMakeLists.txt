
project(GrootDeps CXX)

# Find the QtWidgets library
find_package(Qt5 COMPONENTS
             Core
             Xml
             Svg)


add_library(GrootDeps STATIC)

target_link_libraries(GrootDeps
  PUBLIC
    Qt5::Core
    Qt5::Xml
    Qt5::Svg
)
