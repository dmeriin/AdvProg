#ifndef __TEXCEPTION_H__
#define __TEXCEPTION_H__

#include <string>
using namespace std;

//-------------------------------------------------------------------


typedef enum
{
	BAD_ALLOC,
	INDEX_OUT_OF_BOUNDES,
	NO_FUNCTION_IN_DERIVED_CLASS
}Errors;

template <class err_T> class TException_t
{
	public:
		TException_t(const err_T& _obj, const string& _file, int line):
					m_obj(_obj), m_file(_file), m_line(line) {}
		
		TException_t(const err_T& _obj, const string& _file, int line, 
				const string& _description):m_obj(_obj), m_file(_file), 
					m_line(line), m_description(_description) {}
		
		
		TException_t(const TException_t& _excep) : m_obj(_excep.m_obj), 
					m_file(_excep.m_file), m_line(_excep.m_line), 
					m_description(_excep.m_description) {}
					
		virtual ~TException_t() {}
		
		const TException_t& operator = (const TException_t& _excep){
			if (this != &_excep) { 
				m_obj = _excep.m_obj;  
				m_file = _excep.m_file;
				m_line = _excep.m_line;
				m_description = _excep.m_description;
			}
			return *this;
		}
		

		err_T&			GetThrownObject(void)	const { return m_obj;}	
		const string&	GetDesCription()		const { return m_description; }
		const string&	FileName()				const { return m_file; }
		int				LineNum()				const { return m_line; }
	
	private:
		err_T m_obj;
		string m_file;
		int m_line;	
		string m_description;
};


#endif //__TEXCEPTION_H__





