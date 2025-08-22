add_executable(client
    main_client.cpp)

add_executable(server
    main_server.cpp)

target_link_libraries(client PRIVATE clientLibrary)
target_link_libraries(server PRIVATE serverLibrary)
