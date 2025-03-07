cmake_minimum_required(VERSION 3.1)

# C++ Standard version. Minimum supported is C++11.
set(CMAKE_CXX_STANDARD 11)

if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.12.0")
    # Explicitly set policy for _DIR behaviour
    cmake_policy(SET CMP0074 NEW)
endif()

project(oxts-sdk-examples-gal VERSION 0.1.0)

if(NOT OXTS_SDK_DISABLE_BOOST)
    find_package(Boost COMPONENTS system thread regex)
    if(NOT Boost_FOUND)
        message(STATUS "Boost Library not found. Defaulting to build without Boost. UDP Socket functionality will not be built.")
        set(OXTS_SDK_DISABLE_BOOST ON)
    endif()
    include_directories(${Boost_INCLUDE_DIR})

    # Example 1 - My First GAD
    set(OXTS_SDK_EXAMPLES_GAL_STATIC my-first-gad-example)
    add_executable(${OXTS_SDK_EXAMPLES_GAL_STATIC} ./my-first-gad.cpp)
    target_link_libraries(${OXTS_SDK_EXAMPLES_GAL_STATIC} 
        PUBLIC 
            oxts-sdk-gal-cpp
    )
    # Example 2 - Static Aiding
    set(OXTS_SDK_EXAMPLES_GAL_STATIC static-aiding-example)
    add_executable(${OXTS_SDK_EXAMPLES_GAL_STATIC} ./static-aiding.cpp)
    target_link_libraries(${OXTS_SDK_EXAMPLES_GAL_STATIC} 
        PUBLIC 
            oxts-sdk-gal-cpp
    )
    # Example 3 - Zero velocity wheelspeed
    set(OXTS_SDK_EXAMPLES_GAL_STATIC zv-wheelspeed-example)
    add_executable(${OXTS_SDK_EXAMPLES_GAL_STATIC} ./zero-velocity-wheelspeed.cpp)
    target_link_libraries(${OXTS_SDK_EXAMPLES_GAL_STATIC} 
        PUBLIC 
            oxts-sdk-gal-cpp
    )
    # Example 4 - Heading
    set(OXTS_SDK_EXAMPLES_GAL_STATIC heading-example)
    add_executable(${OXTS_SDK_EXAMPLES_GAL_STATIC} ./heading.cpp)
    target_link_libraries(${OXTS_SDK_EXAMPLES_GAL_STATIC} 
        PUBLIC 
            oxts-sdk-gal-cpp
    )
endif()
    
# Example 4 - Static Aiding No Boost
set(OXTS_SDK_EXAMPLES_GAL_STATIC_NO_BOOST static-aiding-no-boost-example)
add_executable(${OXTS_SDK_EXAMPLES_GAL_STATIC_NO_BOOST} ./static-aiding-no-boost.cpp)
target_link_libraries(${OXTS_SDK_EXAMPLES_GAL_STATIC_NO_BOOST} 
    PUBLIC 
        oxts-sdk-gal-cpp
)
