SOURCES += \
    main.cpp \
    Game.cpp \
    ResourceHolder.inl \
    Entity.cpp \
    Player.cpp \
    EntityList.cpp

HEADERS += \
    Game.h \
    ResourceHolder.hpp \
    Entity.h \
    Player.h \
    EntityList.h

LIBS += \
  -lsfml-system \
  -lsfml-window \
  -lsfml-graphics

CONFIG += \
  c++11
