SOURCES += \
    main.cpp \
    Game.cpp \
    ResourceHolder.inl \
    Entity.cpp \
    Player.cpp \
    Mapping.cxx

HEADERS += \
    Game.h \
    ResourceHolder.hpp \
    Entity.h \
    Player.h \
    Mapping.hxx

LIBS += \
  -lsfml-system \
  -lsfml-window \
  -lsfml-graphics

CONFIG += \
  c++11
