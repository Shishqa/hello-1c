set(TARGET_NAME hello-1c)

add_executable(${TARGET_NAME}
    main.cpp
    matrix.hpp
    matrix.cpp
    lu_decompose.cpp
    lu_decompose.hpp
  )
