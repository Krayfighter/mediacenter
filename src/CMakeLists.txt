
add_executable(
    mediacenter
    ../resources/mainwindow.ui
    # mainwindow.cpp
    main.cpp
    # resources.qrc
)


target_link_libraries(
    mediacenter
    Qt5::Widgets
    Qt5::WebKitWidgets
)