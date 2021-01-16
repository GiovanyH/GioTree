#include "core.h"

int main()
{
	Core::init();
	Core::Ready();

	while(Core::running)
	{
		Core::Update();
	}

	Core::stop();
}
