set(HEADERS
        ${HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/Compare.h
        ${CMAKE_CURRENT_SOURCE_DIR}/database.h
        ${CMAKE_CURRENT_SOURCE_DIR}/RegisterManager.h
        ${CMAKE_CURRENT_SOURCE_DIR}/table.h
        PARENT_SCOPE
        )

set(SOURCE
        ${SOURCE}
        ${CMAKE_CURRENT_SOURCE_DIR}/Compare.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/database.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/table.cpp
        PARENT_SCOPE
        )