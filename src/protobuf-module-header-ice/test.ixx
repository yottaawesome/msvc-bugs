module;

#include "proto.hpp"

export module test;

export namespace A
{
	// breaks on this
	//using google::protobuf::AllocatedRepeatedPtrFieldBackInserter;
}