file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(test61 ${SRCS})

TARGET_LINK_LIBRARIES(test61
    libgtest
    libgmock
)

add_test(NAME test61
         COMMAND test61)
