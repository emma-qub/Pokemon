#ifndef ENTITYLIST_H
#define ENTITYLIST_H

#include <array>

template<typename Entity, size_t NumberMax, size_t Size>
class EntityList: public std::array<Entity, Size> {
public:
  EntityList(void);

  void removeEntityAt(unsigned int pos);
};


#endif // ENTITYLIST_H
