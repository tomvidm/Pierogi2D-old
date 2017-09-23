#include <string>
#include <vector>
#include <map>

namespace engine
{
	template <class ResourceType>
	class ResourceHandler
	{
	public:
		virtual void loadFromFile(std::string filename, std::string id);
		virtual ResourceType& get(std::string id);
	protected:
		std::map<std::string, ResourceType> resourceMap;
	};

	template <class ResourceType>
	ResourceType& get(std::string id)
	{
		return resourceMap.at(id);
	}
}