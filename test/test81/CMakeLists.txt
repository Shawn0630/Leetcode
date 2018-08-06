file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(test81 ${SRCS})

TARGET_LINK_LIBRARIES(test81
    libgtest
    libgmock
)

add_test(NAME test81
         COMMAND test81)
