#include "ResourceHolder.hpp"
//Uncomment to disable assert
//#define NDEBUG
#include <cassert>

template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier p_id, const std::string& p_fileName) {
  std::unique_ptr<Resource> resource(new Resource);
  if (!resource->loadFromFile(p_fileName))
    throw std::runtime_error("ResourceHolder::load - Failed to load " + p_fileName);

  insertResource();
}

template<typename Resource, typename Identifier>
template<typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier p_id, const std::string& p_fileName, const Parameter& p_secondParameter) {
  std::unique_ptr<Resource> resource(new Resource);
  if (!resource->loadFromFile(p_fileName, p_secondParameter))
    throw std::runtime_error("ResourceHolder::load - Failed to load " + p_fileName);

  insertResource();
}

template<typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier p_id) {
  auto found = m_resourceMap.find(p_id);
  assert(found != m_resourceMap.end());

  return *found->second;
}

template<typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier p_id) const {
  auto found = m_resourceMap.find(p_id);
  assert(found != m_resourceMap.end());

  return *found->second;
}

template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::insertResource(Identifier p_id, std::unique_ptr<Resource> p_resource) {
  auto inserted = m_resourceMap.insert(std::make_pair(p_id, std::move(p_resource)));
  assert(inserted.second);
}
