#include <iostream>
#include <Windows.h>
#include <vector>
#include <CL\cl.h>
#include <string>
#include <fstream>
#include <streambuf>


template<typename T> 
class BufferObject
{
	private:
		cl_mem m_MemOpenCL;
		T * m_Object;
	public:
		BufferObject()
		{
			m_Object = new T();
		}
		BufferObject(T * obj)
		{
			m_Object = std::move(obj);
		}

		BufferObject(const T& obj)
		{
			m_Object = obj;
		}
		~BufferObject()
		{
			delete m_Object;
			clReleaseMemObject(m_MemOpenCL);
		}
		
		cl_mem GetOpenCLMem() const
		{
			return m_MemOpenCL;
		}
};


int main(int argc, char ** argv) {
	
	

	return 0;
}











