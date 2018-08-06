file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(test220 ${SRCS})

TARGET_LINK_LIBRARIES(test220
    libgtest
    libgmock
)

add_test(NAME test220
         COMMAND test220)
