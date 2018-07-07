file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(test31 ${SRCS})

TARGET_LINK_LIBRARIES(test31
    libgtest
    libgmock
)

add_test(NAME test31
         COMMAND test31)
