#include <vector>


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
#include "factory.hpp"





Multi::Multi(std::string a_transformations, char a_delimeter)
: m_transformations(a_transformations)
, m_delimeter(a_delimeter)
{
}


//get argv from user and splice it to list
std::list<std::string> Multi::parcer()
{
    std::list<std::string> transformers;
    int i = 0;
    int size = m_transformations.size();
    std::string word;

    while(i != size)
    {
        if( m_transformations[i] != m_delimeter)
        {
            word += m_transformations.at(i);
        }
        else
        {
            transformers.push_back(word);
            word.clear(); 
        }
        ++i;
    }
    transformers.push_back(word);
    return transformers;
}

/*
//gets a list of names and turn it to vector of TextTransformer* using create of factory
std::vector<TextTransformer*> Multi::vector_create(std::list<std::string> a_names)
{
    std::vector<TextTransformer*> transformers;
    Factory factory;

    std::list<std::string>::iterator begin=  a_names.begin();
    std::list<std::string>::iterator end=  a_names.end();

    while(begin != end)
    {
        transformers.push_back(factory.create(*begin));
        begin++;
    }
    return transformers;
}
*/

std::string Multi::trans_sequence(std::vector<TextTransformer*> a_names)
{
    size_t size = a_names.size();

    for(size_t i = 0 ;i < size; ++i)
    {
        m_string = a_names[i]->incoding(m_string);
    }
  
    return m_string;
}


std::string Multi::incoding(std::string a_string)
{
    m_string = a_string;
    std::list<std::string> transformers_words = parcer();
    std::vector<TextTransformer*> transformers_funcs = vector_create(transformers_words);
    m_string = trans_sequence(transformers_funcs);
    return m_string;

}


/*
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


*/
