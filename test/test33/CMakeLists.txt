file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(test33 ${SRCS})

TARGET_LINK_LIBRARIES(test33
    libgtest
    libgmock
)

add_test(NAME test33
         COMMAND test33)
