export module module_a;

export int x = 1; 

// Nothing past the private module fragment should affect
// other translation units.
module :private;

// Comment and uncomment this line and observe how the build 
// output states the following, suggesting module_b and main
// are getting recompiled even though only the private 
// fragment has changed:
//		1>Target ClCompile:
//		1>  Compiling...
//		1>  module_a.ixx
//		1>  module_b.ixx
//		1>  main.cpp
int y = 2;
