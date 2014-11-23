#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <map>
#include <memory>

#include <SFML/Graphics/Texture.hpp>

namespace Textures {
enum ID {
  Background,
  Player
};
}

template<typename Resource, typename Identifier>
class ResourceHolder {
public:
  void load(Identifier p_id, const std::string& p_fileName);

  template<typename Parameter>
  void load(Identifier p_id, const std::string& p_fileName, const Parameter& p_secondParameter);

  Resource& get(Identifier p_id);
  const Resource& get(Identifier p_id) const;

private:
  void insertResource(Identifier p_id, std::unique_ptr<Resource> p_resource);

private:
  std::map<Identifier, std::unique_ptr<Resource>> m_resourceMap;
};

#include "ResourceHolder.inl"

#endif // RESOURCEHOLDER_H
