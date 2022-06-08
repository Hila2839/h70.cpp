#include "message.hpp"
#include "multi.hpp"

#include "TextTransformer.hpp"
#include "TextOutput.hpp"
#include "TextInput.hpp"

#include "LowerCase.hpp"
#include "Censor.hpp"
#include "UpperCase.hpp"
#include "Rot13.hpp"

#include "ToFile.hpp"
#include "ToUser.hpp"

#include "FromFile.hpp"
#include "FromUser.hpp"




Multi::Multi(std::string a_transformations)
: m_transformations(a_transformations)
{
}



TextTransformer* get_transform_multi(std::string const& a_trans)
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
	return 0;
}


std::string Multi::incoding(std::string a_string)
{
    m_string = a_string;
    int i = 0;
    int size = m_transformations.size();
    std::string word;

    while(i != size)
    {
        if( m_transformations[i] != '+')
        {
            word += m_transformations.at(i);
        }
        else
        {
            m_string = get_transform_multi(word)->incoding(m_string);
            word.clear(); 
        }
        ++i;
    }
    m_string = get_transform_multi(word)->incoding(m_string);

    return m_string;
}



