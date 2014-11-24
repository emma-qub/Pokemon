SOURCES += \
    main.cpp \
    Game.cpp \
    ResourceHolder.inl \
    Entity.cpp \
    Player.cpp

HEADERS += \
    Game.h \
    ResourceHolder.hpp \
    Entity.h \
    Player.h

LIBS += \
  -lsfml-system \
  -lsfml-window \
  -lsfml-graphics

CONFIG += \
  c++11
