#pragma once

#include <string>
#include <vector>
#include <map>

namespace engine
{
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