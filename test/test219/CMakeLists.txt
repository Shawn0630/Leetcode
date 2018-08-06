file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(test219 ${SRCS})

TARGET_LINK_LIBRARIES(test219
    libgtest
    libgmock
)

add_test(NAME test219
         COMMAND test219)
