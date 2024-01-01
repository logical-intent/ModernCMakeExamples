// MyExecutable.cpp : Defines the entry point for the application.
//

#include "MyExecutable.h"
#include "HelloLib/Hello.h"
#include "StringTransformerLib/StringTransformer.h"

using namespace std;

int main()
{
	// Hello() from HelloLib uses TransformString() from StringTransformerLib. 
	// Our CMakeLists.txt for MyExecutable does *NOT* need to contain a 
	//   target_link_libraries(MyExecutable PRIVATE StringTransformerLib)
	// for this to work.  
	// StringTransformerLib is linked into our final executable since 
	// our own CMakeLists.txt for MyExecutable contains a 
	//   target_link_libraries(MyExecutable PRIVATE HelloLib)
	// and the CMakeLists.txt for HelloLib contains a 
	//   target_link_libraries(HelloLib PRIVATE StringTransformerLib)
	Hello("direct dependency on HelloLib; indirect dependency on StringTransformerLib");

	// Now we want to use TransformString() directly here.  
	// Our CMakeLists.txt for MyExecutable now *DOES* need to contain a 
	//   target_link_libraries(MyExecutable PRIVATE StringTransformerLib)
	// for that to work.  
	// Adding that statement allows the above 
	//   #include "StringTransformerLib/StringTransformer.h"
	// to work, because it not only says to link the StringTransformerLib target, 
	// but also to add its include directories (declared with target_include_directories()
	// in its CMakeLists.txt file) to our preprocessor include paths.  
	cout << TransformString("direct dependency on StringTransformerLib") << endl;
	return 0;
}
