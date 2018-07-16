file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(test215 ${SRCS})

TARGET_LINK_LIBRARIES(test215
    libgtest
    libgmock
)

add_test(NAME test215
         COMMAND test215)
