file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testGeneral ${SRCS})

TARGET_LINK_LIBRARIES(testGeneral
    libgtest
    libgmock
)

add_test(NAME testGeneral
         COMMAND testGeneral)
