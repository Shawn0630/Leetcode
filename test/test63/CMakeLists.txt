file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(test63 ${SRCS})

TARGET_LINK_LIBRARIES(test63
    libgtest
    libgmock
)

add_test(NAME test63
         COMMAND test63)
