module;

#include <vulkan/vulkan.hpp>

export module main:libs;
import std; // ICE

export namespace vk
{
	using ::vk::PhysicalDevice;
}

