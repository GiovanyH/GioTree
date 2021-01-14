#include "log.h"

#define ERROR(erro) GioLog::error(erro, __FILE__, __LINE__) 

int main()
{
	ERROR("teste de erro");
}
