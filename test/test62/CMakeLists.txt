file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(test62 ${SRCS})

TARGET_LINK_LIBRARIES(test62
    libgtest
    libgmock
)

add_test(NAME test62
         COMMAND test62)
