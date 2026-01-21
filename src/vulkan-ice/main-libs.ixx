module;

#include <vulkan/vulkan.hpp>

export module main:libs;
import std; // ICE goes away if this line is removed

export namespace vk
{
	using ::vk::PhysicalDevice;
}
