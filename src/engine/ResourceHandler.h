#pragma once

#include <string>
#include <vector>
#include <map>

namespace engine
{
	// This template class represent a simple storage mechanism for
	// objects we wish to retrieve by a key. The TextureHandler and
	// AnimationHandler are example specializations of this class.

	template <class ResourceType>
	class ResourceHandler
	{
	public:
		virtual void loadFromFile(std::string filename, std::string id) = 0;
		ResourceType& get(std::string id);
	protected:
		std::map<std::string, ResourceType> resourceMap;
	};

	template <class ResourceType>
	ResourceType& ResourceHandler<ResourceType>::get(std::string id)
	{
		return resourceMap.at(id);
	}
}