file (MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/intermediates/SFML")
file (MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/intermediates/bullet3")

execute_process(COMMAND "${CMAKE_COMMAND}"
        -G ${CMAKE_GENERATOR}
        -DBUILD_CLSOCKET=OFF
        -DBUILD_ENET=OFF
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_BULLET2_DEMOS=OFF -DBUILD_CPU_DEMOS=OFF -DBUILD_EXTRAS=OFF -DBUILD_UNIT_TESTS=OFF -DBUILD_SHARED_LIBS=OFF -DINSTALL_LIBS=ON
        -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_SOURCE_DIR}/lib/bullet3 ${CMAKE_SOURCE_DIR}/vendor/bullet3
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/intermediates/bullet3"
        )
execute_process(COMMAND "${CMAKE_COMMAND}"
        --build ${CMAKE_SOURCE_DIR}/intermediates/bullet3
        --config ${CMAKE_BUILD_TYPE} --target install)

execute_process(COMMAND "${CMAKE_COMMAND}"
        -G ${CMAKE_GENERATOR}
        -DBUILD_SHARED_LIBS=FALSE
        -DSFML_USE_STATIC_STD_LIBS=TRUE
        -DSFML_BUILD_AUDIO=FALSE
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_SOURCE_DIR}/lib/SFML ${CMAKE_SOURCE_DIR}/vendor/SFML
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/intermediates/SFML"
        )
execute_process(COMMAND "${CMAKE_COMMAND}"
        --build ${CMAKE_SOURCE_DIR}/intermediates/SFML
        --config ${CMAKE_BUILD_TYPE} --target install)
