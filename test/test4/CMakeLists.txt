file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(test4 ${SRCS})

TARGET_LINK_LIBRARIES(test4
    libgtest
    libgmock
)

add_test(NAME test4
         COMMAND test4)
