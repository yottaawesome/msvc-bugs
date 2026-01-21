module;

#define VULKAN_HPP_NO_STRUCT_CONSTRUCTORS
#include <vulkan/vulkan_raii.hpp>
#include <vulkan/vulkan.hpp>
#define GLFW_INCLUDE_VULKAN
//#define VK_USE_PLATFORM_WIN32_KHR
#include <GLFW/glfw3.h>
//#define GLFW_EXPOSE_NATIVE_WIN32
//#include <GLFW/glfw3native.h>

export module main:libs;
import std; // ICE

export namespace glfw
{
	using
		::GLFWwindow,
		::glfwInit,
		::glfwWindowHint,
		::glfwWindowShouldClose,
		::glfwPollEvents,
		::glfwDestroyWindow,
		::glfwTerminate,
		::glfwCreateWindow,
		::glfwGetRequiredInstanceExtensions,
		::glfwCreateWindowSurface,
		::glfwGetFramebufferSize,
		::glfwSetWindowUserPointer,
		::glfwSetFramebufferSizeCallback,
		::glfwGetWindowUserPointer,
		::glfwWaitEvents
		;

	constexpr auto
		ClientApi = GLFW_CLIENT_API,
		NoApi = GLFW_NO_API,
		Resizable = GLFW_RESIZABLE
		;
}

export namespace vk
{
	using
		::vk::ApplicationInfo,
		::vk::InstanceCreateInfo,
		::vk::SystemError,
		::vk::DebugUtilsMessageTypeFlagsEXT,
		::vk::DebugUtilsMessengerCallbackDataEXT,
		::vk::DebugUtilsMessageSeverityFlagBitsEXT,
		::vk::DebugUtilsMessageSeverityFlagsEXT,
		::vk::Bool32,
		::vk::DebugUtilsMessengerCreateInfoEXT,
		::vk::PhysicalDevice,
		::vk::PhysicalDeviceFeatures,
		::vk::PhysicalDeviceProperties,
		::vk::PhysicalDeviceLimits,
		::vk::ExtensionProperties,
		::vk::PhysicalDeviceType,
		::vk::ApiVersion14,
		::vk::EXTDebugUtilsExtensionName
		;

	constexpr auto MakeVersion(int x, int y, int z)
		noexcept -> unsigned
	{
		return VK_MAKE_VERSION(x, y, z);
	}

	export namespace raii
	{
		using
			::vk::raii::Instance,
			::vk::raii::Context,
			::vk::raii::DebugUtilsMessengerEXT,
			::vk::raii::PhysicalDevice
			;
	}
}

