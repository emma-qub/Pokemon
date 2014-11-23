#include "EntityList.h"

template<typename Entity, size_t NumberMax, size_t Size>
EntityList<Entity, NumberMax, Size>::EntityList(void):
  std::array<Entity, Size>() {
}

template<typename Entity, size_t NumberMax, size_t Size>
void EntityList<Entity, NumberMax, Size>::removeEntityAt(unsigned int pos) {

}
