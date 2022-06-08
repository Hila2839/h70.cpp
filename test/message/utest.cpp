#include "TextTransformer.hpp"
#include "TextOutput.hpp"
#include "TextInput.hpp"

#include "LowerCase.hpp"
#include "Censor.hpp"
#include "UpperCase.hpp"
#include "Rot13.hpp"
#include "multi.hpp"

#include "ToFile.hpp"
#include "ToUser.hpp"

#include "FromFile.hpp"
#include "FromUser.hpp"

#include "message.hpp"




TextInput* get_input(std::string const& a_from)
{
	if(a_from == "stdin")
	{
		return new FromUser;
	}
	else if(isalpha(a_from[1]))
	{
		const char* from = a_from.c_str();
		return new FromFile(from);
	}
	else
	{
		return 0;
		//std::cout<<"error 1\n";
		//return new FromSocket;
	}
}


TextTransformer* get_transform(std::string const& a_trans)
{
	
	if(a_trans == "up")
	{
		return new UpperCase;
	}
	else if(a_trans == "low")
	{
		return new LowerCase;
	}
	else if(a_trans == "censor")
	{
		return new Censor;
	}
	else if(a_trans == "rot13")
	{
		return new Rot13;
	}
	if(a_trans.size() >= 6)
	{
		std::string transformation = a_trans;
		return new Multi(transformation);
	}
	return 0;
}

TextOutput* get_output(std::string a_to)
{
	if(a_to == "stdout")
	{
		return new ToUser;
	}
	else if(isalpha(a_to[1]))
	{
		const char* to = a_to.c_str();
		
		return new ToFile(to);
	}
	/*else
	{
		//return new ToSocket;
	}*/
	return 0;
}


int main(int argc, char* argv[])
{
	std::string a1(argv[1]);
	TextInput* i = get_input(a1);
	TextTransformer* t = get_transform(argv[2]);
	TextOutput* o = get_output(argv[3]);

	Message m(*i, *t, *o);

	m.input();
	m.manipulate();
	m.output();

    return 0;
}
